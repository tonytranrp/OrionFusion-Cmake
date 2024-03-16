#pragma once
#include "../../../../Utils/MemoryUtils.h"

#include "../../../Client.h"

class GetFovHook {
protected:
	using func_t = float(__thiscall*)(LevelRendererPlayer*, float, bool);
	static inline func_t func;

	static float LevelRendererPlayer_getFov(LevelRendererPlayer* _this, float a, bool applyEffects);
public:
	static void init();
};
