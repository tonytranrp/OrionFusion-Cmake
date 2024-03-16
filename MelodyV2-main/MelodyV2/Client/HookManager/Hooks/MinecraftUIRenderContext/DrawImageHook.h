#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../SDK/Classes/MinecraftUIRenderContext.h"
#include "../../../../SDK/Classes/TextureData.h"
#include "../../../../Utils/Math.h"
#include "../../../ModuleManager/Modules/Client/HUD.h"
#include "../../../Client.h"

class DrawImageHook {
protected:
	using func_t = __int64(__fastcall*)(MinecraftUIRenderContext*, TextureData*, Vec2<float>&, Vec2<float>&, Vec2<float>&, Vec2<float>&);
	static inline func_t func;

	static __int64 drawImageCallBack(MinecraftUIRenderContext* _this, TextureData* texturePtr, Vec2<float>& imagePos, Vec2<float>& imageDimension, Vec2<float>& UvPos, Vec2<float>& UvSize);
public:
	static float lerping(float endPoint, float current, float speed) {
        if (speed < 0.0f)
            speed = 0.0f;
        else if (speed > 1.0f)
            speed = 1.0f;

        float minVal = (endPoint < current) ? endPoint : current;
        float maxVal = (endPoint > current) ? endPoint : current;

        float dif = maxVal - minVal;
        float factor = dif * speed;

        return current + ((endPoint > current) ? factor : -factor);
	}
	static void init(uintptr_t address);
};