#include "Nocturne.h"
#include "Nocturne.Spells.h"	
#include "Nocturne.Modes.h"
#include "Nocturne.Menu.h"
#include "Manamanager.h"

using namespace Tryndamere;

void Modes::None()
{
	if (KillstealE)
		Spells::SpellEUse(OrbwalkingMode::None);
}

void Modes::Combo()
{
	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_Q), OrbwalkingMode::Combo) && UseQOnLowHealth)
		Spells::SpellQUse(OrbwalkingMode::Combo);

	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_W), OrbwalkingMode::Combo) && UseWInCombo)
		Spells::SpellWUse(OrbwalkingMode::Combo);

	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_E), OrbwalkingMode::Combo) && UseEInCombo)
		Spells::SpellEUse(OrbwalkingMode::Combo);

	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_R), OrbwalkingMode::Combo) && UseROnLowHealth)
		Spells::SpellRUse(OrbwalkingMode::Combo);
}

void Modes::LastHit()
{
	Spells::SpellEUse(OrbwalkingMode::LastHit);

}

void Modes::Mixed()
{

	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_W), OrbwalkingMode::Mixed) && UseWInHarass)
		Spells::SpellWUse(OrbwalkingMode::Mixed);

	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_E), OrbwalkingMode::Mixed) && UseEInHarass)
		Spells::SpellEUse(OrbwalkingMode::Mixed);
}

void Modes::LaneClear() 
{
	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_Q), OrbwalkingMode::LaneClear) && UseQInLaneclear)
		Spells::SpellQUse(OrbwalkingMode::LaneClear);
	if (Manamanager::EnoughMana(Player.GetSpell(SPELL_E), OrbwalkingMode::LaneClear) && UseEInLaneclear)
		Spells::SpellEUse(OrbwalkingMode::LaneClear);
}
//lul, you should take some C++ classes online or whatever :P . IEnjoy  its done im doing it in code academy xDD. good the code is done, im leaving :P /

void Modes::Flee()
{
	if (UseEInFlee)
		Spells::SpellEUse(OrbwalkingMode::Flee);
}

/*extern bool UseEInCombo;
extern bool UseQInLaneclear;
extern bool UseEInLaneclear;
*/