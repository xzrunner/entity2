#pragma once

#include <SM_Rect.h>

namespace ecsx { struct Entity; class World; }

namespace e2
{

class SysBoundingBox
{
public:
	static void Combine(sm::rect& aabb, const ecsx::World& world, 
		const ecsx::Entity& entity);

}; // SysBoundingBox

}