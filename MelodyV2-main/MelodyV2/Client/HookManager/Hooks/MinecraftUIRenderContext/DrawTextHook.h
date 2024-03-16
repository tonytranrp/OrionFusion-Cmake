#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../SDK/Classes/MinecraftUIRenderContext.h"
#include "../../../../SDK/Classes/TextHolder.h"
#include "../../../../Utils/Math.h"
#include "../../../../Utils/ColorUtils.h"

#include "../../../Client.h"

class DrawTextHook {
protected:
	using func_t = __int64(__fastcall*)(MinecraftUIRenderContext*, FontBitmap*, float*, std::string*, MC_Color*, float, unsigned int, TextMeasureData*, CaretMeasureData*);
	static inline func_t func;

	static __int64 drawTextCallBack(MinecraftUIRenderContext* _this, FontBitmap* font, float* pos, std::string* text, MC_Color* color, float alpha, unsigned int textAlignment, TextMeasureData* textMeasureData, CaretMeasureData* caretMeasureData);
public:
	static void init(uintptr_t address);
};