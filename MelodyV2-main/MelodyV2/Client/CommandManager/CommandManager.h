#pragma once
#include "Commands/Command.h"
#include "Commands/FriendCommand.h"
#include "../../SDK/Classes/Packet.h"
#include <vector>
#include <string>

class CommandManager {
private:
	std::vector<Command*> commandList;
public:
	char prefix = '.';
	CommandManager();
	~CommandManager();
	void onSendTextPacket(TextPacket* packet, bool& shouldCancel);
};