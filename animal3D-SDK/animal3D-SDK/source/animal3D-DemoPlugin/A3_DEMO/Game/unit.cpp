#include "Unit.h"

void updateUnit(a3_Unit& unit, a3f64 time)
{
	unit.position = addVector(multiply(unit.direction, unit.velocity * time), unit.position);
}