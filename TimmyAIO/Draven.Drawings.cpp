/*
#include "Draven.h"
#include "Draven.Menu.h"
#include "Draven.Drawings.h"

using namespace Draven;

void ::Draven::Draw::DrawGameScene()
{
	if (DravenDrawAxes)
	{
		if (!AxeList.empty())
		{
			SDKVECTOR axePos;
			SDKVECTOR direction{ 100.f, 100.f, 100.f };
			SDKCOLOR color{ 0x00, 0x00, 0xFF, 0xFF };

			for (auto axe: AxeList)
			{
				SdkGetObjectPosition(axe, &axePos);
				SdkDrawCircle(&axePos, 100.f, &color, 3, &direction);
			}
		}
	}

	if (DravenDrawAxeRange)
	{
		SDKVECTOR cursorPos = Renderer::MousePos();
		SDKCOLOR color{ 0x00, 0x00, 0xFF, 0xFF };
		SDKVECTOR direction{ 100.f, 100.f, 100.f };

		SdkDrawCircle(&cursorPos, AxeCatchRange, &color, 3, &direction);
	}

	if (DravenDrawERange && E.IsReady())
	{
		SDKVECTOR localplayerPos = Player.GetPosition();
		SDKCOLOR color{ 0x00, 0x00, 0xFF, 0xFF };
		SDKVECTOR direction{ 100.f, 100.f, 100.f };

		SdkDrawCircle(&localplayerPos, 1050.f, &color, 3, &direction);
	}
}
*/