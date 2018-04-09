#pragma once

#include <ecsx/Component.h>

namespace e2
{

struct CompPosition : public ecsx::Component
{
	CompPosition() : x(0), y(0) {}
	CompPosition(float x, float y) : x(x), y(y) {}

	float x, y;

}; // PositionComp

}