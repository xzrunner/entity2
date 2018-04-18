#pragma once

#include <entity0/Component.h>
#include <painting2/Text.h>

namespace e2
{

struct CompText : public e0::Component
{
	pt2::Text text;
}; // CompText

}