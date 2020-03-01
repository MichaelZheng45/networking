#pragma once

#ifndef UNIT_H
#define UNIT_H

#include "animal3D/animal3D.h"

struct a3_Unit
{
	a3i32 unitID;
	a3i32 xPos;
	a3i32 yPos;

	a3i32 xDir;
	a3i32 yDir;

	a3boolean active = false;
};

#endif // !UNIT_H
