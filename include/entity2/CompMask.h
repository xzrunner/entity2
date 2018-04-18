#pragma once

#include <entity0/Component.h>
#include <entity0/Entity.h>

namespace e2
{

struct CompMask : public e0::Component
{
	e0::Entity base, mask;

}; // CompMask

}