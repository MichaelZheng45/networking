#include "vectors.h"
#include <cmath>

vectorsTwo makeVector(a3f32 xPos, a3f32 yPos)
{
	vectorsTwo result;
	result.xVal = xPos;
	result.yVal = yPos;
	return result;
}

vectorsTwo addVector(vectorsTwo first, vectorsTwo second)
{
	vectorsTwo result;
	result.xVal = first.xVal + second.xVal;
	result.yVal = first.yVal + second.yVal;
	return result;
}

a3f32 dot(vectorsTwo first, vectorsTwo second)
{
	return (first.xVal * second.xVal) + (first.yVal * second.yVal);
}

vectorsTwo lerp(a3f32 parameter, vectorsTwo first, vectorsTwo second)
{
	vectorsTwo diff = subtract(second, first);
	vectorsTwo norm = normalize(diff);
	a3f32 length = magnitude(diff);
	
	return multiply(norm, parameter * length);
}

vectorsTwo normalize(vectorsTwo first)
{
	a3f32 length = magnitude(first);
	vectorsTwo result = first;
	result.xVal /= length;
	result.yVal /= length;
	return result;
}

a3f32 magnitude(vectorsTwo first)
{
	a3f32 length = dot(first, first);
	length = std::sqrt(length);
	return	length;
}

vectorsTwo subtract(vectorsTwo first, vectorsTwo second)
{
	vectorsTwo result;
	result.xVal = first.xVal - second.xVal;
	result.yVal = first.yVal - second.yVal;
	return result;
}

vectorsTwo multiply(vectorsTwo first, a3f32 num)
{
	first.xVal *= num;
	first.yVal *= num;
	return first;
}