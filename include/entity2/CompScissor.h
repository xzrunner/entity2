#pragma once

#include <ecsx/Component.h>
#include <SM_Rect.h>

namespace e2
{

struct CompScissor : public ecsx::Component
{
	sm::rect rect;

}; // CompScissor

}