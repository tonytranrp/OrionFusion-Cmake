
#include "ActorIsOnFireHook.h"
bool ActorIsOnFireHook::Actor_IsOnFire(Actor* _this) {
	static NoRender* noRenderMod = (NoRender*)client->moduleMgr->getModule("NoRender");
	if (noRenderMod->isEnabled() && noRenderMod->noFire && _this == (Actor*)mc.getLocalPlayer()) return false;
	return func(_this);
}

void ActorIsOnFireHook::init(uintptr_t address) {
	MemoryUtils::CreateHook("Actor_isOnFireHook", address, (void*)&ActorIsOnFireHook::Actor_IsOnFire, (void*)&func);
}
