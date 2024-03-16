#include "HurtColorHook.h"

MC_Color* HurtColorHook::HurtColorCallback(__int64 a1, MC_Color* color, __int64 a3) {
	__int64 actor = *(uintptr_t*)(a3 + 0x38);
	int* v7 = *(int**)(actor + 0x630);
	static HurtColor* hurtColorMod = (HurtColor*)client->moduleMgr->getModule("HurtColor");
	if (hurtColorMod->isEnabled()) {
		color->r = hurtColorMod->hurtColor.r / 255.f;
		color->g = hurtColorMod->hurtColor.g / 255.f;
		color->b = hurtColorMod->hurtColor.b / 255.f;
		color->a = hurtColorMod->hurtColor.a / 255.f;
		if (hurtColorMod->fade) color->a *= (*v7 / 10.f);

		return color;
	}
	return func(a1, color, a3); // The Original Color is MC_Color(1.f, 0.f, 0.f, 0.6f)
}
void HurtColorHook::init() {
	uintptr_t address = MemoryUtils::getFuncFromCall(findSig(Sigs::hook::HurtColorHook));
	MemoryUtils::CreateHook("HurtColorHook", address, (void*)&HurtColorHook::HurtColorCallback, (void*)&func);
}
