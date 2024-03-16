#pragma once
#include "../../../../Utils/MemoryUtils.h"

#include "../../../Client.h"

class RenderLevelHook {
protected:
	using func_t = __int64(__fastcall*)(__int64, ScreenContext*, __int64);
	static inline func_t func;

	static __int64 LevelRenderer_renderLevel(__int64 a1, ScreenContext* a2, __int64 a3);
public:
	static void init();
};
