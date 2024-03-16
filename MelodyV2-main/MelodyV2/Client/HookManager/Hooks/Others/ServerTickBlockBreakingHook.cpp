#include "ServerTickBlockBreakingHook.h"

void ServerTickBlockBreakingHook::ServerPlayerBlockUseHandler_serverTickBlockBreaking(__int64 _this, Player* player, Vec3<int>* blockPos) {
	func(_this, player, blockPos);
}
void ServerTickBlockBreakingHook::init() {
	uintptr_t address = findSig(Sigs::hook::ServerTickBlockBreakingHook);
	MemoryUtils::CreateHook("ServerTickBlockBreakingHook", address, (void*)&ServerTickBlockBreakingHook::ServerPlayerBlockUseHandler_serverTickBlockBreaking, (void*)&func);
}