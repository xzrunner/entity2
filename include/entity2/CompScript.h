#pragma once

#include <entity0/Component.h>
#include <moon/SceneNodeScript.h>

namespace e2
{

struct CompScript : public e0::Component
{
	moon::SceneNodeScript script;

}; // CompScript

}