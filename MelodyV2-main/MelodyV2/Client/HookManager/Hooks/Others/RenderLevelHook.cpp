#include "RenderLevelHook.h"

__int64 RenderLevelHook::LevelRenderer_renderLevel(__int64 a1, ScreenContext* a2, __int64 a3) {
	__int64 result = func(a1, a2, a3);
	if (RenderUtils::blendMaterial != nullptr) {
		RenderUtils::setGameRenderContext(a2);
		client->moduleMgr->onLevelRender();
		RenderUtils::setGameRenderContext(nullptr);
	}
	return result;
}
void RenderLevelHook::init() {
	uintptr_t address = findSig(Sigs::hook::RenderLevelHook);
	MemoryUtils::CreateHook("RenderLevelHook", address, (void*)&RenderLevelHook::LevelRenderer_renderLevel, (void*)&func);
}
