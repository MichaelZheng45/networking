#pragma once

#include "RakNet/MessageIdentifiers.h"
#include "RakNet/BitStream.h"

enum a3_NetGameMessages
{
	ID_CUSTOM_MESSAGE_START = ID_USER_PACKET_ENUM ,
	ID_CLIENT_NOTIFIED,
	ID_GAME_MESSAGE_1,
	ID_GAME_EVENT
};