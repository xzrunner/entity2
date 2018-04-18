#pragma once

#include <entity0/Component.h>
#include <painting2/RenderColorMap.h>

namespace e2
{

struct CompColorMap : public e0::Component
{
	pt2::RenderColorMap col;

}; // CompColorMap

}