#include "GameModeStartDestroyBlockHook.h"

bool GameModeStartDestroyBlock::GameMode_startDestroyBlock(GameMode* _this, Vec3<int>* blockPos, uint8_t face, bool* a4) {
	bool result = oFunc(_this, blockPos, face, a4);
	static PacketMine* packetMineMod = (PacketMine*)client->moduleMgr->getModule("PacketMine");
	if (packetMineMod->isEnabled() && result) {
		packetMineMod->setBreakPos(*blockPos, face);
		return false;
	}
	return result;
}
void GameModeStartDestroyBlock::init(uintptr_t address) {
	MemoryUtils::CreateHook("GameMode_startDestroyBlockHook", address, (void*)&GameModeStartDestroyBlock::GameMode_startDestroyBlock, (void*)&oFunc);
}