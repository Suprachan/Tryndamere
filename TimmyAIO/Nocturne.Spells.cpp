#include "Nocturne.h"
#include "Nocturne.Spells.h"
#include "Nocturne.Menu.h"
#include "Manamanager.h"
#include "../../rift-sdk-extensions/Include/Geometry.hpp"

using namespace Tryndamere;

void Spells::SpellQUse(const OrbwalkingMode mode)
{
	if (::Menu::Get<bool>("UseQOnLowHealth") && TryndamereQ.IsReady())
	{
		auto target = pCore->TS->GetTarget();
		auto percentHealth = (Player.GetHealth().Current / target->GetHealth().Max) * 100;
		if (percentHealth < ::Menu::Get<float>("Menu.HealthR"))
		{
			TryndamereQ.Cast();
		}
	}
}
//where is your menu ?
void Spells::SpellWUse(const OrbwalkingMode mode)
{
	if (::Menu::Get<bool>("UseWInCombo") && TryndanmereW.IsReady())
	{
		auto target = pCore->TS->GetTarget();
		if (target != NULL) {
			auto t = target->AsAIBaseClient();
			{
				TryndanmereW.Cast(t);
			}
		}
	}
}

void Spells::SpellEUse(const OrbwalkingMode mode)
{

}

void Spells::SpellRUse(const OrbwalkingMode mode)
{
	if (::Menu::Get<bool>("ComboR") && TryndamereR.IsReady() && TryndamereR.LastCastTick + 1000 < GetTickCount())
	{
		if (!TryndamereQ.IsReady() && Player.GetHealthPercent() <= ::Menu::Get<float>("Menu.HealthR"))
		{
			TryndamereR.Cast();
		}
	}
}
