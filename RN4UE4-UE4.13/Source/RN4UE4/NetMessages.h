#pragma once

#include "UnrealString.h"

enum GameID
{
	ID_ONE,
	ID_TWO
};



struct NetMessage
{
	FString message;
	GameID gameID;
};