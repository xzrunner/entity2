#pragma once

#include <ecsx/Component.h>
#include <ecsx/Entity.h>

#include <vector>

namespace e2
{

struct CompComplex : public ecsx::Component
{
	std::vector<ecsx::Entity> children;

}; // CompComplex

}