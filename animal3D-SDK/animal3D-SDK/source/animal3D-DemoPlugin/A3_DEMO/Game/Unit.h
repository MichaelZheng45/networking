#pragma once

#ifndef UNIT_H
#define UNIT_H

#include "animal3D/animal3D.h"
#include "vectors.h"
struct a3_Unit
{
	a3i32 unitID;
	vectorsTwo position;

	vectorsTwo direction;
	a3f32 velocity;


	a3boolean active = false;

	a3boolean updatedThisFrame = false;
};

void updateUnit(a3_Unit& unit, a3f64 time);


#endif // !UNIT_H
