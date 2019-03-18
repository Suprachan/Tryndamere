#include "Nocturne.h"
#include "Nocturne.Menu.h"

using namespace Tryndamere;

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
bool MiscSwordOptions;
bool MiscExpandedHitchance;

//Drawing menu variables
bool TryndamereDrawERange;
bool TryndamereDrawWRange;

//Miscellaneous Menu Variables

bool TrydamereR;

//Lasthit Spell menu Variables
bool UseEInLasthit;

//Harass Spell menu variables
bool UseEInHarass;
bool HarassWOption;
bool UseWInHarass;

//Laneclear Spell menu variables
bool UseQInLaneclear;
bool UseEInLaneclear;

//Combo Spell menu Variables
bool UseEInCombo;
bool UseWInCombo;
bool UseQOnLowHealth;
bool UseEOnOutOfRange;
bool UseROnLowHealth;

//Flee Spell menu Variables
bool UseEInFlee;

//Auto Menu Variables every comtilation get this worst and worst xD
bool KillstealE;
#pragma endregion


void __cdecl ::Tryndamere::Menu::MenuDraw(void* UserData)
{
	bool changed;

	SdkUiBeginTree("Drawing Options", &DrawingTreeExpanded);
	if (DrawingTreeExpanded)
	{
		SdkUiCheckbox("Draw E Range", &TryndamereDrawERange, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Draw W range", &TryndamereDrawWRange, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiEndTree();
	}


	SdkUiBeginTree("Auto Options", &AutoTreeExpanded);
	if (AutoTreeExpanded)
	{
		SdkUiBeginTree("Harass Options", &HarassSpellTreeExpanded);
		if (HarassSpellTreeExpanded)
		{
			SdkUiCheckbox("Harass with E", &UseEInHarass, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiCheckbox("Harass with W", &UseWInHarass, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}
			SdkUiEndTree();
		}

		SdkUiBeginTree("Kill Options", &LastHitSpellTreeExpanded);
		if (LastHitSpellTreeExpanded)
		{
			SdkUiCheckbox("Use E to Killsteal", &KillstealE, &changed);
			if (changed)
			{
				MenuSaveSettings();
			}

			SdkUiEndTree();
		}
		SdkUiEndTree();
	}

	SdkUiBeginTree("Combo Options", &ComboSpellTreeExpanded);
	if (ComboSpellTreeExpanded)
	{
		SdkUiCheckbox("Use Q in Combo", &UseQOnLowHealth, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Use W in Combo", &UseWInCombo, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Use E in Combo", &UseEInCombo, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		SdkUiCheckbox("Use R in Combo", &TrydamereR, &changed);
		if (changed)
		{
			MenuSaveSettings();
		}
		::Menu::SliderFloat("Use R HealthPercent", "Menu.HealthR", 25.0f, 0.0f, 100.0f);
	
		SdkUiEndTree();
	}


SdkUiBeginTree("Harass Option", &HarassSpellTreeExpanded);
if (HarassSpellTreeExpanded)
{
	SdkUiCheckbox("Use Q in Harass", &UseQInLaneclear, &changed);
	if (changed)
	{
		MenuSaveSettings();
	}
	SdkUiCheckbox("Use W in Harass", &UseWInHarass, &changed);
	if (changed)
	{
		MenuSaveSettings();
	}
	SdkUiCheckbox("Use E in Harass", &UseEInHarass, &changed);
	if (changed)
	{
		MenuSaveSettings();
	}
	SdkUiCheckbox("Use R in Harass", &TrydamereR, &changed);
	if (changed)
	{
		MenuSaveSettings();
	}
	SdkUiEndTree();
}

SdkUiBeginTree("Laneclear Option", &LaneclearSpellTreeExpanded);
if (LaneclearSpellTreeExpanded)
{

	SdkUiCheckbox("Use Q in Laneclear", &UseQInLaneclear, &changed);
	if (changed)
	{
		MenuSaveSettings();
	}
	SdkUiCheckbox("Use E in Laneclear", &UseEInLaneclear, &changed);
	if (changed)
	{
		MenuSaveSettings();
	}

	SdkUiEndTree();
}



const char* hitchanceList[] = { "Low", "Medium", "High", "Very High" };

SdkUiBeginTree("Miscellaneous Tree", &MiscExpanded);

}


void ::Tryndamere::Menu::MenuLoadSettings()
{
	//Drawing Options
;
	SdkGetSettingBool("TimmyAIO.Tryndamere.TryndamereDrawWRange", &TryndamereDrawWRange, true);

	SdkGetSettingBool("TimmyAIO.Tryndamere.TryndamereDrawERange", &TryndamereDrawERange, true);

	SdkGetSettingBool("TimmyAIO.Tryndamere.KillstealE", &KillstealE, true);


	//Harass Spell Options
	SdkGetSettingBool("TimmyAIO.Tryndamere.UseQOnLowHealth", &UseQOnLowHealth, true);
	SdkGetSettingBool("TimmyAIO.Tryndamere.UseEInHarass", &UseEInHarass, true);
	SdkGetSettingBool("TimmyAIO.Tryndamere.UseWInHarass", &UseWInHarass, true);
	SdkGetSettingBool("TimmyAIO.Tryndamere.UseROnLowHealth", &UseROnLowHealth, true);

	//Laneclear Spell Options
	SdkGetSettingBool("TimmyAIO.Tryndamere.UseQInLaneclear", &UseQInLaneclear, true);
	SdkGetSettingBool("TimmyAIO.Tryndamere.UseEInLaneclear", &UseEInLaneclear, true);

	//Combo Spell Options
	SdkGetSettingBool("TimmyAIO.Tryndamere.UseQOnLowHealth", &UseQOnLowHealth, true);
	SdkGetSettingBool("TimmyAIO.Tryndamere.UseWInCombo", &UseWInCombo, true);
	SdkGetSettingBool("TimmyAIO.Tryndamere.UseEOnOutOfRange", &UseEOnOutOfRange, true);
	SdkGetSettingBool("TimmyAIO.Tryndamere.UseQOnLowHealth", &UseQOnLowHealth, true);

	//Flee Spell Options
	SdkGetSettingBool("TimmyAIO.Tryndamere.UseEInFlee", &UseEInFlee, true);

	//Auto Options
	SdkGetSettingBool("TimmyAIO.Tryndamere.KillstealE", &KillstealE, true);

}

void ::Tryndamere::Menu::MenuSaveSettings()
{
	//Drawing Options
	;
	SdkGetSettingBool("TimmyAIO.Tryndamere.TryndamereDrawWRange", &TryndamereDrawWRange, true);

	SdkGetSettingBool("TimmyAIO.Tryndamere.TryndamereDrawERange", &TryndamereDrawERange, true);

	SdkGetSettingBool("TimmyAIO.Tryndamere.KillstealE", &KillstealE, true);


	//Harass Spell Options
	SdkSetSettingBool("TimmyAIO.Tryndamere.UseQOnLowHealth", &UseQOnLowHealth);
	SdkSetSettingBool("TimmyAIO.Tryndamere.UseEInHarass", &UseEInHarass);
	SdkSetSettingBool("TimmyAIO.Tryndamere.UseWInHarass", &UseWInHarass);
	SdkSetSettingBool("TimmyAIO.Tryndamere.UseROnLowHealth", &UseROnLowHealth);

	//Laneclear Spell Options
	SdkSetSettingBool("TimmyAIO.Tryndamere.UseQInLaneclear", &UseQInLaneclear);
	SdkSetSettingBool("TimmyAIO.Tryndamere.UseEInLaneclear", &UseEInLaneclear);

	//Combo Spell Options
	SdkSetSettingBool("TimmyAIO.Tryndamere.UseQOnLowHealth", &UseQOnLowHealth);
	SdkSetSettingBool("TimmyAIO.Tryndamere.UseWInCombo", &UseWInCombo);
	SdkSetSettingBool("TimmyAIO.Tryndamere.UseEOnOutOfRange", &UseEOnOutOfRange);
	SdkSetSettingBool("TimmyAIO.Tryndamere.UseQOnLowHealth", &UseQOnLowHealth);

	//Flee Spell Options
	SdkSetSettingBool("TimmyAIO.Tryndamere.UseEInFlee", UseEInFlee);

	//Auto Options
	SdkSetSettingBool("TimmyAIO.Tryndamere.KillstealE", KillstealE);

}

void ::Tryndamere::Menu::Create()
{
	MenuLoadSettings();
	SdkRegisterOverlayScene(MenuDraw, nullptr);
}

