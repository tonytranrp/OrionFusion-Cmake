#include "AutoSprint.h"

AutoSprint::AutoSprint() : Module("AutoSprint", "Sprint for you.", Category::MOVEMENT) {
	addEnumSetting("Mode", "Change sprint modes.", { "Auto" }, &Mode);
}

void AutoSprint::onNormalTick(Actor* actor) {
	if (mc.getLocalPlayer() == nullptr) return;

	mc.getLocalPlayer()->setSprinting(true);
}