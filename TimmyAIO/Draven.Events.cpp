/*
#include "Draven.h"
#include "Draven.Events.h"
#include "Draven.Modes.h"
#include "Draven.Drawings.h"

using namespace Draven;

void Events::Update(void* UserData)
{
	if (DravenCatchAxesLaneClear && pCore->Orbwalker->IsModeActive(OrbwalkingMode::LaneClear))
		Draven::BestAxe();

	else if (DravenCatchAxesLastHit && pCore->Orbwalker->IsModeActive(OrbwalkingMode::LastHit))
		Draven::BestAxe();

	else if (DravenCatchAxesCombo && pCore->Orbwalker->IsModeActive(OrbwalkingMode::Combo))
		Draven::BestAxe();

	else if (DravenCatchAxesMixed && pCore->Orbwalker->IsModeActive(OrbwalkingMode::Mixed))
		Draven::BestAxe();
}

void Events::Tick(void* UserData)
{
	Modes::None();

	if (pCore->Orbwalker->IsModeActive(OrbwalkingMode::LaneClear))
		Modes::LaneClear();

	else if (pCore->Orbwalker->IsModeActive(OrbwalkingMode::LastHit))
		Modes::LastHit();

	else if (pCore->Orbwalker->IsModeActive(OrbwalkingMode::Combo))
		Modes::Combo();

	else if (pCore->Orbwalker->IsModeActive(OrbwalkingMode::Mixed))
		Modes::Harras();

	else if (pCore->Orbwalker->IsModeActive(OrbwalkingMode::Flee))
		Modes::Flee();
}

void Events::Draw(void* UserData)
{
	Draw::DrawGameScene();
}

void Events::Create()
{
	pSDK->EventHandler->RegisterCallback(CallbackEnum::Tick,		Tick);
	pSDK->EventHandler->RegisterCallback(CallbackEnum::Update,	Update);
	pSDK->EventHandler->RegisterCallback(CallbackEnum::Update,	Draw);

	SdkRegisterOnObjectCreate([](void* object, unsigned net_id, void*) -> bool
	{
		int team;
		SdkGetObjectTeamID(object, &team);
		
		const char* objName;
		SdkGetObjectName(object, &objName);
		std::string objString{ objName };

		if (team == 0)
		{
			if (objString.find("Q_reticle_self") != std::string::npos)
			{
				AxeList.push_back(object);
			}

			if (objString.find("Q_activation") != std::string::npos)
			{
				++DravenAxeCount;
			}

			if (objString.find("draven_spinning_buff_end_sound") != std::string::npos)
			{
				DravenAxeCount = 0;
			}
		}

		else if (Player.GetTeamID() == team)
		{
			if (objString.find("DravenR") != std::string::npos)
			{
				DravenRObject = object;
			}
		}

		return true;
	}, nullptr);

	SdkRegisterOnObjectDelete([](void* object, unsigned net_id, void*) -> bool
	{
		int team;
		SdkGetObjectTeamID(object, &team);

		const char* objName;
		SdkGetObjectName(object, &objName);
		std::string objString{ objName };

		if (team == 0)
		{
			if (objString.find("Q_reticle_self") != std::string::npos)
			{
				AxeList.erase(AxeList.begin());
				
				SDKVECTOR axePos;
				SdkGetObjectPosition(object, &axePos);

				if (Player.Distance(axePos) > 150)
					--DravenAxeCount;
			}
		}

		else if (Player.GetTeamID() == team)
		{
			if (objString.find("DravenR") != std::string::npos)
			{
				DravenRObject = nullptr;
				CastedRTarget = nullptr;
			}
		}

		return true;
	}, nullptr);
}
*/