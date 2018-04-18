#pragma once

#include <entity0/Component.h>
#include <SM_Vector.h>
#include <SM_Matrix2D.h>

namespace e2
{

struct CompPosition : public e0::Component
{
	CompPosition() {}
	CompPosition(const sm::vec2& pos) : pos(pos) {}

	sm::vec2 pos;

}; // CompPosition

struct CompAngle : public e0::Component
{
	CompAngle() : angle(0) {}
	CompAngle(float angle) : angle(angle) {}

	float angle;

}; // CompAngle

struct CompScale : public e0::Component
{
	CompScale() : scale(1, 1) {}
	CompScale(const sm::vec2& scale) : scale(scale) {}

	sm::vec2 scale;

}; // CompScale

struct CompShear : public e0::Component
{
	CompShear() {}
	CompShear(const sm::vec2& shear) : shear(shear) {}

	sm::vec2 shear;

}; // CompShear

struct CompOffset : public e0::Component
{
	CompOffset() {}
	CompOffset(const sm::vec2& offset) : offset(offset) {}

	sm::vec2 offset;

}; // CompOffset

struct CompLocalMat : public e0::Component
{
	sm::Matrix2D mat;

}; // CompLocalMat

}