#pragma once

#include <cstddef>
#include <cstdint>

namespace astra::offsets {

inline constexpr char kProfileName[] = "Standoff2-1.0.0-arm64-il2cppdump-v15-local-input-init";
inline constexpr char kSourceSha256[] = "57c952704158ee14d531280c5fdd2b627677f733bf342ae11bd872430c477b04";
inline constexpr char kDumpCsSha256[] = "0c1c10058f7593ed8fd6fab830f35c2834ab9a35799052af4893c75e5ecdf651";
inline constexpr char kIl2CppHeaderSha256[] = "a2dbacf5969f298e2c241638453cdd7d9fb6fb8b167decb032bb829ff024dcf3";
inline constexpr char kStringLiteralSha256[] = "ecfd3170c8a95e6294c37f1e56c0bdb0a25a86415e0ad9b509d2953a6f0e0ccc";
inline constexpr char kApkSha256[] = "863073036c0fcf6532906d50c087677e5fcc5cf0b2566aa98e10eb5f7a2ef0a2";
inline constexpr char kLibUnitySha256[] = "a5d530e0ee7f4982d4bafec50c6109737b6119525935cac3e423e5145ff33e0f";
inline constexpr char kLibUnityBuildId[] = "69a652effabe2f13";

namespace elf {
inline constexpr std::uintptr_t kTextBegin = 0x535F940;
inline constexpr std::uintptr_t kTextEnd = 0xB882E00;
inline constexpr std::uintptr_t kDataRelRoBegin = 0xB886F80;
inline constexpr std::uintptr_t kDataBegin = 0xBF07F60;
inline constexpr std::uintptr_t kDataEnd = 0xC46CF80;
}

// ARM64 IL2CPP entry points recovered from the matching 1.0.0 libunity.so.
// Prefer dlsym where available; use these only after the ARM64 profile gate passes.
namespace il2cpp_api {
inline constexpr std::uintptr_t kResolveIcall = 0x63279F4;
inline constexpr std::uintptr_t kFree = 0x63279F8;
inline constexpr std::uintptr_t kAssemblyGetImage = 0x6327A18;
inline constexpr std::uintptr_t kClassFromName = 0x6327A3C;
inline constexpr std::uintptr_t kClassGetFields = 0x6327AC8;
inline constexpr std::uintptr_t kClassGetFieldFromName = 0x6327AD0;
inline constexpr std::uintptr_t kClassGetName = 0x6327AD8;
inline constexpr std::uintptr_t kClassGetNamespace = 0x6327ADC;
inline constexpr std::uintptr_t kClassGetParent = 0x6327AE0;
inline constexpr std::uintptr_t kDomainGet = 0x6327B70;
inline constexpr std::uintptr_t kDomainAssemblyOpen = 0x6327B74;
inline constexpr std::uintptr_t kFieldGetOffset = 0x6327C44;
inline constexpr std::uintptr_t kFieldGetType = 0x6327C48;
inline constexpr std::uintptr_t kFieldStaticGetValue = 0x6327C50;
inline constexpr std::uintptr_t kThreadAttach = 0x6327D6C;
inline constexpr std::uintptr_t kThreadDetach = 0x6327D70;
inline constexpr std::uintptr_t kTypeGetName = 0x6327D8C;
}

namespace unity {
inline constexpr std::uintptr_t kNativeInjectEvent = 0x5668AD8;
// 0x53653C4 returns a GC handle, NOT a managed Camera object.
inline constexpr std::uintptr_t kCameraGetMain = 0x53653C4;  // diagnostics only
// Native Camera::GetMain; verified call target of the GC-handle wrapper.
inline constexpr std::uintptr_t kNativeCameraGetMain = 0x54C1338;
inline constexpr std::uintptr_t kCameraGetCurrent = 0x53653E8;
inline constexpr std::uintptr_t kCameraGetFov = 0x5364FE4;
inline constexpr std::uintptr_t kCameraWorldToCameraMatrix = 0x5365204;
inline constexpr std::uintptr_t kCameraProjectionMatrix = 0x5365228;
inline constexpr std::uintptr_t kCameraWorldToScreen = 0x5365268;
inline constexpr std::uintptr_t kCameraScreenToWorld = 0x53652FC;
inline constexpr std::uintptr_t kComponentGetTransform = 0x5371D30;
inline constexpr std::uintptr_t kGameObjectGetTransform = 0x53727CC;
inline constexpr std::uintptr_t kTransformGetPositionAndRotation = 0x53764E0;
inline constexpr std::uintptr_t kAnimatorGetBoneTransform = 0x539569C;
inline constexpr std::uintptr_t kRendererGetBounds = 0x53689D0;
inline constexpr std::uintptr_t kColliderGetBounds = 0x538B650;
inline constexpr std::uintptr_t kGameObjectGetComponentsInternal = 0x5372370;
inline constexpr std::uintptr_t kPhysicsRaycastTest = 0x538BCF4;
inline constexpr std::uintptr_t kPhysicsRaycast = 0x538BD0C;
inline constexpr std::uintptr_t kPhysicsRaycastNonAlloc = 0x538BD24;
inline constexpr std::uintptr_t kPhysicsSphereCast = 0x538BDBC;
inline constexpr std::uintptr_t kPhysicsBoxCast = 0x538BE40;
}

// Metadata usage slots from the matching ARM64 script.json. Zero means that
// script.json exposes no direct TypeInfo slot; resolve that class by name at runtime.
namespace typeinfo {
inline constexpr std::uintptr_t kClientWorld = 0xC2062E0;       // njh_TypeInfo
inline constexpr std::uintptr_t kRegistry = 0xC203D50;          // gat_TypeInfo
inline constexpr std::uintptr_t kStore = 0xC204210;             // gzx_TypeInfo
inline constexpr std::uintptr_t kPlayer = 0xC202058;            // ake_TypeInfo
inline constexpr std::uintptr_t kNetObject = 0xC205CE8;         // mfc_TypeInfo
inline constexpr std::uintptr_t kTransforms = 0xC2031A8;        // dwc_TypeInfo
inline constexpr std::uintptr_t kPlayerBindings = 0;            // no direct slot
inline constexpr std::uintptr_t kModel = 0xC204D68;             // jgi_TypeInfo
inline constexpr std::uintptr_t kCharacterBindings = 0xC1F4440;
inline constexpr std::uintptr_t kBonesDictionary = 0xC1F3E28;
inline constexpr std::uintptr_t kHitBoxCollider = 0;             // no direct slot
inline constexpr std::uintptr_t kStats = 0xC209D38;             // ylw_TypeInfo
inline constexpr std::uintptr_t kUntouchable = 0xC207FA0;       // tbq_TypeInfo
inline constexpr std::uintptr_t kVisibility = 0xC207118;        // qdp_TypeInfo
inline constexpr std::uintptr_t kTransport = 0xC204278;         // hbu_TypeInfo
inline constexpr std::uintptr_t kActor = 0xC207E00;             // stn_TypeInfo
inline constexpr std::uintptr_t kWeaponPart = 0xC2064A8;        // nrk_TypeInfo
inline constexpr std::uintptr_t kWeaponInstance = 0xC207240;    // qjf_TypeInfo
inline constexpr std::uintptr_t kWeaponProvider = 0xC2048A8;    // ijq_TypeInfo
inline constexpr std::uintptr_t kWeaponDefinition = 0;          // no direct slot
inline constexpr std::uintptr_t kGunParameters = 0xC1F8010;
inline constexpr std::uintptr_t kInputManager = 0xC20A2F0;      // znn_TypeInfo
inline constexpr std::uintptr_t kInputCommand = 0xC206A90;      // owv_TypeInfo
inline constexpr std::uintptr_t kCameraComponent = 0xC2049C0;   // ios_TypeInfo
inline constexpr std::uintptr_t kRotation = 0xC203498;          // eir_TypeInfo
inline constexpr std::uintptr_t kCameraController = 0;          // nrl has no direct slot
inline constexpr std::uintptr_t kNavigation = 0xC2062C0;        // nip_TypeInfo
inline constexpr std::uintptr_t kMovement = 0xC208230;          // tof_TypeInfo
inline constexpr std::uintptr_t kGlobalOptions = 0xC1F7B70;
inline constexpr std::uintptr_t kRootLifetimeScope = 0;         // no direct slot
inline constexpr std::uintptr_t kGrenadeCim = 0xC2029B0;
inline constexpr std::uintptr_t kGrenadeQak = 0;                // no direct slot
inline constexpr std::uintptr_t kBomb = 0xC20A2F8;
inline constexpr std::uintptr_t kDrop = 0xC2062D8;
inline constexpr std::uintptr_t kRagdoll = 0xC2059D0;
inline constexpr std::uintptr_t kModeNbs = 0xC206188;
inline constexpr std::uintptr_t kModeXlm = 0xC2097F8;
inline constexpr std::uintptr_t kModeYmn = 0xC209D68;
inline constexpr std::uintptr_t kModeQin = 0xC207208;
inline constexpr std::uintptr_t kModeHog = 0xC2044E8;
}

namespace typevar {
inline constexpr std::uintptr_t kCharacterBindings = 0xC1D6C38;
inline constexpr std::uintptr_t kWeaponContext = 0xC1DAF50;
inline constexpr std::uintptr_t kGlobalOptions = 0xC1D8328;
inline constexpr std::uintptr_t kActor = 0xC1DC598;
}

// Managed ARM64 methods used only as validation anchors or optional read helpers.
namespace managed_rva {
// Current 1.0.0 ARM64 equivalents of the older PlayerController sample.
// ake::opmn() is the per-player update interface callback used for collection;
// ake::xdzx() is the canonical world-position getter.
inline constexpr std::uintptr_t kPlayerUpdateHook = 0x949E8A0;
inline constexpr std::uintptr_t kPlayerGetPosition = 0x9489018;
inline constexpr std::uintptr_t kStatsGetHp = 0x94A7418;
inline constexpr std::uintptr_t kStatsGetMaxHp = 0x949CD84;
inline constexpr std::uintptr_t kStatsGetArmor = 0x948EA58;
inline constexpr std::uintptr_t kStatsGetMaxArmor = 0x94A3CBC;
inline constexpr std::uintptr_t kStatsGetHelmet = 0x9491630;
inline constexpr std::uintptr_t kWeaponPartGetContext = 0x948953C;
inline constexpr std::uintptr_t kWeaponPartGetActiveWeapon = 0x9489544;
inline constexpr std::uintptr_t kWeaponGetId = 0x9735590;
inline constexpr std::uintptr_t kWeaponGetMagazineAmmo = 0x973B9F4;
inline constexpr std::uintptr_t kWeaponGetReserveAmmo = 0x973B400;
inline constexpr std::uintptr_t kNetObjectGetParts = 0x74CC168;
}

// Dump-confirmed physical object offsets. Value-type offsets are already
// converted from boxed dump offsets to their embedded physical positions.
namespace field {
// NetObject world path confirmed from the matching ARM64 dump and native code:
// njh(ClientWorld) -> gat(registry) -> gzx(store) -> yjk<krm> -> krm[] objects.
namespace njh {
inline constexpr std::size_t kRegistry = 0x40;
}
namespace gat {
inline constexpr std::size_t kWorld = 0x20;
inline constexpr std::size_t kStore = 0x30;
inline constexpr std::size_t kTypeConfiguration = 0x48;
}
namespace gzx {
inline constexpr std::size_t kObjects = 0x18;
}
namespace yjk {
inline constexpr std::size_t kItems = 0x10;
inline constexpr std::size_t kCount = 0x18;
}
namespace mfc {
inline constexpr std::size_t kNetObjectId = 0x10;
inline constexpr std::size_t kOwnerId = 0x14;
inline constexpr std::size_t kWorld = 0x18;
inline constexpr std::size_t kComponentsContainer = 0x20;
inline constexpr std::size_t kPartsContainer = 0x28;
inline constexpr std::size_t kLocalOwned = 0x44;
}
namespace part_container {
// rct::vsog is a managed List<eur>, not an array.
inline constexpr std::size_t kPartList = 0x10;
}
namespace managed_list {
inline constexpr std::size_t kItems = 0x10;
inline constexpr std::size_t kSize = 0x18;
}
namespace ake {
inline constexpr std::size_t kStats = 0x70;
inline constexpr std::size_t kVisibility = 0x88;
inline constexpr std::size_t kTeam = 0x90;
}
namespace ylw {
inline constexpr std::size_t kHp = 0x10;
inline constexpr std::size_t kUnknown12 = 0x12;
inline constexpr std::size_t kMaxHp = 0x14;
inline constexpr std::size_t kArmor = 0x16;
inline constexpr std::size_t kUnknown18 = 0x18;
inline constexpr std::size_t kMaxArmor = 0x1A;
inline constexpr std::size_t kHelmet = 0x1C;
inline constexpr std::size_t kFloatValue = 0x20;
}
namespace nrk {
inline constexpr std::size_t kWeaponContext = 0x30;
inline constexpr std::size_t kTeam = 0x38;
inline constexpr std::size_t kHitTransform = 0x40;
inline constexpr std::size_t kNavigationContext = 0x48;
inline constexpr std::size_t kAccuracyContext = 0x68;
inline constexpr std::size_t kRecoilContext = 0x70;
inline constexpr std::size_t kActiveWeapon = 0x78;
inline constexpr std::size_t kWeaponState = 0x80;
inline constexpr std::size_t kAimState = 0x8C;
inline constexpr std::size_t kRecoilState = 0x98;
inline constexpr std::size_t kReloadState = 0xB8;
inline constexpr std::size_t kCurrentTime = 0xBC;
inline constexpr std::size_t kWasHit = 0xC0;
inline constexpr std::size_t kClearWeaponSignal = 0xC8;
}
namespace qjf {
inline constexpr std::size_t kWeaponId = 0x10;
inline constexpr std::size_t kWeaponMetaData = 0x18;
inline constexpr std::size_t kWeaponMetaId = 0x50;
inline constexpr std::size_t kMagazineAmmo = 0x52;
inline constexpr std::size_t kReserveAmmo = 0x54;
inline constexpr std::size_t kFloatValue = 0x58;
inline constexpr std::size_t kDefinitionLike = 0x60;
}
namespace dwc {
inline constexpr std::size_t kTransformA = 0x28;
inline constexpr std::size_t kTransformB = 0x30;
inline constexpr std::size_t kPlayerBindings = 0x38;
}
namespace jgi {
inline constexpr std::size_t kHitBoxColliders = 0x18;
inline constexpr std::size_t kTransform = 0x20;
inline constexpr std::size_t kAnimator = 0x28;
inline constexpr std::size_t kCharacterBindings = 0x30;
}
namespace player_bindings {
inline constexpr std::size_t kCharacterController = 0x20;
inline constexpr std::size_t kCapsuleCollider = 0x28;
inline constexpr std::size_t kCameraPlaceholder = 0x30;
inline constexpr std::size_t kTrigger = 0x38;
}
namespace character_bindings {
inline constexpr std::size_t kBones = 0x20;
inline constexpr std::size_t kTool = 0x28;
inline constexpr std::size_t kAnimator = 0x30;
inline constexpr std::size_t kCharacterRenderer = 0x38;
inline constexpr std::size_t kArmsRenderer = 0x40;
inline constexpr std::size_t kGlovesRenderer = 0x48;
}
namespace hitbox_collider {
inline constexpr std::size_t kHitBox = 0x20;
inline constexpr std::size_t kCollider = 0x28;
}
}

// Compatibility aliases for older source files. These values are no longer candidates.
namespace field_candidate {
inline constexpr std::size_t kStatsHp = field::ylw::kHp;
inline constexpr std::size_t kStatsMaxHp = field::ylw::kMaxHp;
inline constexpr std::size_t kStatsArmor = field::ylw::kArmor;
inline constexpr std::size_t kStatsMaxArmor = field::ylw::kMaxArmor;
inline constexpr std::size_t kWeaponContextInPart = field::nrk::kWeaponContext;
inline constexpr std::size_t kTeamInWeaponPart = field::nrk::kTeam;
inline constexpr std::size_t kActiveWeaponInPart = field::nrk::kActiveWeapon;
inline constexpr std::size_t kWeaponIdInInstance = field::qjf::kWeaponId;
inline constexpr std::size_t kAmmoInInstance = field::qjf::kReserveAmmo;
}

namespace managed {
// UnityEngine.Object::m_CachedPtr (confirmed by dump and Camera managed wrapper).
inline constexpr std::size_t kUnityObjectCachedPtr = 0x10;
// Native Camera cached matrices; confirmed from 0x5A7C2B8/0x5A7C31C.
inline constexpr std::size_t kNativeCameraWorldToCameraMatrix = 0x70;
inline constexpr std::size_t kNativeCameraProjectionMatrix = 0xB0;
inline constexpr std::size_t kObjectFirstField = 0x10;
inline constexpr std::size_t kArrayLength = 0x18;
inline constexpr std::size_t kArrayData = 0x20;
inline constexpr std::size_t kListItems = 0x10;
inline constexpr std::size_t kListSize = 0x18;
inline constexpr float kFallbackPlayerHeight = 1.78f;
}

}  // namespace astra::offsets

// Astra visual additions; original project offsets retained.
namespace astra::offsets {
namespace il2cpp_api {
inline constexpr std::uintptr_t kClassGetMethods = 0x6327AD4;
inline constexpr std::uintptr_t kClassGetMethodFromName = 0x632EC5C;
inline constexpr std::uintptr_t kMethodGetName = 0x6327CEC;
inline constexpr std::uintptr_t kMethodGetParamCount = 0x6327CFC;
inline constexpr std::uintptr_t kMethodGetParam = 0x6327D00;
inline constexpr std::uintptr_t kMethodGetParamName = 0x63454E4;
inline constexpr std::uintptr_t kStringNew = 0x6327D58;
inline constexpr std::uintptr_t kStringChars = 0x6327D54;
inline constexpr std::uintptr_t kObjectNew = 0x6327D14;
}
namespace method_info {
inline constexpr std::size_t kSlot = 0x00;               // uint16 vtable slot
inline constexpr std::size_t kName = 0x10;               // const char*
inline constexpr std::size_t kInvokerMethod = 0x20;
inline constexpr std::size_t kMethodPointer = 0x30;      // Il2CppMethodPointer
inline constexpr std::size_t kVirtualMethodPointer = 0x50;
inline constexpr std::size_t kKlass = 0x68;              // Il2CppClass*
}
namespace class_layout {
inline constexpr std::size_t kStaticFields = 0x40;
inline constexpr std::size_t kParent = 0xE8;
inline constexpr std::size_t kName = 0x198;
inline constexpr std::size_t kNamespace = 0xD8;
inline constexpr std::size_t kVtable = 0x1A0;            // VirtualInvokeData[]
}
namespace visuals_rva {
namespace shader {
inline constexpr std::uintptr_t kFind = 0x75FAF74;          // static Shader Find(string)
inline constexpr std::uintptr_t kFindBuiltin = 0x7603724;   // internal static Shader FindBuiltin(string)
}
namespace material {
// NOTE: only the *string* overloads are used by the natives. The int
// overloads live at 0x75E89C0 (GetColor(int)) / 0x75FE688 (GetFloat(int)) /
// 0x760C250 (SetFloat(int,float)) / 0x75FC688 (SetColor(int,Color)) and must
// NOT be swapped in: the callers pass il2cpp System.String pointers.
inline constexpr std::uintptr_t kGetShader = 0x75F9610;       // Shader get_shader()
inline constexpr std::uintptr_t kSetShader = 0x7602D8C;       // void set_shader(Shader)
// Property forms (no string arguments) - used on cheat-owned materials whose
// shader is known to carry _Color / _MainTex:
inline constexpr std::uintptr_t kCtorShader = 0x75F3798;      // void .ctor(Shader)
inline constexpr std::uintptr_t kGetColorProp = 0x7612180;    // Color get_color()
inline constexpr std::uintptr_t kSetColorProp = 0x76079E4;    // void set_color(Color)
inline constexpr std::uintptr_t kGetMainTexture = 0x760BDB0;  // Texture get_mainTexture()
inline constexpr std::uintptr_t kSetMainTexture = 0x7611648;  // void set_mainTexture(Texture)
inline constexpr std::uintptr_t kSetColor = 0x761134C;        // void SetColor(string, Color)
inline constexpr std::uintptr_t kGetColor = 0x76123E0;        // Color GetColor(string)
inline constexpr std::uintptr_t kHasProperty = 0x7612934;     // bool HasProperty(string)
inline constexpr std::uintptr_t kHasFloat = 0x75FDC64;        // bool HasFloat(string)
inline constexpr std::uintptr_t kSetFloat = 0x75F6C44;        // void SetFloat(string, float)
inline constexpr std::uintptr_t kGetFloat = 0x75E69E0;        // float GetFloat(string)
inline constexpr std::uintptr_t kGetTexture = 0x76000D8;      // Texture GetTexture(string)
inline constexpr std::uintptr_t kSetTexture = 0x75F1238;      // void SetTexture(string, Texture)
inline constexpr std::uintptr_t kGetRenderQueue = 0x76027CC;  // int get_renderQueue()
inline constexpr std::uintptr_t kSetRenderQueue = 0x75FCB04;  // void set_renderQueue(int)
}
namespace renderer {
inline constexpr std::uintptr_t kGetMaterial = 0x75E7C4C;      // private Material GetMaterial()
inline constexpr std::uintptr_t kSetMaterial = 0x75F2DE8;      // void set_material(Material)
inline constexpr std::uintptr_t kGetSharedMaterial = 0x7613034;  // Material get_sharedMaterial()
inline constexpr std::uintptr_t kGetSharedMaterials = 0x7612138; // Material[] get_sharedMaterials()
inline constexpr std::uintptr_t kSetSharedMaterials = 0x75EB8A0; // void set_sharedMaterials(Material[])
}
namespace reflection {
inline constexpr std::uintptr_t kTypeGetType = 0x63A1E0C;          // static Type Type.GetType(string)
inline constexpr std::uintptr_t kFindObjectsOfTypeAll = 0x67E81A0; // static Object[] Object.FindObjectsOfTypeAll(Type)
}
namespace render_settings {
inline constexpr std::uintptr_t kGetFog = 0x7612954;               // static bool get_fog()
inline constexpr std::uintptr_t kSetFog = 0x75F0BD4;               // static void set_fog(bool)
inline constexpr std::uintptr_t kGetFogColor = 0x760EC5C;          // static Color get_fogColor()
inline constexpr std::uintptr_t kSetFogColor = 0x760931C;          // static void set_fogColor(Color)
inline constexpr std::uintptr_t kGetAmbientSky = 0x7609EAC;        // static Color get_ambientSkyColor()
inline constexpr std::uintptr_t kSetAmbientSky = 0x75E4898;        // static void set_ambientSkyColor(Color)
inline constexpr std::uintptr_t kGetAmbientEquator = 0x760C3D8;    // static Color get_ambientEquatorColor()
inline constexpr std::uintptr_t kSetAmbientEquator = 0x761701C;    // static void set_ambientEquatorColor(Color)
inline constexpr std::uintptr_t kGetAmbientGround = 0x7610320;     // static Color get_ambientGroundColor()
inline constexpr std::uintptr_t kSetAmbientGround = 0x760BD30;     // static void set_ambientGroundColor(Color)
inline constexpr std::uintptr_t kGetAmbientLight = 0x760A254;      // static Color get_ambientLight()
inline constexpr std::uintptr_t kSetAmbientLight = 0x75F8A00;      // static void set_ambientLight(Color)
inline constexpr std::uintptr_t kGetAmbientIntensity = 0x75FE000;  // static float get_ambientIntensity()
inline constexpr std::uintptr_t kSetAmbientIntensity = 0x75F05F4;  // static void set_ambientIntensity(float)
inline constexpr std::uintptr_t kGetAmbientMode = 0x760B964;       // static AmbientMode get_ambientMode()
inline constexpr std::uintptr_t kSetAmbientMode = 0x7611FFC;       // static void set_ambientMode(AmbientMode)
inline constexpr std::uintptr_t kGetFogStart = 0x7616F70;          // static float get_fogStartDistance()
inline constexpr std::uintptr_t kSetFogStart = 0x760D93C;          // static void set_fogStartDistance(float)
inline constexpr std::uintptr_t kGetFogEnd = 0x7601480;            // static float get_fogEndDistance()
inline constexpr std::uintptr_t kSetFogEnd = 0x76134EC;            // static void set_fogEndDistance(float)
inline constexpr std::uintptr_t kGetFogMode = 0x76145A0;           // static FogMode get_fogMode()
inline constexpr std::uintptr_t kSetFogMode = 0x75EA52C;           // static void set_fogMode(FogMode)
inline constexpr std::uintptr_t kGetFogDensity = 0x760B268;        // static float get_fogDensity()
inline constexpr std::uintptr_t kSetFogDensity = 0x76096D0;        // static void set_fogDensity(float)
inline constexpr std::uintptr_t kGetSkybox = 0x75FED14;            // static Material get_skybox()
inline constexpr std::uintptr_t kSetSkybox = 0x75F7328;            // static void set_skybox(Material)
inline constexpr std::uintptr_t kSetSunColor = 0;                  // set_sunColor(Color): METADATA-ONLY
                                                                   // (the dump tables available here do
                                                                   // not carry this RVA; resolveMethod
                                                                   // resolves it from live il2cpp metadata)
}
// Skeleton ESP: humanoid bone lookup through the character Animator.
namespace skeleton {
inline constexpr std::uintptr_t kAnimatorGetBoneTransform = 0x8828724;  // Transform Animator.GetBoneTransform(HumanBodyBones)
}
// Camera-driven effects (scope suppression, view model). Transform wrappers live in
// the 0x67E..0x680 block of UnityEngine.Transform.
namespace transform_rva {
inline constexpr std::uintptr_t kGetPosition = 0x67EF458;   // Vector3 Transform.get_position()
inline constexpr std::uintptr_t kSetPosition = 0x67F1268;   // void Transform.set_position(Vector3)
inline constexpr std::uintptr_t kGetForward = 0x67F967C;    // Vector3 Transform.get_forward()
// Local-position wrappers for the hand-pos view model offset.
inline constexpr std::uintptr_t kGetLocalPosition = 0x67FDC50;  // Vector3 Transform.get_localPosition()
inline constexpr std::uintptr_t kSetLocalPosition = 0x67FDCE0;  // void Transform.set_localPosition(Vector3)
}
namespace physics {
// bool Physics.Raycast(Vector3 origin, Vector3 direction, out RaycastHit hitInfo,
//                      float maxDistance, int layerMask)
// ABI (AAPCS64): origin -> s0-s2 (HFA), direction -> s3-s5, &hit -> x0,
// maxDistance -> s6, layerMask -> x1, MethodInfo* -> x2. RaycastHit is the
// managed struct: point @+0x00, normal @+0x0C, distance @+0x20 (56 bytes).
inline constexpr std::uintptr_t kRaycast = 0x905A4CC;
}
namespace canvas_group {
inline constexpr std::uintptr_t kSetAlpha = 0x7A68CD8;      // void CanvasGroup.set_alpha(float)
}
// Camera property wrappers for the remove-scope FOV normalizer.
namespace camera {
inline constexpr std::uintptr_t kGetFieldOfView = 0x6D2640C;  // float Camera.get_fieldOfView()
inline constexpr std::uintptr_t kSetFieldOfView = 0x6D29968;  // void Camera.set_fieldOfView(float)
inline constexpr std::uintptr_t kSetUseOcclusionCulling = 0x6D19818;  // void set_useOcclusionCulling(bool)
inline constexpr std::uintptr_t kGetBackgroundColor = 0x6D10EE0;      // Color get_backgroundColor()
inline constexpr std::uintptr_t kSetBackgroundColor = 0x6D13AF8;      // void set_backgroundColor(Color)
inline constexpr std::uintptr_t kGetAspect = 0x6D1F5B0;               // float get_aspect()
// Aspect-ratio override rides the projection matrix (this build exposes no
// Camera.set_aspect). The _Injected forms pass Matrix4x4 by reference:
// void (*)(Camera*, Matrix4x4*, MethodInfo*).
inline constexpr std::uintptr_t kGetProjectionMatrixInjected = 0x6D1E880;
inline constexpr std::uintptr_t kSetProjectionMatrixInjected = 0x6D0E720;
inline constexpr std::uintptr_t kResetProjectionMatrixInjected = 0x6D16BBC;
}
// Per-light shadows + intensity (No Shadows / Night mode).
// LightShadows: None=0, Hard=1, Soft=2.
namespace light {
inline constexpr std::uintptr_t kGetShadows = 0x760155C;   // LightShadows Light.get_shadows()
inline constexpr std::uintptr_t kSetShadows = 0x760322C;   // void Light.set_shadows(LightShadows)
inline constexpr std::uintptr_t kGetIntensity = 0x75FEC9C; // float Light.get_intensity()
inline constexpr std::uintptr_t kSetIntensity = 0x7613524; // void Light.set_intensity(float)
}
// Animator culling (Occlusion Bypass): AlwaysAnimate keeps the bone
// transforms updating for players outside the camera frustum / behind walls,
// so the skeleton keeps reading live positions instead of a frozen pose.
namespace animator {
inline constexpr std::uintptr_t kGetCullingMode = 0x88342A0;  // AnimatorCullingMode get_cullingMode()
inline constexpr std::uintptr_t kSetCullingMode = 0x882E200;  // void set_cullingMode(AnimatorCullingMode)
}
// GameObject activation (remove scope re-worked to the original cheat's
// SetActive path: the CanvasGroup alpha alone is re-driven by the game).
namespace game_object {
inline constexpr std::uintptr_t kComponentGetGameObject = 0x67D4FBC;  // GameObject Component.get_gameObject()
inline constexpr std::uintptr_t kGetActive = 0x67D5858;               // bool GameObject.get_active()
inline constexpr std::uintptr_t kSetActive = 0x67D8A78;              // void GameObject.set_active(bool)
}
// Local-player camera component execute (netcode component of the player).
// Late in the frame - hooking it gives a Unity-main-thread callback that runs
// AFTER the game positioned the camera, which is where the third-person
// pull-back / scope suppression / arms offset must run to survive the frame.
namespace camera_component {
inline constexpr std::uintptr_t kIqkrExecute = 0xA0903DC;  // void ios.iqkr(ExecuteTime)
}
}
}
