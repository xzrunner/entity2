#pragma once

#include <entity0/Component.h>
#include <SM_Rect.h>

namespace e2
{

struct CompScissor : public e0::Component
{
	sm::rect rect;

}; // CompScissor

}