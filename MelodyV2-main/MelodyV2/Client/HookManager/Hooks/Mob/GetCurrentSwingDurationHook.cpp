#include "GetCurrentSwingDurationHook.h"

int GetCurrentSwingDurationHook::Mob_GetCurrentSwingDuration(Mob* _this) {
	static Swing* swingMod = (Swing*)client->moduleMgr->getModule("Swing");
	if (swingMod->isEnabled() && _this == (Mob*)mc.getLocalPlayer()) {
		return swingMod->swingSpeed;
	}
	return func(_this);
}
void GetCurrentSwingDurationHook::init() {
	uintptr_t address = findSig(Sigs::hook::GetCurrentSwingDurationHook);
	MemoryUtils::CreateHook("Mob_GetCurrentSwingDurationHook", address, (void*)&GetCurrentSwingDurationHook::Mob_GetCurrentSwingDuration, (void*)&func);
}
