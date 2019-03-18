/*
#include "Draven.h"
#include "Draven.Spells.h"
#include "Draven.Modes.h"
#include "Manamanager.h"

using namespace Draven;

void Modes::None()
{
	Spells::SpellRUse(OrbwalkingMode::None);
	
	Spells::SpellEUse(OrbwalkingMode::None);
}

void Modes::Combo()
{
	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_Q), OrbwalkingMode::Combo))
		Spells::SpellQUse(OrbwalkingMode::Combo);
	
	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_W), OrbwalkingMode::Combo))
		Spells::SpellWUse(OrbwalkingMode::Combo);
	
	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_E), OrbwalkingMode::Combo))
		Spells::SpellEUse(OrbwalkingMode::Combo);
}

void Modes::LastHit()
{
	Spells::SpellQUse(OrbwalkingMode::LastHit);
}

void Modes::Harras()
{
	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_Q), OrbwalkingMode::Mixed))
		Spells::SpellQUse(OrbwalkingMode::Mixed);

	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_W), OrbwalkingMode::Mixed))
		Spells::SpellWUse(OrbwalkingMode::Mixed);
}

void Modes::LaneClear()
{
	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_Q), OrbwalkingMode::LaneClear))
		Spells::SpellQUse(OrbwalkingMode::LaneClear);
}

/*
void Modes::Flee()
{
	Spells::SpellWUse(OrbwalkingMode::Flee);
	Spells::SpellEUse(OrbwalkingMode::Flee);
}

*/