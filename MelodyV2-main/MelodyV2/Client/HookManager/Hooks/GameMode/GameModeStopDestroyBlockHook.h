#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../Utils/Math.h"
#include "../../../../SDK/Classes/GameMode.h"

#include "../../../Client.h"

class GameModeStopDestroyBlock {
protected:
	using func_t = void(__fastcall*)(GameMode*, Vec3<int>*);
	static inline func_t oFunc;

	static void GameMode_stopDestroyBlock(GameMode* _this, Vec3<int>* blockPos);
public:
	static void init(uintptr_t address);
};