#pragma once

#include <ecsx/Component.h>

#include <memory>

namespace pt2 { class Texture; }

namespace e2
{

struct CompImage : public ecsx::Component
{
	std::shared_ptr<pt2::Texture> tex = nullptr;

}; // CompImage

}