#include "Module.h"
#include "Client/Notifications.h"

Setting::~Setting() {
	delete minValue;
	delete maxValue;
}

Module::Module(const std::string& mName, const std::string& des, Category c, int k) {
	this->moduleName = obfuscate(mName);
	this->description = des;
	this->category = c;
	this->keybind = k;
	addBoolCheck("Visible", "Show module in Arraylist.", &visible);
	addKeybindSetting("Keybind", "Changes module keybind.", &keybind);
	addEnumSetting("Toggle", "Changes toggle modes.", { "Normal", "Hold" }, &toggleMod);
}

Module::~Module() {
	for (Setting* setting : this->settingList) {
		delete setting;
	}
}

std::string Module::getModuleName() {
	return deobfuscate(this->moduleName);
}

std::string Module::getModName() {
	return this->modName;
}

std::string Module::getDescription() {
	return this->description;
}

bool Module::isEnabled() {
	return this->enabled;
}

void Module::setEnabled(bool enabled) {
	if (this->enabled != enabled) {
		this->enabled = enabled;

		if (this->getModuleName() != "ClickGui") {
			std::string message = std::string(this->getModuleName()) + (enabled ? " has been enabled" : " has been disabled");
			Notifications::addNotifBox(message, 2.f);
		}

		if (enabled) this->onEnable();
		else this->onDisable();
	}
}

void Module::toggle() {
	this->setEnabled(!this->enabled);
}

bool Module::isVisible() {
	return this->visible;
}

void Module::onEnable() {
}

void Module::onDisable() {
}

void Module::onSaveConfig(json* currentConfig) {
	json obj = (*currentConfig)[getModuleName()];
	obj["enabled"] = enabled;
	for (Setting* setting : this->settingList) {
		switch (setting->settingType) {
		case (SettingType::KEYBIND): {
			obj[setting->settingName] = setting->valuePtr->_int;
			break;
		}
		case (SettingType::BOOL): {
			obj[setting->settingName] = setting->valuePtr->_bool;
			break;
		}
		case (SettingType::ENUM): {
			obj[setting->settingName] = *setting->enumValue;
			break;
		}
		case (SettingType::COLOR): {
			obj[setting->settingName] = ColorUtils::RGBtoHex(*setting->colorPtr);
			std::string alpha = setting->settingName + "Alpha";
			obj[alpha] = setting->colorPtr->a;
			break;
		}
		case (SettingType::SLIDER): {
			if (setting->valueType == ValueType::INT_T) {
				obj[setting->settingName] = setting->valuePtr->_int;
			}
			else if (setting->valueType == ValueType::FLOAT_T) {
				obj[setting->settingName] = setting->valuePtr->_float;
			}
			break;
		}
		}
	}
	(*currentConfig)[getModuleName()] = obj;
}

void Module::onLoadConfig(json* config) {
	if (config->contains(getModuleName())) {
		auto obj = config->at(getModuleName());
		if (obj.is_null())
			return;
		for (auto it = this->settingList.begin(); it != this->settingList.end(); ++it) {
			Setting* setting = *it;
			if (obj.contains("enabled")) {
				auto value = obj.at("enabled");
				if (value.is_null()) continue;
				//enabled = value.get<bool>();
				setEnabled(value.get<bool>());
			}
			if (obj.contains(setting->settingName)) {
				auto value = obj.at(setting->settingName);
				if (value.is_null())
					continue;

				switch (setting->settingType) {
				case (SettingType::KEYBIND): {
					setting->valuePtr->_int = value.get<int>();
					break;
				}
				case (SettingType::BOOL): {
					setting->valuePtr->_bool = value.get<bool>();
					break;
				}
				case (SettingType::ENUM): {
					*setting->enumValue = value.get<int>();
					break;
				}
				case (SettingType::COLOR): {
					*setting->colorPtr = ColorUtils::HexToRGB(value.get<std::string>());
					static const Vec2<float> colorPickerSize = Vec2<float>(136.f, 100.f);
					static float h, s, v;
					ImGui::ColorConvertRGBtoHSV((float)setting->colorPtr->r / 255.f, (float)setting->colorPtr->g / 255.f, (float)setting->colorPtr->b / 255.f, h, s, v);
					setting->hueDuration = h;
					setting->pos = Vec2<float>(s * colorPickerSize.x, (v - 1.f) * -1.f * colorPickerSize.y);
					break;
				}
				case (SettingType::SLIDER): {
					if (setting->valueType == ValueType::INT_T) {
						setting->valuePtr->_int = value.get<int>();
					}
					else if (setting->valueType == ValueType::FLOAT_T) {
						setting->valuePtr->_float = value.get<float>();
					}
					break;
				}
				}
			}
			std::string alpha = setting->settingName + "Alpha"; // dm ColorPicker
			if (obj.contains(alpha)) {
				auto value = obj.at(alpha);
				if (value.is_null())
					continue;
				setting->colorPtr->a = value.get<int>();
			}
		}
	}
}

void Module::onKeyUpdate(int key, bool isDown) {
	if (key == this->keybind) {
		if (this->toggleMod == 0) { // Normal
			if (isDown) this->toggle();
		}
		else { // Hold
			this->setEnabled(isDown);
		}
	}
}

void Module::onRender(MinecraftUIRenderContext* ctx) {
}

void Module::onImGuiRender(ImDrawList* drawlist) {
}

void Module::onNormalTick(Actor* actor) {
}
void Module::onContainerScreenControllerTickEvent(ContainerScreenControllerTickEvent* events) {
}

void Module::onSendPacket(Packet* packet, bool& shouldCancel) {
}

void Module::onLevelRender() {
}
