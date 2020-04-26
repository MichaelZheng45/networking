#ifndef  VECTORS_H
#define VECTORS_H

#include "animal3D/animal3D.h"

struct vectorsTwo
{
	a3f32 xVal;
	a3f32 yVal;
};
vectorsTwo makeVector(a3f32 xPos, a3f32 yPos);
vectorsTwo addVector(vectorsTwo first, vectorsTwo second);
a3f32 dot(vectorsTwo first, vectorsTwo second);
vectorsTwo lerp(a3f32 parameter,vectorsTwo first, vectorsTwo second);
vectorsTwo normalize(vectorsTwo first);
a3f32 magnitude(vectorsTwo first);
vectorsTwo subtract(vectorsTwo first, vectorsTwo second);
vectorsTwo multiply(vectorsTwo first, a3f32 num);


#endif // ! VECTORS_H
