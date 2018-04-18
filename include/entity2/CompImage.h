#pragma once

#include <entity0/Component.h>

#include <memory>

namespace pt2 { class Texture; }

namespace e2
{

struct CompImage : public e0::Component
{
	std::shared_ptr<pt2::Texture> tex = nullptr;

}; // CompImage

}