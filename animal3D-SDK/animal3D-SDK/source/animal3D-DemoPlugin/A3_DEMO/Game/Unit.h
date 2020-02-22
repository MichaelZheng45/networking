#pragma once

#ifndef UNIT_H
#define UNIT_H

#include "animal3D/animal3D.h"

#ifdef __cplusplus
extern "C"
{
#else	//! __cplusplus
typedef struct a3_Unit				a3_Unit;
#endif // __ cplusplus

struct a3_Unit
{
	a3i32 unitID;
	a3i32 xPos;
	a3i32 yPos;
	
};



#ifdef __cplusplus
}
#endif	// __cplusplus

#endif // !UNIT_H
