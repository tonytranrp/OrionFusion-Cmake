#include "GetFovHook.h"

float GetFovHook::LevelRendererPlayer_getFov(LevelRendererPlayer* _this, float a, bool applyEffects) {
	static CustomFov* customFovMod = (CustomFov*)client->moduleMgr->getModule("CustomFov");
	if (customFovMod->isEnabled()) {
		return customFovMod->fov;
	}
	return func(_this, a, applyEffects);
}
void GetFovHook::init() {
	MemoryUtils::CreateHook("CauseHurtHook", findSig(Sigs::hook::getFovHook), (void*)&GetFovHook::LevelRendererPlayer_getFov, (void*)&func);
}
