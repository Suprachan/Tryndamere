/*
#include "Draven.h"
#include "Draven.Spells.h"

using namespace Draven;

void Spells::SpellQUse(const OrbwalkingMode mode)
{
	const auto canCastSpell = Q.IsReady();

	auto shouldCast{false};

	if (pCore->Orbwalker->GetTarget() != nullptr)
		shouldCast = true;

	if (mode == OrbwalkingMode::Combo && UseQInCombo)
	{
		if (canCastSpell && shouldCast)
			Q.Cast();
	}

	else if (mode == OrbwalkingMode::LastHit && UseQInLasthit && LasthitSecondAxeOption)
	{
		if (canCastSpell && shouldCast && DravenAxeCount < 2)
			Q.Cast();
	}

	else if (mode == OrbwalkingMode::LastHit && UseQInLasthit && !LasthitSecondAxeOption)
	{
		if (canCastSpell && shouldCast && DravenAxeCount < 1)
			Q.Cast();

	}

	else if (mode == OrbwalkingMode::Mixed && UseQInHarass && HarassSecondAxeOption)
	{
		if (canCastSpell && shouldCast && DravenAxeCount < 2)
			Q.Cast();
	}

	else if (mode == OrbwalkingMode::Mixed && UseQInHarass && !HarassSecondAxeOption)
	{
		if (canCastSpell && shouldCast && DravenAxeCount < 1)
			Q.Cast();
	}

	else if (mode == OrbwalkingMode::LaneClear && UseQInLaneclear && LaneclearSecondAxeOption)
	{
		if (canCastSpell && shouldCast && DravenAxeCount < 2)
			Q.Cast();
	}

	else if (mode == OrbwalkingMode::LaneClear && UseQInLaneclear && !LaneclearSecondAxeOption)
	{
		if (canCastSpell && shouldCast && DravenAxeCount < 1)
			Q.Cast();
	}
}

void Spells::SpellWUse(const OrbwalkingMode mode)
{
	if (mode == OrbwalkingMode::Combo && UseWInCombo)
	{
		if (W.IsReady() && pCore->Orbwalker->CanMove() && !pSDK->EntityManager->GetEnemyHeroes(850.f).empty() && !pSDK->BuffManager->HasBuff(Player.NetworkID, "dravenfurybuff"))
		{
			W.Cast();
		}
	}

	else if (mode == OrbwalkingMode::Mixed && UseWInHarass)
	{
		if (W.IsReady() && !pSDK->EntityManager->GetEnemyHeroes(1000.f).empty() && pSDK->EntityManager->GetEnemyHeroes(Player.GetTrueAttackRange()).empty())
		{
			if (!pSDK->BuffManager->HasBuff(Player.NetworkID, "dravenfurybuff"))
				W.Cast();
		}
	}
	else if (mode == OrbwalkingMode::Flee && UseWInFlee && W.IsReady())
	{
		W.Cast();
	}
}

void Spells::SpellEUse(const OrbwalkingMode mode)
{
	if (mode == OrbwalkingMode::None)
	{
		if (E.IsReady())
		{
			auto enemies = pSDK->EntityManager->GetEnemyHeroes(1050.f);
			for (auto &[netID, enemy]: enemies)
			{
				if (enemy != nullptr)
				{
					if (KillstealE && pCore->TS->IsValidTarget(enemy) && Player.Distance(enemy) > Player.GetTrueAttackRange(enemy))
					{
						auto enemyHealth = enemy->GetHealth().Current + enemy->GetHealth().PhysicalShield + 10.f;
						enemyHealth -= Draven::GetEDamage(enemy);

						if (enemyHealth <= 0.f)
						{
							auto pred{ enemy ? E.GetPrediction(enemy) : nullptr };
							if (pred && pred->Hitchance >= HitChance(DravenEPredHitchance + 2) && pred->CastPosition.IsValid())
							{
								E.Cast(&pred->CastPosition);
								break;
							}
						}
					}

					else if (UseEOnMelee && pCore->TS->IsValidTarget(enemy) && enemy->IsMelee() && Player.Distance(enemy) < 250.f)
					{
						auto pred{ enemy ? E.GetPrediction(enemy) : nullptr };
						if (pred && pred->Hitchance >= HitChance(DravenEPredHitchance + 2) && pred->CastPosition.IsValid())
						{
							E.Cast(&pred->CastPosition);
							break;
						}
					}
				}
			}
		}
	}

	else if (mode == OrbwalkingMode::Combo)
	{
		if (E.IsReady())
		{
			const auto target = pCore->TS->GetTarget(1050.f);

			if (target != nullptr)
			{
				if (R.IsReady())
				{
					auto targetHealth = target->GetHealth().Current + target->GetHealth().PhysicalShield;
					targetHealth -= Draven::GetRDamage(target);

					if (targetHealth > 0.f)
					{
						if (UseEOnOutOfRange && Player.Distance(target) > Player.GetTrueAttackRange(target))
						{
							auto pred{ target ? E.GetPrediction(target) : nullptr };
							if (pred && pred->Hitchance >= HitChance(DravenEPredHitchance + 2) && pred->CastPosition.IsValid())
							{
								E.Cast(&pred->CastPosition);
							}
						}
					}
				}
				else if (!R.IsReady())
				{
					if (UseEOnOutOfRange && Player.Distance(target) > Player.GetTrueAttackRange(target))
					{
						auto pred{ target ? E.GetPrediction(target) : nullptr };
						if (pred && pred->Hitchance >= HitChance(DravenEPredHitchance + 2) && pred->CastPosition.IsValid())
						{
							E.Cast(&pred->CastPosition);
						}
					}
				}
	
				else if (UseEOnLowHealth && Player.GetHealth().Current < Player.GetHealth().Max * 0.5f)
				{
					auto pred{ target ? E.GetPrediction(target) : nullptr };
					if (pred && pred->Hitchance >= HitChance(DravenEPredHitchance + 2) && pred->CastPosition.IsValid())
					{
						E.Cast(&pred->CastPosition);
					}
				}
			}
		}
	}

	else if (mode == OrbwalkingMode::Flee && UseEInFlee)
	{
		AIHeroClient* bestHero = nullptr;

		auto enemies = pSDK->EntityManager->GetEnemyHeroes(1050.f);
		for (auto &[netID, enemy]: enemies)
		{
			if (enemy != nullptr)
			{
				if (pCore->TS->IsValidTarget(enemy))
				{
					if (bestHero != nullptr)
					{
						if (Player.Distance(enemy) < Player.Distance(bestHero))
						{
							bestHero = enemy;
						}
					}
					else
					{
						bestHero = enemy;
					}
				}
			}
		}

		if (bestHero != nullptr && E.IsReady())
		{
			auto pred{ bestHero ? E.GetPrediction(bestHero) : nullptr };
			if (pred && pred->Hitchance >= HitChance(DravenEPredHitchance + 2) && pred->CastPosition.IsValid())
			{
				E.Cast(&pred->CastPosition);
			}
		}
	}
}

void Spells::SpellRUse(const OrbwalkingMode mode)
{
	if (CastedRTarget != nullptr)
	{
		if (Player.GetBuff("DravenRDoublecast").Stacks && DravenRObject != nullptr && R.IsReady())
		{
			SDKVECTOR DravenRObjectPosition;
			SdkGetObjectPosition(DravenRObject, &DravenRObjectPosition);

			if (CastedRTarget->Distance(DravenRObjectPosition) <= 20)
				R2.Cast();
		}
	}

	else if (mode == OrbwalkingMode::None && KillstealR)
	{
		if (R.IsReady())
		{
			auto enemies = pSDK->EntityManager->GetEnemyHeroes(KillstealRRange);
			for (auto &[netID, enemy]: enemies)
			{
				if (enemy != nullptr)
				{
					if (pCore->TS->IsValidTarget(enemy) && enemy->Distance(&Player) >= Player.GetTrueAttackRange(enemy) + 50.f)
					{
						auto enemyHealth = enemy->GetHealth().Current + enemy->GetHealth().AllShield + 10.f;
						enemyHealth -= Draven::GetRDamage(enemy);


						SdkUiConsoleWrite("RDamage: %f", Draven::GetRDamage(enemy));

						if (enemyHealth <= 0.f)
						{
							auto pred{R.GetPrediction(enemy)};
							if (pred != nullptr)
							{
								if (pred && pred->Hitchance >= HitChance(DravenRPredHitchance + 2) && pred->CastPosition.IsValid())
								{
									R.Cast(&pred->CastPosition);
									CastedRTarget = enemy;
								}
							}
						}
					}
				}
			}
		}
	}
}
*/ 