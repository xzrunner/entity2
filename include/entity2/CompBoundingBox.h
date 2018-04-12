#pragma once

#include <ecsx/Component.h>
#include <SM_Rect.h>
#include <SM_Vector.h>

namespace e2
{

struct CompBoundingBox : public ecsx::Component
{
	CompBoundingBox() : angle(0) {}

	sm::rect rect;
	sm::vec2 position;
	float    angle;

}; // CompBoundingBox

}