/*#include "KogMaw.h"
#include "KogMaw.Menu.h"
#include "KogMaw.Events.h"
#include "Manamanager.Menu.h"

using namespace KogMaw;

void ::KogMaw::KogMaw::Create()
{
	Menu::Create();
	ManamanagerMenu::Create();
	Events::Create();
}

float ::KogMaw::KogMaw::GetCausticSpittleDamage(AIBaseClient* enemy)
{
	auto damage = 0.f;
	const auto spellLevel = Player.GetSpell(SPELL_Q).Level -1;

	const float baseDamage[] = { 80.f, 130.f, 180.f, 230.f, 280.f };

	damage = baseDamage[spellLevel] + Player.GetAbilityPower() * 0.50f;
	damage = pSDK->DamageLib->CalculateMagicalDamage(&Player, enemy, damage);

	return damage;
}

float ::KogMaw::KogMaw::GetVoidOozeDamage(AIBaseClient* enemy)
{
	auto damage = 0.f;
	const auto spellLevel = Player.GetSpell(SPELL_E).Level -1;

	const float baseDamage[] = { 60.f, 105.f, 150.f, 195.f, 240.f };

	damage = baseDamage[spellLevel] + Player.GetAbilityPower() * 0.50f;
	damage = pSDK->DamageLib->CalculateMagicalDamage(&Player, enemy, damage);

	return damage;
}

float ::KogMaw::KogMaw::GetLivingArtilleryDamage(AIBaseClient* enemy)
{
	auto damage = 0.f;
	const auto spellLevel = Player.GetSpell(SPELL_R).Level - 1;
	const auto heroHealth = enemy->GetHealth();
	const auto missingHealthPercent = 1.f - heroHealth.Current / heroHealth.Max;

	const float baseDamage[] = { 100.f, 140.f, 180.f };

	damage = baseDamage[spellLevel] + Player.GetAbilityPower() * 0.25f + Player.GetBonusAttackDamage() * 0.65f;

	if (missingHealthPercent <= 60.f)
	{
		const auto bonusDamagePercent = missingHealthPercent * 0.833f;

		damage *= bonusDamagePercent;
	}else
	{
		damage *= 3.5f;
	}

	damage = pSDK->DamageLib->CalculateMagicalDamage(&Player, enemy, damage);

	return damage;
}
*/