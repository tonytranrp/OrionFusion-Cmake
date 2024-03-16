#include "ActorGetHeadRotHook.h"
float ActorGetHeadRotHook::Actor_getInterpolatedHeadRot(Actor* _this, float a1) { // Head Yaw
	if (_this == mc.getLocalPlayer()) {
		// Soon
	}
	return func(_this, a1);
}
void ActorGetHeadRotHook::init(uintptr_t address) {
	MemoryUtils::CreateHook("Actor_getInterpolatedHeadRotHook", address, (void*)&ActorGetHeadRotHook::Actor_getInterpolatedHeadRot, (void*)&func);
}