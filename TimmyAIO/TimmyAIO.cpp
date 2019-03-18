
// TimmyAIO.cpp : Defines the exported functions for the DLL application.
//
#include "TimmyAIO.h"
#include "Nocturne.h"

///This gets called once, at load
void MyTemplateClass::Init() 
{
#pragma region RegisterCallbacks

#pragma endregion

	const auto heroName = Player.GetCharName();

	if (!strcmp(heroName, "Tryndamere"))
	{
		Tryndamere::Tryndamere::Create();
		SdkDisplayChatLocalPlayer("Tryndamere Loaded", CHAT_FLAG_TURQUOISE);
	}
}

//th