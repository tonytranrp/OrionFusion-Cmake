
#include "ActorGetBodyYawHook.h"

float ActorGetBodyYawHook::Actor_getInterpolatedBodyYaw(Actor* _this, float a1) { // Body Yaw
	if (_this == mc.getLocalPlayer()) {
		// Soon
	}
	return func(_this, a1);
}
void ActorGetBodyYawHook::init(uintptr_t address) {
	MemoryUtils::CreateHook("Actor_getInterpolatedBodyYawHook", address, (void*)&ActorGetBodyYawHook::Actor_getInterpolatedBodyYaw, (void*)&func);
}