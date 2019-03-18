#include "Nocturne.h"
#include "Nocturne.Menu.h"
#include "Nocturne.Drawings.h"

using namespace Tryndamere;

void ::Tryndamere::Draw::DrawGameScene()
{ 
	if (TryndamereDrawWRange && TryndanmereW.IsReady())
	{
		SDKVECTOR localplayerPos = Player.GetPosition();
		SDKCOLOR color{ 0x00, 0x00, 0xFF, 0xFF };
		SDKVECTOR direction{ 100.f, 100.f, 100.f };

		SdkDrawCircle(&localplayerPos, 850.f, &color, 4, &direction);
	}
	if (TryndamereDrawERange && TryndamereE.IsReady())
	{
		SDKVECTOR localplayerPos = Player.GetPosition();
		SDKCOLOR color{ 0x00, 0x00, 0xFF, 0xFF };
		SDKVECTOR direction{ 100.f, 100.f, 100.f };

		SdkDrawCircle(&localplayerPos, 660.f, &color, 3, &direction);
	}
}
//mylifeisshit.exe HAHAHAHAH, i do not understand your language lol  idk how to change it to english xD