#include "Nocturne.h"
#include "Nocturne.Menu.h"
#include "Nocturne.Events.h"
#include "Manamanager.Menu.h"

using namespace Tryndamere;

void ::Tryndamere::Tryndamere::Create()
{
	Menu::Create();
	ManamanagerMenu::Create();
	Events::Create();
}

static float BloodlustHeal()
{
	auto healing = 0.f;

	const float base[] = { 0.f, 30.f, 40.f, 50.f, 60.f, 70.f };
	healing += base[Player.GetSpell(0).Level] + Player.GetAbilityPower() * 0.3f;

	return healing;
}

float ::Tryndamere::Tryndamere::MockingShout(AIBaseClient* enemy)
{
	auto slow = 0.f;

	const float base[] = { 30.f, 37.f, 45.f, 52.f, 60.f };
	slow += base[Player.GetSpell(0).Level];

	return slow;
}

float ::Tryndamere::Tryndamere::SpinningSlash(AIBaseClient* enemy)
{
	auto damage = 0.f;
	const auto spellLevel = Player.GetSpell(SPELL_E).Level - 1;

	const float baseDamage[] = { 80.f, 110.f, 140.f, 170.f, 200.f };

	damage = baseDamage[spellLevel] + (Player.GetAttackDamage() * 1.30f) + (Player.GetAbilityPower() * 1.00f);
	damage = pSDK->DamageLib->CalculateMagicalDamage(&Player, enemy, damage);

	return damage;
}


//float ::Tryndamere::Tryndamere::