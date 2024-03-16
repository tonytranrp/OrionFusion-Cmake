#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../Utils/ColorUtils.h"
#include "../../../../SDK/Classes/ScreenContext.h"
#include "../../../../SDK/Classes/TextHolder.h"

class FontDrawTransformedHook {
protected:
	using func_t = __int64(__thiscall*)(void*, ScreenContext*, TextHolder*, float, float, MC_Color, float, float, bool, float);
	static inline func_t func;

	static void FontDrawTransformedCallback(void* _this, ScreenContext* screenContext, TextHolder* textStr, float posX, float posY, MC_Color color, float angle, float scale, bool centered, float maxWidth);

public:
	static void init();
};
