#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../Utils/Math.h"
#include "../../../../SDK/Classes/GameMode.h"

#include "../../../Client.h"

class GameModeStartDestroyBlock {
protected:
	using func_t = bool(__fastcall*)(GameMode*, Vec3<int>*, uint8_t, bool*);
	static inline func_t oFunc;

	static bool GameMode_startDestroyBlock(GameMode* _this, Vec3<int>* blockPos, uint8_t face, bool* a4);
public:
	static void init(uintptr_t address);
};