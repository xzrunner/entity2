#pragma once

#include <ecsx/Component.h>
#include <moon/SceneNodeScript.h>

namespace e2
{

struct CompScript : public ecsx::Component
{
	moon::SceneNodeScript script;

}; // CompScript

}