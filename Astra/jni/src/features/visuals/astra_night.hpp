// ASTRA_NATIVE_LIGHTING_V1
#pragma once
#include "features/visuals/esp_runtime.hpp"
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <mutex>
namespace astra_night {
namespace ed=astra::esp::detail;
struct Color {float r=1.f,g=1.f,b=1.f,a=1.f;};
static_assert(sizeof(Color)==16,"Color ABI");
using Clock=std::chrono::steady_clock;
struct Settings {bool enabled=false;float strength=.45f;};
inline std::mutex mutex;
inline Settings requested;
inline unsigned revision=0;
inline std::atomic<bool> pending{false},active{false},sunPresent{false};
inline std::atomic<int> status{0};
inline Settings configuration(){std::lock_guard<std::mutex> l(mutex);return requested;}
inline void publish(Settings s){
 s.strength=std::isfinite(s.strength)?std::clamp(s.strength,0.f,1.f):.45f;
 std::lock_guard<std::mutex> l(mutex);requested=s;++revision;pending.store(true);status.store(1);
}
inline bool needsRuntime(){std::lock_guard<std::mutex> l(mutex);return requested.enabled||pending.load()||active.load();}
template<class T> inline T fn(uintptr_t rva){return reinterpret_cast<T>(ed::g_runtime.unityBase+rva);}
using GF=float(*)(const void*);using SF=void(*)(float,const void*);
using GC=Color(*)(const void*);using SC=void(*)(Color,const void*);
using GI=int(*)(const void*);
using GL=float(*)(void*,const void*);using SL=void(*)(void*,float,const void*);
inline uintptr_t native(void* o){
 uintptr_t p=0;
 if(o)ed::readValue(reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(o)+0x10),p);
 return p;
}
inline uintptr_t root(void* o){return o?fn<uintptr_t(*)(void*,const void*)>(0x651292C)(o,nullptr):0;}
inline void* target(uintptr_t h){return h?fn<void*(*)(uintptr_t,const void*)>(0x65017E0)(h,nullptr):nullptr;}
inline void release(uintptr_t& h){if(h)fn<void(*)(uintptr_t,const void*)>(0x64FEBF4)(h,nullptr);h=0;}
inline bool valid(float x){return std::isfinite(x)&&x>=0&&x<=65504.f;}
inline bool finite(Color c){return valid(c.r)&&valid(c.g)&&valid(c.b)&&std::isfinite(c.a);}
struct Saved {bool valid=false;uintptr_t world=0;float ambient=0,reflection=0;int mode=0;Color flat{};};
inline Saved saved;
inline uintptr_t sunHandle=0,sunNative=0;
inline float sunOriginal=0;
inline Clock::time_point lastApply{};
inline uintptr_t checkedBase=0;
inline bool checked=false;
inline bool codeReady(){
 const uintptr_t base=ed::g_runtime.unityBase;
 if(checkedBase==base)return checked;
 checkedBase=base;checked=false;
 struct C{uintptr_t r;uint32_t w;};
 const C checks[]={
 {0x75FE000,0xA9BF4FFE},{0x75F05F4,0xFC1E0FE8},
 {0x7609C24,0xA9BF4FFE},{0x7604704,0xFC1E0FE8},
 {0x760B964,0xA9BF4FFE},{0x760A254,0xD10083FF},{0x75F8A00,0xD10083FF},
 {0x760A064,0xF81E0FFE},{0x75FEC9C,0xF81E0FFE},{0x7613524,0xFC1E0FE8},
 {0x651292C,0xAA1F03E1},{0x6512930,0x52800042},{0x65017E0,0x15175DDD},{0x64FEBF4,0x151768BF}};
 for(auto c:checks){uint32_t w=0;if(!ed::readValue(reinterpret_cast<void*>(base+c.r),w)||w!=c.w)return false;}
 checked=true;return true;
}
inline void releaseSun(bool restore){
 void* obj=target(sunHandle);
 if(restore && obj && sunNative && native(obj)==sunNative)
  fn<SL>(0x7613524)(obj,sunOriginal,nullptr);
 release(sunHandle);sunNative=0;sunPresent.store(false);
}
inline void restore(){
 if(!saved.valid)return;
 fn<SF>(0x75F05F4)(saved.ambient,nullptr);
 fn<SF>(0x7604704)(saved.reflection,nullptr);
 // Never force Flat mode or overwrite unused gradient colors.
 if(saved.mode==3)fn<SC>(0x75F8A00)(saved.flat,nullptr);
 releaseSun(true);saved={};active.store(false);
}
inline void tick(void* player){
 if(!player||!ed::g_runtime.ready||!ed::isUnityMainCallback())return;
 unsigned char local=0;
 if(!ed::readValue(reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(player)+astra::offsets::field::mfc::kLocalOwned),local)||!local)return;
 Settings s;unsigned ver;
 {std::lock_guard<std::mutex> l(mutex);s=requested;ver=revision;}
 if(!s.enabled&&!saved.valid&&!pending.load())return;
 auto world=reinterpret_cast<uintptr_t>(ed::readObject(reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(player)+astra::offsets::field::mfc::kWorld)));
 if(!world){status.store(1);return;}
 if(!codeReady()){status.store(2);return;}
 if(saved.valid&&saved.world!=world){
  // Global RenderSettings now belong to another world; do not restore old globals there.
  // A retained old sun can still exist, so restore that object before releasing it.
  releaseSun(true);saved={};active.store(false);lastApply={};
 }
 auto ack=[&](){std::lock_guard<std::mutex> l(mutex);if(ver==revision)pending.store(false);};
 if(!s.enabled||s.strength<=.0001f){restore();status.store(s.enabled?5:0);ack();return;}
 if(!saved.valid){
  Saved v;v.world=world;v.ambient=fn<GF>(0x75FE000)(nullptr);
  v.reflection=fn<GF>(0x7609C24)(nullptr);v.mode=fn<GI>(0x760B964)(nullptr);
  v.flat=fn<GC>(0x760A254)(nullptr);
  if(!valid(v.ambient)||!valid(v.reflection)||!finite(v.flat)||(v.mode!=0&&v.mode!=1&&v.mode!=3)){status.store(2);return;}
  v.valid=true;saved=v;active.store(true);
 }
 const auto now=Clock::now();
 if(!pending.load()&&now-lastApply<std::chrono::milliseconds(100))return;
 lastApply=now;
 // Exponential exposure: at full strength approximately -4.3 stops.
 const float factor=std::pow(.05f,s.strength);
 const float ambient=saved.ambient*factor,reflection=saved.reflection*factor;
 fn<SF>(0x75F05F4)(ambient,nullptr);fn<SF>(0x7604704)(reflection,nullptr);
 Color flat=saved.flat;
 if(saved.mode==3){flat.r*=factor;flat.g*=factor;flat.b*=factor;fn<SC>(0x75F8A00)(flat,nullptr);}
 void* sun=fn<void*(*)(const void*)>(0x760A064)(nullptr);
 uintptr_t cp=native(sun);
 if(!sun||!cp){releaseSun(true);}
 else {
  if(target(sunHandle)!=sun||sunNative!=cp){
   releaseSun(true);
   if(ed::nameEquals(ed::className(ed::objectClass(sun)),"Light")){
    float intensity=fn<GL>(0x75FEC9C)(sun,nullptr);
    if(valid(intensity)){sunHandle=root(sun);if(sunHandle){sunNative=cp;sunOriginal=intensity;}}
   }
  }
  void* held=target(sunHandle);
  if(held&&native(held)==sunNative){fn<SL>(0x7613524)(held,sunOriginal*factor,nullptr);sunPresent.store(true);}
 }
 auto near=[](float a,float b){return std::isfinite(a)&&std::fabs(a-b)<=.005f+.005f*std::fabs(b);};
 bool accepted=near(fn<GF>(0x75FE000)(nullptr),ambient)&&near(fn<GF>(0x7609C24)(nullptr),reflection);
 if(saved.mode==3){Color got=fn<GC>(0x760A254)(nullptr);accepted=accepted&&near(got.r,flat.r)&&near(got.g,flat.g)&&near(got.b,flat.b);}
 if(void* held=target(sunHandle))if(native(held)==sunNative)accepted=accepted&&near(fn<GL>(0x75FEC9C)(held,nullptr),sunOriginal*factor);
 status.store(accepted?3:4);ack();
}
}
