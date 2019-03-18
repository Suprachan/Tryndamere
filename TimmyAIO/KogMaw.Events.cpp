/*#include "KogMaw.h"
#include "KogMaw.Events.h"
#include "KogMaw.Modes.h"
#include "KogMaw.Drawings.h"

using namespace KogMaw;

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
	pSDK->EventHandler->RegisterCallback(CallbackEnum::Update,	Draw);
	pSDK->EventHandler->RegisterCallback(CallbackEnum::Tick,		Tick);
}
*/