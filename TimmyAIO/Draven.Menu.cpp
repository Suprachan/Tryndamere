/*
#include "Draven.h"

using namespace Draven;

#pragma region Menu Variables
//Menu tree variables
bool DrawingTreeExpanded;
bool ComboSpellTreeExpanded;
bool LastHitSpellTreeExpanded;
bool HarassSpellTreeExpanded;
bool LaneclearSpellTreeExpanded;
bool FleeSpellTreeExpanded;
bool AutoTreeExpanded;
bool MiscExpanded;
bool MiscAxeOptions;
bool MiscExpandedHitchance;

//Drawing Menu Variables
bool DravenDrawAxes;
bool DravenDrawAxeRange;

bool DravenDrawERange;

//Miscellaneous Menu Variables
int DravenEPredHitchance;
int DravenRPredHitchance;

bool DravenCatchAxesAttack;
bool DravenCatchAxesLaneClear;
bool DravenCatchAxesLastHit;
bool DravenCatchAxesCombo;
bool DravenCatchAxesMixed;

//Lasthit Spell menu variables
bool UseQInLasthit;
bool LasthitSecondAxeOption;

//Harass Spell menu variables
bool UseQInHarass;
bool HarassSecondAxeOption;
bool UseWInHarass;

//Laneclear Spell menu variables
bool UseQInLaneclear;
bool LaneclearSecondAxeOption;

//Combo Spell menu Variables
bool UseQInCombo;
bool UseWInCombo;
bool UseEOnLowHealth;
bool UseEOnOutOfRange;

//Flee Spell menu Variables
bool UseWInFlee;
bool UseEInFlee;

//Auto Menu Variables
bool KillstealR;
float KillstealRRange;
bool KillstealE;
bool UseEOnMelee;
#pragma endregion


void __cdecl ::Draven::Menu::MenuDraw(void* UserData)
{
	bool changed;

	SdkUiBeginTree("Drawing Options", &DrawingTreeExpanded);
	if (DrawingTreeExpanded)
	{
		SdkUiCheckbox("Draw On Draven Axes", &DravenDrawAxes, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Draw Draven Catch Range", &DravenDrawAxeRange, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Draw E range", &DravenDrawERange, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiEndTree();
	}

	SdkUiBeginTree("Combo Spell Options", &ComboSpellTreeExpanded);
	if (ComboSpellTreeExpanded)
	{
		SdkUiCheckbox("Q in combo mode", &UseQInCombo, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("W in combo mode", &UseWInCombo, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("E when draven is low health", &UseEOnLowHealth, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("E when Target is out of autoattackrange", &UseEOnOutOfRange, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiEndTree();
	}

	SdkUiBeginTree("Lasthit Spell Options", &LastHitSpellTreeExpanded);
	if (LastHitSpellTreeExpanded)
	{
		SdkUiCheckbox("Q in lasthit mode", &UseQInLasthit, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		if (UseQInLasthit)
		{
			SdkUiCheckbox("Use a second axe", &LasthitSecondAxeOption, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
		}
		SdkUiEndTree();
	}

	SdkUiBeginTree("Harass Spell Options", &HarassSpellTreeExpanded);
	if (HarassSpellTreeExpanded)
	{
		SdkUiCheckbox("Q in Harass mode", &UseQInHarass, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		if (UseQInHarass)
		{
			SdkUiCheckbox("Use a second axe", &HarassSecondAxeOption, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
		}
		SdkUiCheckbox("W in Harass mode", &UseWInHarass, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiEndTree();
	}

	SdkUiBeginTree("Laneclear Spell Options", &LaneclearSpellTreeExpanded);
	if (LaneclearSpellTreeExpanded)
	{
		SdkUiCheckbox("Q in Laneclear mode", &UseQInLaneclear, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		if (UseQInHarass)
		{
			SdkUiCheckbox("Use a second axe", &LaneclearSecondAxeOption, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
		}
		SdkUiEndTree();
	}

	SdkUiBeginTree("Flee Spell Options", &FleeSpellTreeExpanded);
	if (FleeSpellTreeExpanded)
	{
		SdkUiCheckbox("W in Flee mode", &UseWInFlee, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("E in Flee mode", &UseEInFlee, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiEndTree();
	}

	SdkUiBeginTree("Auto Options", &AutoTreeExpanded);
	if (AutoTreeExpanded)
	{
		SdkUiCheckbox("Killsteal with E", &KillstealE, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Auto E melee champions in melee range", &UseEOnMelee, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Killsteal with R", &KillstealR, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		if (KillstealR)
		{
			SdkUiInputFloat("Auto R range", &KillstealRRange, 0, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
		}
		SdkUiEndTree();
	}

	const char* hitchanceList[] = {"Low", "Medium", "High", "Very High"};

	SdkUiBeginTree("Miscellaneous Options", &MiscExpanded);
	if (MiscExpanded)
	{
		SdkUiBeginTree("Hitchance Options", &MiscExpandedHitchance);
		if (MiscExpandedHitchance)
		{
			SdkUiText("E Hitchance:");
			SdkUiForceOnSameLine();
			SdkUiCombo(" ", &DravenEPredHitchance, hitchanceList, RTL_NUMBER_OF(hitchanceList), &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiText("R Hitchance:");
			SdkUiForceOnSameLine();
			SdkUiCombo("  ", &DravenRPredHitchance, hitchanceList, RTL_NUMBER_OF(hitchanceList), &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiEndTree();
		}

		SdkUiBeginTree("Axe options", &MiscAxeOptions);
		if (MiscAxeOptions)
		{
			SdkUiCheckbox("AA in between catches", &DravenCatchAxesAttack, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiCheckbox("Catch Axes in LaneClear", &DravenCatchAxesLaneClear, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiCheckbox("Catch Axes in LastHit", &DravenCatchAxesLastHit, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiCheckbox("Catch Axes in combo", &DravenCatchAxesCombo, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiCheckbox("Catch Axes in Mixed", &DravenCatchAxesMixed, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiInputFloat("Axe Catch Range (Default: 600)", &AxeCatchRange, 0, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiEndTree();
		}
		SdkUiEndTree();
	}
}

void ::Draven::Menu::MenuLoadSettings()
{
	//Drawing Options
	SdkGetSettingBool("TimmyAIO.Draven.DrawOnAxe", &DravenDrawAxes, true);
	SdkGetSettingBool("TimmyAIO.Draven.DrawAxeRange", &DravenDrawAxeRange, true);

	SdkGetSettingBool("TimmyAIO.Draven.DravenDrawERange", &DravenDrawERange, true);
	
	//Misc Options
	SdkGetSettingBool("TimmyAIO.Draven.DravenCatchAxesAttack", &DravenCatchAxesAttack, true);
	SdkGetSettingBool("TimmyAIO.Draven.DravenCatchAxesLaneClear", &DravenCatchAxesLaneClear, true);
	SdkGetSettingBool("TimmyAIO.Draven.DravenCatchAxesLastHit", &DravenCatchAxesLastHit, true);
	SdkGetSettingBool("TimmyAIO.Draven.DravenCatchAxesCombo", &DravenCatchAxesCombo, true);
	SdkGetSettingBool("TimmyAIO.Draven.DravenCatchAxesMixed", &DravenCatchAxesMixed, true);
	SdkGetSettingFloat("TimmyAIO.Draven.AxeCatchRange", &AxeCatchRange, 600.f);

	SdkGetSettingNumber("TimmyAIO.Draven.DravenEPredHitchance", &DravenEPredHitchance, 2);
	SdkGetSettingNumber("TimmyAIO.Draven.DravenRPredHitchance", &DravenRPredHitchance, 2);

	//Lasthit Spell Options
	SdkGetSettingBool("TimmyAIO.Draven.UseQInLasthit", &UseQInLasthit, true);
	SdkGetSettingBool("TimmyAIO.Draven.LasthitSecondAxeOption", &LasthitSecondAxeOption, true);

	//Harass Spell Options
	SdkGetSettingBool("TimmyAIO.Draven.UseQInHarass", &UseQInHarass, true);
	SdkGetSettingBool("TimmyAIO.Draven.HarassSecondAxeOption", &HarassSecondAxeOption, true);
	SdkGetSettingBool("TimmyAIO.Draven.UseWInHarass", &UseWInHarass, true);

	//Laneclear Spell Options
	SdkGetSettingBool("TimmyAIO.Draven.UseQInLaneclear", &UseQInLaneclear, true);
	SdkGetSettingBool("TimmyAIO.Draven.LaneclearSecondAxeOption", &LaneclearSecondAxeOption, true);

	//Combo Spell Options
	SdkGetSettingBool("TimmyAIO.Draven.UseQInCombo", &UseQInCombo, true);
	SdkGetSettingBool("TimmyAIO.Draven.UseWInCombo", &UseWInCombo, true);
	SdkGetSettingBool("TimmyAIO.Draven.UseEOnOutOfRange", &UseEOnOutOfRange, true);
	SdkGetSettingBool("TimmyAIO.Draven.UseEOnLowHealth", &UseEOnLowHealth, true);

	//Flee Spell Options
	SdkGetSettingBool("TimmyAIO.Draven.UseWInFlee", &UseWInFlee, true);
	SdkGetSettingBool("TimmyAIO.Draven.UseEInFlee", &UseEInFlee, true);

	//Auto Options
	SdkGetSettingBool("TimmyAIO.Draven.RKillsteal", &KillstealR, true);
	SdkGetSettingFloat("TimmyAIO.Draven.RKillstealRange", &KillstealRRange, 1000.f);
	SdkGetSettingBool("TimmyAIO.Draven.EKillsteal", &KillstealE, true);
	SdkGetSettingBool("TimmyAIO.Draven.AutoEOnMelee", &UseEOnMelee, true);
}

void ::Draven::Menu::MenuSaveSettings()
{
	//Drawing Options
	SdkSetSettingBool("TimmyAIO.Draven.DrawOnAxe", DravenDrawAxes);
	SdkSetSettingBool("TimmyAIO.Draven.DrawAxeRange", DravenDrawAxeRange);

	SdkSetSettingBool("TimmyAIO.Draven.DravenDrawERange", DravenDrawERange);

	//Misc Options
	SdkSetSettingBool("TimmyAIO.Draven.DravenCatchAxesAttack", DravenCatchAxesAttack);
	SdkSetSettingBool("TimmyAIO.Draven.DravenCatchAxesLaneClear", DravenCatchAxesLaneClear);
	SdkSetSettingBool("TimmyAIO.Draven.DravenCatchAxesLastHit", DravenCatchAxesLastHit);
	SdkSetSettingBool("TimmyAIO.Draven.DravenCatchAxesCombo", DravenCatchAxesCombo);
	SdkSetSettingBool("TimmyAIO.Draven.DravenCatchAxesMixed", DravenCatchAxesMixed);
	SdkSetSettingFloat("TimmyAIO.Draven.AxeCatchRange", AxeCatchRange);

	SdkSetSettingNumber("TimmyAIO.Draven.DravenEPredHitchance", DravenEPredHitchance);
	SdkSetSettingNumber("TimmyAIO.Draven.DravenRPredHitchance", DravenRPredHitchance);

	//Lasthit Spell Options
	SdkSetSettingBool("TimmyAIO.Draven.UseQInLasthit", UseQInLasthit);
	SdkSetSettingBool("TimmyAIO.Draven.LasthitSecondAxeOption", LasthitSecondAxeOption);

	//Harass Spell Options
	SdkSetSettingBool("TimmyAIO.Draven.UseQInHarass", UseQInHarass);
	SdkSetSettingBool("TimmyAIO.Draven.HarassSecondAxeOption", HarassSecondAxeOption);
	SdkSetSettingBool("TimmyAIO.Draven.UseWInHarass", UseWInHarass);

	//Laneclear Spell Options
	SdkSetSettingBool("TimmyAIO.Draven.UseQInLaneclear", UseQInLaneclear);
	SdkSetSettingBool("TimmyAIO.Draven.LaneclearSecondAxeOption", LaneclearSecondAxeOption);

	//Combo Spell Options
	SdkSetSettingBool("TimmyAIO.Draven.UseQInCombo", UseQInCombo);
	SdkSetSettingBool("TimmyAIO.Draven.UseWInCombo", UseWInCombo);
	SdkSetSettingBool("TimmyAIO.Draven.UseEOnOutOfRange", UseEOnOutOfRange);
	SdkSetSettingBool("TimmyAIO.Draven.UseEOnLowHealth", UseEOnLowHealth);

	//Flee Spell Options
	SdkSetSettingBool("TimmyAIO.Draven.UseWInFlee", UseWInFlee);
	SdkSetSettingBool("TimmyAIO.Draven.UseEInFlee", UseEInFlee);

	//Auto Options
	SdkSetSettingBool("TimmyAIO.Draven.RKillsteal", KillstealR);
	SdkSetSettingFloat("TimmyAIO.Draven.RKillstealRange", KillstealRRange);
	SdkSetSettingBool("TimmyAIO.Draven.EKillsteal", KillstealE);
	SdkSetSettingBool("TimmyAIO.Draven.AutoEOnMelee", UseEOnMelee);
}
/*
void ::Draven::Menu::Create()
{
	MenuLoadSettings();
	SdkRegisterOverlayScene(MenuDraw, nullptr);
}
*/