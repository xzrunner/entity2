#pragma once

#include <entity0/Component.h>
#include <entity0/Entity.h>

#include <vector>

namespace e2
{

struct CompComplex : public e0::Component
{
	std::shared_ptr<std::vector<e0::Entity>> children =
		std::make_unique<std::vector<e0::Entity>>();

}; // CompComplex

}