#pragma once

#include <ecsx/Component.h>
#include <ecsx/Entity.h>

#include <vector>

namespace e2
{

struct CompComplex : public ecsx::Component
{
	std::shared_ptr<std::vector<ecsx::Entity>> children = 
		std::make_unique<std::vector<ecsx::Entity>>();

}; // CompComplex

}