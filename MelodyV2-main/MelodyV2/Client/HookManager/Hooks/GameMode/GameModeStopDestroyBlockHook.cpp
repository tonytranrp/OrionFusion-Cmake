#include "GameModeStopDestroyBlockHook.h"

void GameModeStopDestroyBlock::GameMode_stopDestroyBlock(GameMode* _this, Vec3<int>* blockPos) {
	static PacketMine* packetMineMod = (PacketMine*)client->moduleMgr->getModule("PacketMine");
	if (packetMineMod->isEnabled()) return;
	oFunc(_this, blockPos);
}
void GameModeStopDestroyBlock::init(uintptr_t address) {
	MemoryUtils::CreateHook("GameMode_stopDestroyBlockHook", address, (void*)&GameModeStopDestroyBlock::GameMode_stopDestroyBlock, (void*)&oFunc);
}