#pragma once

#include <dojo.h>

#include <Dojo2D/World.h>
#include <Dojo2D/Body.h>
#include <Dojo2D/BodyPart.h>
#include <Dojo2D/Material.h>
#include <Dojo2D/PhysUtil.h>
#include <Dojo2D/ParticleSystem.h>
#include <Dojo2D/Joint.h>
#include <Dojo2D/ForceField.h>
#include <Dojo2D/BodyPartType.h>

#include <memory>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <numeric>

enum class Layers {
	Background,

	_count
};

using namespace Dojo;
using namespace std::chrono_literals;
