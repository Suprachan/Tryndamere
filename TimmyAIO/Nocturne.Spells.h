#pragma once
#include "TimmyAIO.h"
#include "Nocturne.h"

namespace Tryndamere
{
	class Spells
	{
	public:
		static void SpellQUse(OrbwalkingMode mode);
		static void SpellWUse(OrbwalkingMode mode);
		static void SpellEUse(OrbwalkingMode mode);
		static void SpellRUse(OrbwalkingMode mode);
	};
}