#pragma once

#include <ecsx/Component.h>
#include <painting2/RenderColorCommon.h>

namespace e2
{

struct CompColorCommon : public ecsx::Component
{
	pt2::RenderColorCommon col;

}; // CompColorCommon

}