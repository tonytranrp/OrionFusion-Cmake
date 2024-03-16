#include "KeyMapHook.h"

__int64 KeyMapHook::KeyPress(uint64_t key, bool isDown) {
	static ClickGui* clickGuiMod = (ClickGui*)client->moduleMgr->getModule("ClickGui");
	if (clickGuiMod->isEnabled()) {
		clickGuiMod->onKey((int)key, isDown);
		return 0;
	}

	if (mc.canUseMoveKeys() || mc.getLocalPlayer() == nullptr) client->moduleMgr->onKeyUpdate((int)key, isDown);
	return func(key, isDown);
}
void KeyMapHook::init() {
	uintptr_t address = findSig(Sigs::hook::KeyMapHook);
	MemoryUtils::CreateHook("KeyMapHook", address, (void*)&KeyMapHook::KeyPress, (void*)&func);
}
