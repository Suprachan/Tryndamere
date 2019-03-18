#include "Nocturne.h"
#include "Nocturne.Events.h"
#include "Nocturne.Modes.h"
#include "Nocturne.Drawings.h"

using namespace Tryndamere;

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
		Modes::Mixed();

	else if (pCore->Orbwalker->IsModeActive(OrbwalkingMode::Flee))
		Modes::Flee();
}

void Events::Draw(void* UserData)
{
	Draw::DrawGameScene();
}

void Events::Create()
{
	pSDK->EventHandler->RegisterCallback(CallbackEnum::Tick,	Tick);
	pSDK->EventHandler->RegisterCallback(CallbackEnum::Update,	Draw);
}