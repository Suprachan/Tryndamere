/*
//#include "KogMaw.h"
#include "KogMaw.Menu.h"
#include "KogMaw.Spells.h"
#include "../../rift-sdk-extensions/Include/Geometry.hpp"

using namespace KogMaw;

void Spells::SpellQUse(const OrbwalkingMode mode)
{
	if (mode == OrbwalkingMode::Combo && KogMawComboUseQ || mode == OrbwalkingMode::Mixed && KogMawHarassUseQ)
	{
		if (Q.IsReady())
		{
			const auto target = pCore->TS->GetTarget(1175.f);

			if (target != nullptr)
			{
				auto pred{ Q.GetPrediction(target)};
				if (pred != nullptr)
				{
					if (pred->CollisionResult != nullptr)
					{
						if (pred && pred->Hitchance >= HitChance(KogMawQPredHitchance + 2) && pred->CastPosition.IsValid())
						{
							Q.Cast(&pred->CastPosition);
						}
					}
				}
			}
		}
	}

	if (mode == OrbwalkingMode::None && KogMawAutoQHarass)
	{
		if (pSDK->EntityManager->GetEnemyTurrets(776.f).empty())
		{
			if (Q.IsReady())
			{
				const auto target = pCore->TS->GetTarget(1175.f);

				if (target != nullptr)
				{
					auto pred{ Q.GetPrediction(target)};
					if (pred != nullptr)
					{
						if (pred->CollisionResult != nullptr)
						{
							if (pred && pred->Hitchance >= HitChance(KogMawQPredHitchance + 2) && pred->CastPosition.IsValid())
							{
								Q.Cast(&pred->CastPosition);
							}
						}
					}
				}
			}
		}
	}

	if (mode == OrbwalkingMode::None && KogMawQKillSteal)
	{
		if (Q.IsReady())
		{
			const auto qSpell = Player.GetSpell(SPELL_Q);

			auto enemies = pSDK->EntityManager->GetEnemyHeroes(qSpell.CastRange);
			for (auto &[netID, enemy]: enemies)
			{
				if (enemy != nullptr)
				{
					if (pCore->TS->IsValidTarget(enemy) && enemy->Distance(&Player) > Player.GetTrueAttackRange(enemy))
					{
						auto enemyHealth = enemy->GetHealth().Current + enemy->GetHealth().MagicalShield + 5;
						enemyHealth -= KogMaw::GetCausticSpittleDamage(enemy);

						if (enemyHealth <= 0)
						{
							auto pred{ enemy ? Q.GetPrediction(enemy) : nullptr };
							if (pred && pred->Hitchance >= HitChance(KogMawQPredHitchance + 2) && pred->CastPosition.IsValid())
							{
								Q.Cast(&pred->CastPosition);
							}
						}
					}
				}
			}
		}
	}
}

void Spells::SpellWUse(OrbwalkingMode mode)
{
	if (mode == OrbwalkingMode::Combo && KogMawComboUseW || mode == OrbwalkingMode::Mixed && KogMawHarassUseW)
	{
		const auto wSpell = Player.GetSpell(SPELL_W);
		const auto spellLevel = wSpell.Level - 1;
		const float bonusRange[] = {130.f, 150.f, 170.f, 190.f, 210.f};

		if (W.IsReady())
		{
			if (!pSDK->EntityManager->GetEnemyHeroes(Player.GetTrueAttackRange() + bonusRange[spellLevel]).empty())
			{
				W.Cast();
			}
		}
	}

	else if (mode == OrbwalkingMode::LaneClear && KogMawLaneclearUseW)
	{
		if (pSDK->EntityManager->GetEnemyTurrets(776.f).empty() && KogMawLaneclearWTower || !KogMawLaneclearWTower)
		{
			const auto wSpell = Player.GetSpell(SPELL_W);
			const auto spellLevel = wSpell.Level - 1;
			const float bonusRange[] = {130.f, 150.f, 170.f, 190.f, 210.f};

			if (W.IsReady())
			{
				if (!pSDK->EntityManager->GetEnemyMinions(Player.GetTrueAttackRange() + bonusRange[spellLevel]).empty())
				{
					W.Cast();
				}
			}
		}
	}
}

void Spells::SpellEUse(const OrbwalkingMode mode)
{
	if (mode == OrbwalkingMode::None && KogMawEKillSteal)
	{
		if (W.IsReady())
		{
			const auto eSpell = Player.GetSpell(SPELL_E);

			auto enemies = pSDK->EntityManager->GetEnemyHeroes(eSpell.CastRange);
			for (auto &[netID, enemy]: enemies)
			{
				if (enemy != nullptr)
				{
					if (pCore->TS->IsValidTarget(enemy) && enemy->Distance(&Player) > Player.GetTrueAttackRange(enemy))
					{
						auto enemyHealth = enemy->GetHealth().Current + enemy->GetHealth().MagicalShield + 5;
						enemyHealth -= KogMaw::GetCausticSpittleDamage(enemy);

						if (enemyHealth <= 0)
						{
							auto pred{ enemy ? E.GetPrediction(enemy) : nullptr };
							if (pred && pred->Hitchance >= HitChance(KogMawEPredHitchance + 2) && pred->CastPosition.IsValid())
							{
								E.Cast(&pred->CastPosition);
							}
						}
					}
				}
			}
		}
	}

	if (mode == OrbwalkingMode::Combo && KogMawComboUseE)
	{
		if (E.IsReady())
		{
			const auto target = pCore->TS->GetTarget(1280.f);

			if (target != nullptr)
			{
				if (target->Distance(&Player) >= Player.GetTrueAttackRange(target))
				{
					auto pred{ target ? E.GetPrediction(target) : nullptr };
					if (pred && pred->Hitchance >= HitChance(KogMawEPredHitchance + 2) && pred->CastPosition.IsValid())
					{
						E.Cast(&pred->CastPosition);
					}
				}
			}
		}
	}

	if (mode == OrbwalkingMode::LaneClear && KogMawLaneclearUseE)
	{
		if (E.IsReady())
		{
			std::vector<Vector2> minionVector = {};
			auto minions = pSDK->EntityManager->GetEnemyMinions(1280.f);
			for (auto &[netID, minion]: minions)
			{
				if (minion != nullptr)
				{
					if (pCore->TS->IsValidTarget(minion))
					{
						minionVector.emplace_back(minion->GetPosition());
					}
				}
			}
	
			auto playerVector2 = Player.GetPosition().To2D();
			const auto eHits = Geometry::BestCoveringRectangle(minionVector, playerVector2, 120.f);
			if (eHits.second >= 5)
			{
				E.Cast(&static_cast<SDKVECTOR>(eHits.first));
			}
		}
	}

	if (mode == OrbwalkingMode::Flee && KogMawFleeUseE)
	{
		if (E.IsReady())
		{
			const auto eSpell = Player.GetSpell(SPELL_E);

			AIHeroClient* target = nullptr;

			auto enemies = pSDK->EntityManager->GetEnemyHeroes(1280.f);
			for (auto &[netID, enemy]: enemies)
			{
				if (enemy != nullptr)
				{
					if (pCore->TS->IsValidTarget(enemy))
					{
						if (target == nullptr)
						{
							target = enemy;
						}

						if (target != nullptr)
						{
							if (Player.Distance(target) > Player.Distance(enemy))
							{
								target = enemy;
							}
						}
					}
				}
			}

			if (target != nullptr)
			{
				auto pred{ target ? E.GetPrediction(target) : nullptr };
				if (pred && pred->Hitchance >= HitChance(KogMawEPredHitchance + 2) && pred->CastPosition.IsValid())
				{
					E.Cast(&pred->CastPosition);
				}
			}
		}
	}
}

void Spells::SpellRUse(OrbwalkingMode mode)
{
	if (mode == OrbwalkingMode::None && KogMawRKillSteal)
	{
		if (R.IsReady())
		{
			const auto rSpell = Player.GetSpell(SPELL_R);

			auto enemies = pSDK->EntityManager->GetEnemyHeroes(rSpell.CastRange);
			for (auto &[netID, enemy]: enemies)
			{
				if (enemy != nullptr)
				{
					if (pCore->TS->IsValidTarget(enemy) && enemy->Distance(&Player) >= Player.GetTrueAttackRange(enemy))
					{
						auto enemyHealth = enemy->GetHealth().Current + enemy->GetHealth().MagicalShield + 5.f;
						enemyHealth -= KogMaw::GetLivingArtilleryDamage(enemy);

						if (enemyHealth <= 0.f)
						{
							auto pred{ enemy ? R.GetPrediction(enemy) : nullptr };
							if (pred && pred->Hitchance >= HitChance(KogMawRPredHitchance + 2) && pred->CastPosition.IsValid())
							{
								R.Cast(&pred->CastPosition);
							}
						}
					}
				}
			}
		}
	}

	if (mode == OrbwalkingMode::None && KogMawAutoRHarass)
	{
		if (pSDK->EntityManager->GetEnemyTurrets(776.f).empty())
		{
			if (R.IsReady() && pSDK->BuffManager->GetBuffStacks(Player.NetworkID, "kogmawlivingartillerycost") <= KogMawAutoRHarassMaxStacks - 1)
			{
				const auto target = pCore->TS->GetTarget(Player.GetSpell(SPELL_R).CastRange);

				if (target != nullptr)
				{
					auto pred{ target ? R.GetPrediction(target) : nullptr };
					if (pred && pred->Hitchance >= HitChance(KogMawRPredHitchance + 2) && pred->CastPosition.IsValid())
					{
						R.Cast(&pred->CastPosition);
					}
				}
			}
		}
	}

	if (mode == OrbwalkingMode::Combo && KogMawComboUseR)
	{
		if (R.IsReady() && pSDK->BuffManager->GetBuffStacks(Player.NetworkID, "kogmawlivingartillerycost") <= KogMawComboMaxStacks - 1)
		{
			const auto target = pCore->TS->GetTarget(Player.GetSpell(SPELL_R).CastRange);

			if (target != nullptr)
			{
				if (KogMawCombo40Percent && target->GetHealthPercent() <= 40.f || !KogMawCombo40Percent)
				{
					auto pred{ target ? R.GetPrediction(target) : nullptr };
					if (pred && pred->Hitchance >= HitChance(KogMawRPredHitchance + 2) && pred->CastPosition.IsValid())
					{
						R.Cast(&pred->CastPosition);
					}
				}
			}
		}
	}

	else if (mode == OrbwalkingMode::Mixed && KogMawHarassUseR)
	{
		if (R.IsReady() && pSDK->BuffManager->GetBuffStacks(Player.NetworkID, "kogmawlivingartillerycost") <= KogMawHarassMaxStacks - 1)
		{
			const auto target = pCore->TS->GetTarget(Player.GetSpell(SPELL_R).CastRange);

			if (target != nullptr)
			{
				auto pred{ target ? R.GetPrediction(target) : nullptr };
				if (pred && pred->Hitchance >= HitChance(KogMawRPredHitchance + 2) && pred->CastPosition.IsValid())
				{
					R.Cast(&pred->CastPosition);
				}
			}
		}
	}

}
**/