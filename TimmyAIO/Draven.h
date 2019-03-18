/*
#pragma once
#include "TimmyAIO.h"
#include "Draven.Menu.h"

extern int DravenAxeCount;
extern void* DravenRObject;
extern AIBaseClient* CastedRTarget;
extern std::vector<void*> AxeList;
extern float AxeCatchRange;

extern Vector3 OrbMovePos;

namespace Draven
{
	inline Spell::Active Q(SpellSlot::Q);
	inline Spell::Active W(SpellSlot::W);
	inline Spell::Skillshot E(SpellSlot::E, 1050.f, SkillshotType::Line, 0.884956f, 1600.f, 130.f);
	inline Spell::Skillshot R(SpellSlot::R, 5000.f, SkillshotType::Line, 0.25, 2000.f, 160.f);
	inline Spell::Active R2(SpellSlot::R);

	class Draven
	{
	public:
		static void Create();

		static float GetEDamage(AIBaseClient* enemy);
		static float GetRDamage(AIBaseClient* enemy);

		static void BestAxe();
		static void CatchAxe(void* object);
	};
}
*/