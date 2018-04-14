#pragma once

#include <ecsx/Component.h>
#include <ecsx/Entity.h>

namespace e2
{

struct CompMask : public ecsx::Component
{
	ecsx::Entity base, mask;

}; // CompMask

}