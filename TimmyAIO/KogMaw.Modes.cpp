/*#include "KogMaw.h"
#include "KogMaw.Menu.h"
#include "KogMaw.Modes.h"
#include "KogMaw.Spells.h"
#include "Manamanager.h"

using namespace KogMaw;

void Modes::None()
{
	if (KogMawRKillSteal)
		Spells::SpellRUse(OrbwalkingMode::None);

	if (KogMawAutoQHarass && Manamanager::EnoughMana(Player.GetSpell(SPELL_Q), OrbwalkingMode::Mixed))
		Spells::SpellQUse(OrbwalkingMode::None);

	if (KogMawAutoRHarass && Manamanager::EnoughMana(Player.GetSpell(SPELL_R), OrbwalkingMode::Mixed))
		Spells::SpellRUse(OrbwalkingMode::None);
}

void Modes::Combo()
{
	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_Q), OrbwalkingMode::Combo) && KogMawComboUseQ)
		Spells::SpellQUse(OrbwalkingMode::Combo);

	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_W), OrbwalkingMode::Combo) && KogMawComboUseW)
		Spells::SpellWUse(OrbwalkingMode::Combo);

	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_E), OrbwalkingMode::Combo) && KogMawComboUseE)
		Spells::SpellEUse(OrbwalkingMode::Combo);

	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_R), OrbwalkingMode::Combo) && KogMawComboUseR)
		Spells::SpellRUse(OrbwalkingMode::Combo);
}

void Modes::LastHit()
{

}

void Modes::Harras()
{
	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_Q), OrbwalkingMode::Mixed) && KogMawHarassUseQ)
		Spells::SpellQUse(OrbwalkingMode::Mixed);

	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_W), OrbwalkingMode::Mixed) && KogMawHarassUseW)
		Spells::SpellWUse(OrbwalkingMode::Mixed);

	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_R), OrbwalkingMode::Mixed) && KogMawHarassUseR)
		Spells::SpellRUse(OrbwalkingMode::Mixed);
}

void Modes::LaneClear()
{
	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_W), OrbwalkingMode::LaneClear) && KogMawHarassUseW)
		Spells::SpellWUse(OrbwalkingMode::LaneClear);

	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_E), OrbwalkingMode::LaneClear) && KogMawHarassUseW)
		Spells::SpellEUse(OrbwalkingMode::LaneClear);
}

void Modes::Flee()
{
	if (KogMawFleeUseE)
		Spells::SpellEUse(OrbwalkingMode::Flee);
}

*/