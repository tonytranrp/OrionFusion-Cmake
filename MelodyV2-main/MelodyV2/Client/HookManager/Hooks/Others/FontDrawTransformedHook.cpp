#include "FontDrawTransformedHook.h"

void FontDrawTransformedHook::FontDrawTransformedCallback(void* _this, ScreenContext* screenContext, TextHolder* textStr, float posX, float posY, MC_Color color, float angle, float scale, bool centered, float maxWidth) {
	static TextHolder text("MelodyV2 is riel?");
	//static int mmb = 0;
	//mmb++;
	//if (mmb >= 360) mmb = 0;
	//angle = mmb; // Spin lfmao

	static float dScale = 1.5f; // dynamic Scale
	static bool up = true;
	if (up) {
		dScale += 0.01f;
		if (dScale >= 1.6f) up = false;
	}
	else {
		dScale -= 0.01f;
		if (dScale <= 1.4f) up = true;
	}
	scale = dScale;
	func(_this, screenContext, &text, posX, posY, color, angle, scale, centered, maxWidth);
}
void FontDrawTransformedHook::init() {
	uintptr_t address = findSig(Sigs::hook::FontDrawTransformedHook);
	MemoryUtils::CreateHook("FontDrawTransformedHook", address, (void*)&FontDrawTransformedHook::FontDrawTransformedCallback, (void*)&func);
}
