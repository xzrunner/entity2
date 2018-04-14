#pragma once

#include <ecsx/Component.h>
#include <painting2/RenderColorMap.h>

namespace e2
{

struct CompColorMap : public ecsx::Component
{
	pt2::RenderColorMap col;

}; // CompColorMap

}