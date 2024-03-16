#include "GameModeGetPickRangeHook.h"

float GameModeGetPickRangeHook::GameMode_getPickRange(GameMode* _this, __int64 inputMode, bool a3) {
	static BlockReach* blockReachMod = (BlockReach*)client->moduleMgr->getModule("BlockReach");
	if (blockReachMod->isEnabled()) return blockReachMod->blockReach;

	return oFunc(_this, inputMode, a3);
}
void GameModeGetPickRangeHook::init(uintptr_t address) {
	MemoryUtils::CreateHook("GameMode_getPickRangeHook", address, (void*)&GameModeGetPickRangeHook::GameMode_getPickRange, (void*)&oFunc);
};