#pragma once
#include "TimmyAIO.h"
#include "Nocturne.Menu.h"
namespace Tryndamere
{
	inline Spell::Active TryndamereQ(SpellSlot::Q);
	inline Spell::Active TryndanmereW(SpellSlot::W);
	inline Spell::Skillshot TryndamereE(SpellSlot::E, 660.f, SkillshotType::Line, 0.221239f, 1200.f, 120.f);
	inline Spell::Active TryndamereR(SpellSlot::R);

	class Tryndamere
	{
	public:
		static float BloodlustHeal(AIBaseClient* enemy);
		static float MockingShout(AIBaseClient* enemy);
		static float SpinningSlash(AIBaseClient* enemy);
		static void Create();
	};
}