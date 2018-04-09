#pragma once

#include <ecsx/Component.h>
#include <painting2/AABB.h>

namespace e2
{

struct CompBoundingBox : public ecsx::Component
{
	pt2::AABB aabb;

}; // CompBoundingBox

}