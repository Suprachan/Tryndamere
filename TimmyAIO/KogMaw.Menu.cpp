/*
&#include "KogMaw.h"
#include "KogMaw.Menu.h"

using namespace KogMaw;

#pragma region KogMaw Menu Variables
//Tree variables
bool KogmawDrawingsTree;
bool KogMawAutoTree;
bool KogMawAutoHarassTree;
bool KogMAwAutoKillstealTree;
bool KogMawComboTree;
bool KogMawHarassTree;
bool KogMawLaneclearTree;
bool KogMawFleeTree;
bool MiscTree;
bool MiscTreeHitchance;

//Drawings Options
bool KogMawDrawQRange;
bool KogMawDrawWRange;
bool KogMawDrawERange;
bool KogMawDrawRRange;

//Auto Options
bool KogMawAutoQHarass;
bool KogMawAutoRHarass;
int KogMawAutoRHarassMaxStacks;

bool KogMawLasthitQ;

bool KogMawQKillSteal;
bool KogMawEKillSteal;
bool KogMawRKillSteal;

//Combo Options
bool KogMawComboUseQ;
bool KogMawComboUseW;
bool KogMawComboUseE;
bool KogMawComboUseR;
int KogMawComboMaxStacks;
bool KogMawCombo40Percent;

//Harass Options
bool KogMawHarassUseQ;
bool KogMawHarassUseW;
bool KogMawHarassUseR;
int KogMawHarassMaxStacks;

//Laneclear Options
bool KogMawLaneclearUseW;
bool KogMawLaneclearWTower;
bool KogMawLaneclearUseE;

//Flee Options
bool KogMawFleeUseE;

//Misc Options
int KogMawQPredHitchance;
int KogMawEPredHitchance;
int KogMawRPredHitchance;

#pragma endregion

void __cdecl ::KogMaw::Menu::MenuDraw(void* UserData)
{
	bool changed;

	SdkUiBeginTree("Drawing Options", &KogmawDrawingsTree);
	if (KogmawDrawingsTree)
	{
		SdkUiCheckbox("Draw Q range", &KogMawDrawQRange, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Draw W range", &KogMawDrawWRange, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Draw E range", &KogMawDrawERange, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Draw R range", &KogMawDrawRRange, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiEndTree();
	}

	SdkUiBeginTree("Auto Options", &KogMawAutoTree);
	if (KogMawAutoTree)
	{
		SdkUiBeginTree("Harass Options", &KogMawAutoHarassTree);
		if (KogMawAutoHarassTree)
		{
			SdkUiCheckbox("Harass with Q", &KogMawAutoQHarass, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiCheckbox("Harass with R", &KogMawAutoRHarass, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			if (KogMawAutoRHarass)
			{
				SdkUiInputNumber("R max mana stacks", &KogMawAutoRHarassMaxStacks, &changed);
				if (changed)
				{
					MenuSaveSettings();
				}
			}
			SdkUiEndTree();
		}

		SdkUiBeginTree("Kill Options", &KogMAwAutoKillstealTree);
		if (KogMAwAutoKillstealTree)
		{
			SdkUiCheckbox("Use Q to Killsteal", &KogMawQKillSteal, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiCheckbox("Use E to Killsteal", &KogMawEKillSteal, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiCheckbox("Use R to Killsteal", &KogMawRKillSteal, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiEndTree();
		}
		SdkUiEndTree();
	}

	SdkUiBeginTree("Combo Options", &KogMawComboTree);
	if (KogMawComboTree)
	{
		SdkUiCheckbox("Use Q in Combo", &KogMawComboUseQ, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Use W in Combo", &KogMawComboUseW, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Use E in Combo", &KogMawComboUseE, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Use R in Combo", &KogMawComboUseR, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		if (KogMawComboUseR)
		{
			SdkUiInputNumber("R max mana stacks", &KogMawComboMaxStacks, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiCheckbox("Only use R when target below 40 percent health", &KogMawCombo40Percent, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
		}
		SdkUiEndTree();
	}

	SdkUiBeginTree("Harass Option", &KogMawHarassTree);
	if (KogMawHarassTree)
	{
		SdkUiCheckbox("Use Q in Harass", &KogMawHarassUseQ, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Use W in Harass", &KogMawHarassUseW, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Use R in Harass", &KogMawHarassUseR, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		if (KogMawHarassUseR)
		{
			SdkUiInputNumber("R max mana stacks", &KogMawHarassMaxStacks, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
		}
		SdkUiEndTree();
	}

	SdkUiBeginTree("Laneclear Option", &KogMawLaneclearTree);
	if (KogMawLaneclearTree)
	{

		SdkUiCheckbox("Use W in Laneclear", &KogMawLaneclearUseW, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		if (KogMawLaneclearUseW)
		{
			SdkUiCheckbox("Laneclear W under tower", &KogMawLaneclearWTower, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
		}
		SdkUiCheckbox("Use E in Laneclear", &KogMawLaneclearUseE, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}

		SdkUiEndTree();
	}

	const char* hitchanceList[] = {"Low", "Medium", "High", "Very High"};

	SdkUiBeginTree("Miscellaneous Tree", &MiscTree);
	if (MiscTree)
	{
		SdkUiBeginTree("Hitchance Selector", &MiscTree);
		if (MiscTree)
		{
			SdkUiText("Q Hitchance:");
			SdkUiForceOnSameLine();
			SdkUiCombo(" ", &KogMawQPredHitchance, hitchanceList, RTL_NUMBER_OF(hitchanceList), &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiText("E Hitchance:");
			SdkUiForceOnSameLine();
			SdkUiCombo("  ", &KogMawEPredHitchance, hitchanceList, RTL_NUMBER_OF(hitchanceList), &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiText("R Hitchance:");
			SdkUiForceOnSameLine();
			SdkUiCombo("   ", &KogMawRPredHitchance, hitchanceList, RTL_NUMBER_OF(hitchanceList), &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiEndTree();
		}
		SdkUiEndTree();
	}
}

void ::KogMaw::Menu::MenuSaveSettings()
{
	//Drawings Options
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawDrawQRange", KogMawDrawQRange);
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawDrawWRange", KogMawDrawWRange);
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawDrawERange", KogMawDrawERange);
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawDrawRRange", KogMawDrawRRange);

	//Auto Options
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawAutoQHarass", KogMawAutoQHarass);
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawAutoRHarass", KogMawAutoRHarass);
	SdkSetSettingNumber("TimmyAIO.KogMaw.KogMawAutoRHarassMaxStacks", KogMawAutoRHarassMaxStacks);

	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawQKillSteal", KogMawQKillSteal);
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawEKillSteal", KogMawEKillSteal);
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawRKillSteal", KogMawRKillSteal);

	//Combo Options
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawComboUseQ", KogMawComboUseQ);
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawComboUseW", KogMawComboUseW);
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawComboUseE", KogMawComboUseE);
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawComboUseR", KogMawComboUseR);
	SdkSetSettingNumber("TimmyAIO.KogMaw.KogMawComboMaxStacks", KogMawComboMaxStacks);
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawCombo40Percent", KogMawCombo40Percent);

	//Harass Options
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawHarassUseQ", KogMawHarassUseQ);
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawHarassUseW", KogMawHarassUseW);
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawHarassUseR", KogMawHarassUseR);
	SdkSetSettingNumber("TimmyAIO.KogMaw.KogMawHarassMaxStacks", KogMawHarassMaxStacks);
	
	//Laneclear Options
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawLaneclearUseW", KogMawLaneclearUseW);
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawLaneclearWTower", KogMawLaneclearWTower);
	SdkSetSettingBool("TimmyAIO.KogMaw.KogMawLaneclearUseE", KogMawLaneclearUseE);

	//Miscellaneous Settings
	SdkSetSettingNumber("TimmyAIO.KogMaw.KogMawQPredHitchance", KogMawQPredHitchance);
	SdkSetSettingNumber("TimmyAIO.KogMaw.KogMawEPredHitchance", KogMawEPredHitchance);
	SdkSetSettingNumber("TimmyAIO.KogMaw.KogMawRPredHitchance", KogMawRPredHitchance);
}

void ::KogMaw::Menu::MenuLoadSettings()
{
	//Drawings Options
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawDrawQRange", &KogMawDrawQRange, true);
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawDrawWRange", &KogMawDrawWRange, true);
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawDrawERange", &KogMawDrawERange, true);
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawDrawRRange", &KogMawDrawRRange, true);

	//Auto Options
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawAutoQHarass", &KogMawAutoQHarass, true);
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawAutoRHarass", &KogMawAutoRHarass, true);
	SdkGetSettingNumber("TimmyAIO.KogMaw.KogMawAutoRHarassMaxStacks", &KogMawAutoRHarassMaxStacks, 2);

	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawQKillSteal", &KogMawQKillSteal, true);
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawEKillSteal", &KogMawEKillSteal, true);
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawRKillSteal", &KogMawRKillSteal, true);

	//Combo Options
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawComboUseQ", &KogMawComboUseQ, true);
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawComboUseW", &KogMawComboUseW, true);
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawComboUseE", &KogMawComboUseE, true);
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawComboUseR", &KogMawComboUseR, true);
	SdkGetSettingNumber("TimmyAIO.KogMaw.KogMawComboMaxStacks", &KogMawComboMaxStacks, 2);
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawCombo40Percent", &KogMawCombo40Percent, true);

	//Harass Options
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawHarassUseQ", &KogMawHarassUseQ, true);
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawHarassUseW", &KogMawHarassUseW, true);
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawHarassUseR", &KogMawHarassUseR, true);
	SdkGetSettingNumber("TimmyAIO.KogMaw.KogMawHarassMaxStacks", &KogMawHarassMaxStacks, 2);


	//Laneclear Options
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawLaneclearUseW", &KogMawLaneclearUseW, true);
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawLaneclearWTower", &KogMawLaneclearWTower, true);
	SdkGetSettingBool("TimmyAIO.KogMaw.KogMawLaneclearUseE", &KogMawLaneclearUseE, true);

	//Miscellaneous Settings
	SdkGetSettingNumber("TimmyAIO.KogMaw.KogMawQPredHitchance", &KogMawQPredHitchance, 2);
	SdkGetSettingNumber("TimmyAIO.KogMaw.KogMawEPredHitchance", &KogMawEPredHitchance, 2);
	SdkGetSettingNumber("TimmyAIO.KogMaw.KogMawRPredHitchance", &KogMawRPredHitchance, 2);
}

void ::KogMaw::Menu::Create()
{
	MenuLoadSettings();
	SdkRegisterOverlayScene(MenuDraw, nullptr);
}
*/