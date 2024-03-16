#pragma once
#include <libhat.hpp>
#include <libhat/Process.hpp>

#define DEFINE(name, str) const hat::signature_view name = ([]() {  \
    static constexpr auto sig = hat::compile_signature<str>();      \
    return hat::signature_view{sig};                                \
})();

namespace Sigs {
    namespace gamedata {
        extern const hat::signature_view isKeyDown;
        extern const hat::signature_view sendKey;
    }
    namespace packet {
        extern const hat::signature_view ModEquipmentPacket;
        extern const hat::signature_view AnimatePacket;
        extern const hat::signature_view MobEffectPacket;
        extern const hat::signature_view InventoryTransactionPacket;
        extern const hat::signature_view MovePlayerPacket;
        extern const hat::signature_view MinecraftPacket;
        extern const hat::signature_view InteractPacket_cctor;
        extern const hat::signature_view ItemUseOnActorInventoryTransaction;
    }
    namespace gamemode {
        extern const hat::signature_view getDestroyRate;
        extern const hat::signature_view baseUseItem;
    }
    namespace enchantutils {
        extern const hat::signature_view getenchantlevel;
    }
    namespace tessellator {
        extern const hat::signature_view begin;
        extern const hat::signature_view vertex;
        extern const hat::signature_view color;
        extern const hat::signature_view setRotation;
        extern const hat::signature_view resetTransform;
        extern const hat::signature_view renderMeshImmediately;
    }
    namespace materialptr {
        extern const hat::signature_view createMaterial;
    }
    namespace actor {
        extern const hat::signature_view getNameTag;
    }
    namespace player {
        extern const hat::signature_view getDestroyProgress;
    }
    namespace blocksource {
        extern const hat::signature_view getSeenPercent;
    }
    namespace networkitemstackdescriptor {
        extern const hat::signature_view constructor;
    }
    namespace ContainerScreenController {
        extern const hat::signature_view ContainerScreenController__handleAutoPlace;
        extern const hat::signature_view ContainerScreenController__handleDropItem;
        extern const hat::signature_view ContainerScreenController__handlePlaceAll;
        extern const hat::signature_view ContainerScreenController__handleTakeAll;
        extern const hat::signature_view ContainerScreenController_tick;
    }
    namespace inventorytransactionmanager {
        extern const hat::signature_view addAction;
    }
    namespace hook {
        extern const hat::signature_view KeyMapHook;
        extern const hat::signature_view KeyMouseHook;
        extern const hat::signature_view HurtColorHook;
        extern const hat::signature_view CameraNoClip;
        extern const hat::signature_view HIDControllerHook;
        extern const hat::signature_view GetGammaHook;
        extern const hat::signature_view ActorLerpMotionHook;
        extern const hat::signature_view SetupAndRenderHook;
        extern const hat::signature_view FontDrawTransformedHook;
        extern const hat::signature_view GetCurrentSwingDurationHook;
        extern const hat::signature_view ServerTickBlockBreakingHook;
        extern const hat::signature_view CauseHurtHook;
        extern const hat::signature_view RenderLevelHook;
        extern const hat::signature_view getFovHook;
        extern const hat::signature_view ItemUseSlowdownSystemImpl_doItemUseSlowdownSystemHook;
        extern const hat::signature_view MobJumpFromGroundSystemImpl_mobJumpFromGroundHook;
    }
    namespace vtable {
        extern const hat::signature_view PlayerVtable;
        extern const hat::signature_view GamemodeVtable;
    }
    namespace global {
        extern const hat::signature_view survivalReach;
    }
    namespace component {
        extern const hat::signature_view getActorTypeComponent;
        extern const hat::signature_view getFallDistanceComponent;
        extern const hat::signature_view getRenderPositionComponent;
        extern const hat::signature_view getRuntimeIDComponent;
        extern const hat::signature_view getMobBodyRotationComponent;
        extern const hat::signature_view getMobEffectsComponent;
        extern const hat::signature_view onGroundFlag;
        extern const hat::signature_view getActorUniqueIDComponent;
    }
}