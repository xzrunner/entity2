#pragma once

#include <entity0/Component.h>
#include <painting2/RenderColorCommon.h>

namespace e2
{

struct CompColorCommon : public e0::Component
{
	pt2::RenderColorCommon col;

}; // CompColorCommon

}