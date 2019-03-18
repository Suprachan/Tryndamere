/*#include "KogMaw.h"
#include "KogMaw.Menu.h"
#include "KogMaw.Drawings.h"

using namespace KogMaw;

void ::KogMaw::Draw::DrawGameScene()
{
	if (KogMawDrawQRange && Q.IsReady())
	{
		SDKVECTOR localplayerPos = Player.GetPosition();
		SDKCOLOR color{ 0x00, 0x00, 0xFF, 0xFF };
		SDKVECTOR direction{ 100.f, 100.f, 100.f };

		SdkDrawCircle(&localplayerPos, 1175.f, &color, 3, &direction);
	}

	if (KogMawDrawWRange && W.IsReady())
	{
		const auto wSpell = Player.GetSpell(SPELL_W);
		const auto spellLevel = wSpell.Level - 1;
		const float bonusRange[] = {130.f, 150.f, 170.f, 190.f, 210.f};

		SDKVECTOR localplayerPos = Player.GetPosition();
		SDKCOLOR color{ 0x00, 0x00, 0xFF, 0xFF };
		SDKVECTOR direction{ 100.f, 100.f, 100.f };

		SdkDrawCircle(&localplayerPos, Player.GetTrueAttackRange() + bonusRange[spellLevel], &color, 3, &direction);
	}

	if (KogMawDrawERange && E.IsReady())
	{
		SDKVECTOR localplayerPos = Player.GetPosition();
		SDKCOLOR color{ 0x00, 0x00, 0xFF, 0xFF };
		SDKVECTOR direction{ 100.f, 100.f, 100.f };

		SdkDrawCircle(&localplayerPos, 1280.f, &color, 3, &direction);
	}

	if (KogMawDrawRRange && R.IsReady())
	{
		SDKVECTOR localplayerPos = Player.GetPosition();
		SDKCOLOR color{ 0x00, 0x00, 0xFF, 0xFF };
		SDKVECTOR direction{ 100.f, 100.f, 100.f };

		SdkDrawCircle(&localplayerPos, Player.GetSpell(SPELL_R).CastRange, &color, 3, &direction);
	}
}
*/