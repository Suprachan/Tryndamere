/*
#include "Draven.h"
#include "Draven.Events.h"
#include "Manamanager.Menu.h"

using namespace Draven;

int DravenAxeCount{0};

std::vector<void*> AxeList = std::vector<void*>();
float AxeCatchRange = 600.f;
void* DravenRObject = nullptr;
AIBaseClient* CastedRTarget = nullptr;

Vector3 OrbMovePos;

void ::Draven::Draven::Create()
{
	Menu::Create();
	ManamanagerMenu::Create();
	Events::Create();
}

float ::Draven::Draven::GetEDamage(AIBaseClient* enemy)
{
	float baseDamage[] = { 75.f, 110.f, 145.f, 180.f, 215.f };
	const auto spellLevel = Player.GetSpell(SPELL_E).Level - 1;

	auto damage = baseDamage[spellLevel] + Player.GetBonusAttackDamage() * 0.5f;
	damage = pSDK->DamageLib->CalculatePhysicalDamage(&Player, enemy, damage);

	return damage;
}

float ::Draven::Draven::GetRDamage(AIBaseClient* enemy)
{

	float baseDamage[] = { 175.f, 275.f, 375.f };
	const auto spellLevel = Player.GetSpell(SPELL_E).Level - 1;

	auto damage = baseDamage[spellLevel] + Player.GetBonusAttackDamage() * 1.1f;
	Vector3 playerPos = Player.GetPosition();
	Vector3 enemyPos = enemy->GetPosition();
	const auto collisionCount = static_cast<float>(pSDK->Collision->GetCollisions(playerPos, enemyPos, R.Delay, R.Speed).use_count()) ;
	
	auto damagePercent = collisionCount * 0.08f;
	if (damagePercent < 0.4f)
		damagePercent = 0.4f;
	damage *= damagePercent;
	
	damage += baseDamage[spellLevel] + Player.GetBonusAttackDamage() * 1.1f;

	damage = pSDK->DamageLib->CalculatePhysicalDamage(&Player, enemy, damage);

	return damage;
}

void ::Draven::Draven::BestAxe()
{
	if (!DravenCatchAxesAttack && !pCore->Orbwalker->CanMove())
		return;

	SDKVECTOR mousePos = Renderer::MousePos();

	auto target = pCore->TS->GetTarget(800.f, DamageType::Physical);
	
	//TODO: Create menu's for this stuff
	if (target != nullptr)
	{
		if (Player.Distance(target) > 400.f && pSDK->DamageLib->GetAutoAttackDamage(&Player, target, true) * 2.f > target->GetHealth().Current + target->GetHealth().AllShield)
		{
			pCore->Orbwalker->DisableMovement(false);

			if (DravenCatchAxesAttack)
				pCore->Orbwalker->DisableAttack(false);

			return;
		}
	}

	if (AxeList.empty())
	{
		pCore->Orbwalker->DisableMovement(false);
		
		if (DravenCatchAxesAttack)
			pCore->Orbwalker->DisableAttack(false);

	}
	else if (AxeList.size() == 1)
	{
		CatchAxe(AxeList.front());
	}
	else
	{
		auto bestAxe = AxeList.front();
	
		SDKVECTOR bestAxePos;
		SdkGetObjectPosition(bestAxe, &bestAxePos);
	
		for (auto axe: AxeList)
		{
			SDKVECTOR axePos;
			SdkGetObjectPosition(axe, &axePos);
	
			if (mousePos.Distance(bestAxePos) > mousePos.Distance(axePos))
				bestAxe = axe;
		}
		CatchAxe(bestAxe);
	}
}

void ::Draven::Draven::CatchAxe(void* object)
{
	SDKVECTOR axePos;
	SdkGetObjectPosition(object, &axePos);

	SDKVECTOR mousePos = Renderer::MousePos();

	if (Player.Distance(axePos) < 90.f)
	{
		pCore->Orbwalker->DisableMovement(false);
		
		if (DravenCatchAxesAttack)
			pCore->Orbwalker->DisableAttack(false);

		return;
	}
	
	for (auto &[netID, turret]: pSDK->EntityManager->GetEnemyTurrets(1500.f))
	{
		if (turret->Distance(axePos) <= 775.f)
		{
			pCore->Orbwalker->DisableMovement(false);
			
			if (DravenCatchAxesAttack)
				pCore->Orbwalker->DisableAttack(false);

			return;
		}
	}
	
	auto heroCount = 0;
	for (auto &[netID, hero] : pSDK->EntityManager->GetEnemyHeroes(1500.f))
	{
		if (hero->Distance(axePos) <= 500.f)
			heroCount++;
	}
	
	if (heroCount > 2)
	{
		pCore->Orbwalker->DisableMovement(false);
		
		if (DravenCatchAxesAttack)
			pCore->Orbwalker->DisableAttack(false);

		return;
	}

	if (mousePos.Distance(axePos) < AxeCatchRange)
	{
		pCore->Orbwalker->DisableMovement(true);
		
		if (DravenCatchAxesAttack)
			pCore->Orbwalker->DisableAttack(true);

		pSDK->Control->Move(&axePos);
	}
	else
	{
		pCore->Orbwalker->DisableMovement(false);
		
		if (DravenCatchAxesAttack)
			pCore->Orbwalker->DisableAttack(false);
	}
}
*/