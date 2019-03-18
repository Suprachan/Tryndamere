#include "TimmyAIO.h"

#include "Manamanager.Menu.h"
#include "Windows.h"

#pragma region Manamanager Variables
//Manamanager Tree Expanded Variables
bool ManamanagerTree;

//Manamanager Combo Tree Expanded Variables
bool ManamanagerComboSpellManagementOptionsTree;
bool ManamanagerComboModeOptionsTree;
bool ManamanagerComboPrioritizeModeOptionsTree;
bool ManamanagerComboPercentageModeOptionsTree;

//Manamanager Harass Tree Expanded Variables
bool ManamanagerHarassSpellManagementOptionsTree;
bool ManamanagerHarassModeOptionsTree;
bool ManamanagerHarassPrioritizeModeOptionsTree;
bool ManamanagerHarassPercentageModeOptionsTree;

//Manamanager Laneclear Tree Expanded Variables
bool ManamanagerLaneclearSpellManagementOptionsTree;
bool ManamanagerLaneclearModeOptionsTree;
bool ManamanagerLaneclearPrioritizeModeOptionsTree;
bool ManamanagerLaneclearPercentageModeOptionsTree;

//Manamanager Orbmode selection
int ManamanagerOrbModeSelection;

//Manamanager Combo Spell Variables
int ManamanagerComboManageQSelection;
int ManamanagerComboManageWSelection;
int ManamanagerComboManageESelection;
int ManamanagerComboManageRSelection;

//Manamanager Combo Priority Varibles
int ManamanagerComboQPrioritySelection;
int ManamanagerComboWPrioritySelection;
int ManamanagerComboEPrioritySelection;
int ManamanagerComboRPrioritySelection;

//Manamanager Combo Percent Variables
float ManamanagerComboQMinPercentMana;
float ManamanagerComboWMinPercentMana;
float ManamanagerComboEMinPercentMana;
float ManamanagerComboRMinPercentMana;

//Manamanager Harass Spell Variables
int ManamanagerHarassManageQSelection;
int ManamanagerHarassManageWSelection;
int ManamanagerHarassManageESelection;
int ManamanagerHarassManageRSelection;

//Manamanager Harass Priority Varibles
int ManamanagerHarassQPrioritySelection;
int ManamanagerHarassWPrioritySelection;
int ManamanagerHarassEPrioritySelection;
int ManamanagerHarassRPrioritySelection;

//Manamanager Harass Percent Variables
float ManamanagerHarassQMinPercentMana;
float ManamanagerHarassWMinPercentMana;
float ManamanagerHarassEMinPercentMana;
float ManamanagerHarassRMinPercentMana;

//Manamanager Laneclear Spell Variables
int ManamanagerLaneclearManageQSelection;
int ManamanagerLaneclearManageWSelection;
int ManamanagerLaneclearManageESelection;
int ManamanagerLaneclearManageRSelection;

//Manamanager Laneclear Priority Varibles
int ManamanagerLaneclearQPrioritySelection;
int ManamanagerLaneclearWPrioritySelection;
int ManamanagerLaneclearEPrioritySelection;
int ManamanagerLaneclearRPrioritySelection;

//Manamanager Laneclear Percent Variables
float ManamanagerLaneclearQMinPercentMana;
float ManamanagerLaneclearWMinPercentMana;
float ManamanagerLaneclearEMinPercentMana;
float ManamanagerLaneclearRMinPercentMana;
#pragma endregion


void __cdecl ManamanagerMenu::MenuDraw(void* UserData)
{
	bool changed;
	static const char* orbModes[] = {"Combo", "Harass", "Lane Clear"};
	static const char* managerModes[] = {"Disabled", "Prioritize/Reserve Mode", "Percentage Mode"};
	static const char* prioritizeSpells[] = {"First", "Second", "Third", "Fourth"};

	SdkUiBeginTree("Manamanager Options", &ManamanagerTree);
	if (ManamanagerTree)
	{
		SdkUiText("Orbwalker Mode:");
		SdkUiForceOnSameLine();
		SdkUiCombo(" ", &ManamanagerOrbModeSelection, orbModes, RTL_NUMBER_OF(orbModes), nullptr);

		if (ManamanagerOrbModeSelection == 0)
		{
			SdkUiBeginTree("Combo Spell options", &ManamanagerComboSpellManagementOptionsTree);
			if (ManamanagerComboSpellManagementOptionsTree)
			{
				SdkUiText("Manage Q:");
				SdkUiForceOnSameLine();
				SdkUiCombo(" ", &ManamanagerComboManageQSelection, managerModes, RTL_NUMBER_OF(managerModes), &changed);
				if (changed)
				{
					MenuSaveSettings();
				}
				SdkUiText("Manage W:");
				SdkUiForceOnSameLine();
				SdkUiCombo("  ", &ManamanagerComboManageWSelection, managerModes, RTL_NUMBER_OF(managerModes), &changed);
				if (changed)
				{
					MenuSaveSettings();
				}
				SdkUiText("Manage E:");
				SdkUiForceOnSameLine();
				SdkUiCombo("   ", &ManamanagerComboManageESelection, managerModes, RTL_NUMBER_OF(managerModes), &changed);
				if (changed)
				{
					MenuSaveSettings();
				}
				SdkUiText("Manage R:");
				SdkUiForceOnSameLine();
				SdkUiCombo("    ", &ManamanagerComboManageRSelection, managerModes, RTL_NUMBER_OF(managerModes), &changed);
				if (changed)
				{
					MenuSaveSettings();
				}
				SdkUiEndTree();
			}
			SdkUiBeginTree("Combo Mode Options", &ManamanagerComboModeOptionsTree);
			if (ManamanagerComboModeOptionsTree)
			{
				SdkUiBeginTree("Combo Prioritize Options", &ManamanagerComboPrioritizeModeOptionsTree);
				if (ManamanagerComboPrioritizeModeOptionsTree)
				{
					if (ManamanagerComboManageQSelection == 1)
					{
						SdkUiText("Q Priority:");
						SdkUiForceOnSameLine();
						SdkUiCombo(" ", &ManamanagerComboQPrioritySelection, prioritizeSpells, RTL_NUMBER_OF(prioritizeSpells), &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerComboManageWSelection == 1)
					{
						SdkUiText("W Priority:");
						SdkUiForceOnSameLine();
						SdkUiCombo("  ", &ManamanagerComboWPrioritySelection, prioritizeSpells, RTL_NUMBER_OF(prioritizeSpells), &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerComboManageESelection == 1)
					{
						SdkUiText("E Priority:");
						SdkUiForceOnSameLine();
						SdkUiCombo("   ", &ManamanagerComboEPrioritySelection, prioritizeSpells, RTL_NUMBER_OF(prioritizeSpells), &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerComboManageRSelection == 1)
					{
						SdkUiText("R Priority:");
						SdkUiForceOnSameLine();
						SdkUiCombo("    ", &ManamanagerComboRPrioritySelection, prioritizeSpells, RTL_NUMBER_OF(prioritizeSpells), &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}
					SdkUiEndTree();
				}
				SdkUiBeginTree("Combo Percentage Options", &ManamanagerComboPercentageModeOptionsTree);
				if (ManamanagerComboPercentageModeOptionsTree)
				{
					if (ManamanagerComboManageQSelection == 2)
					{
						SdkUiText("Q Min Percent:");
						SdkUiForceOnSameLine();
						SdkUiDragFloat(" ", &ManamanagerComboQMinPercentMana, 0.f, 100.f, "%.f", &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerComboManageWSelection == 2)
					{
						SdkUiText("W Min Percent:");
						SdkUiForceOnSameLine();
						SdkUiDragFloat("  ", &ManamanagerComboWMinPercentMana, 0.f, 100.f, "%.f", &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerComboManageESelection == 2)
					{
						SdkUiText("E Min Percent:");
						SdkUiForceOnSameLine();
						SdkUiDragFloat("   ", &ManamanagerComboEMinPercentMana, 0.f, 100.f, "%.f", &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerComboManageRSelection == 2)
					{
						SdkUiText("R Min Percent:");
						SdkUiForceOnSameLine();
						SdkUiDragFloat("    ", &ManamanagerComboRMinPercentMana, 0.f, 100.f, "%.f", &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}
					SdkUiEndTree();
				}
				SdkUiEndTree();
			}
		}

		if (ManamanagerOrbModeSelection == 1)
		{
			SdkUiBeginTree("Harass Spell options", &ManamanagerHarassSpellManagementOptionsTree);
			if (ManamanagerHarassSpellManagementOptionsTree)
			{
				SdkUiText("Manage Q:");
				SdkUiForceOnSameLine();
				SdkUiCombo(" ", &ManamanagerHarassManageQSelection, managerModes, RTL_NUMBER_OF(managerModes), &changed);
				if (changed)
				{
					MenuSaveSettings();
				}
				SdkUiText("Manage W:");
				SdkUiForceOnSameLine();
				SdkUiCombo("  ", &ManamanagerHarassManageWSelection, managerModes, RTL_NUMBER_OF(managerModes), &changed);
				if (changed)
				{
					MenuSaveSettings();
				}
				SdkUiText("Manage E:");
				SdkUiForceOnSameLine();
				SdkUiCombo("   ", &ManamanagerHarassManageESelection, managerModes, RTL_NUMBER_OF(managerModes), &changed);
				if (changed)
				{
					MenuSaveSettings();
				}
				SdkUiText("Manage R:");
				SdkUiForceOnSameLine();
				SdkUiCombo("    ", &ManamanagerHarassManageRSelection, managerModes, RTL_NUMBER_OF(managerModes), &changed);
				if (changed)
				{
					MenuSaveSettings();
				}
				SdkUiEndTree();
			}
			SdkUiBeginTree("Harass Mode Options", &ManamanagerHarassModeOptionsTree);
			if (ManamanagerHarassModeOptionsTree)
			{
				SdkUiBeginTree("Harass Prioritize Options", &ManamanagerHarassPrioritizeModeOptionsTree);
				if (ManamanagerHarassPrioritizeModeOptionsTree)
				{
					if (ManamanagerHarassManageQSelection == 1)
					{
						SdkUiText("Q Priority:");
						SdkUiForceOnSameLine();
						SdkUiCombo(" ", &ManamanagerHarassQPrioritySelection, prioritizeSpells, RTL_NUMBER_OF(prioritizeSpells), &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerHarassManageWSelection == 1)
					{
						SdkUiText("W Priority:");
						SdkUiForceOnSameLine();
						SdkUiCombo("  ", &ManamanagerHarassWPrioritySelection, prioritizeSpells, RTL_NUMBER_OF(prioritizeSpells), &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerHarassManageESelection == 1)
					{
						SdkUiText("E Priority:");
						SdkUiForceOnSameLine();
						SdkUiCombo("   ", &ManamanagerHarassEPrioritySelection, prioritizeSpells, RTL_NUMBER_OF(prioritizeSpells), &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerHarassManageRSelection == 1)
					{
						SdkUiText("R Priority:");
						SdkUiForceOnSameLine();
						SdkUiCombo("    ", &ManamanagerHarassRPrioritySelection, prioritizeSpells, RTL_NUMBER_OF(prioritizeSpells), &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}
					SdkUiEndTree();
				}
				SdkUiBeginTree("Harass Percentage Options", &ManamanagerHarassPercentageModeOptionsTree);
				if (ManamanagerHarassPercentageModeOptionsTree)
				{
					if (ManamanagerHarassManageQSelection == 2)
					{
						SdkUiText("Q Min Percent:");
						SdkUiForceOnSameLine();
						SdkUiDragFloat(" ", &ManamanagerHarassQMinPercentMana, 0.f, 100.f, "%.f", &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerHarassManageWSelection == 2)
					{
						SdkUiText("W Min Percent:");
						SdkUiForceOnSameLine();
						SdkUiDragFloat("  ", &ManamanagerHarassWMinPercentMana, 0.f, 100.f, "%.f", &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerHarassManageESelection == 2)
					{
						SdkUiText("E Min Percent:");
						SdkUiForceOnSameLine();
						SdkUiDragFloat("   ", &ManamanagerHarassEMinPercentMana, 0.f, 100.f, "%.f", &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerHarassManageRSelection == 2)
					{
						SdkUiText("R Min Percent:");
						SdkUiForceOnSameLine();
						SdkUiDragFloat("    ", &ManamanagerHarassRMinPercentMana, 0.f, 100.f, "%.f", &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}
					SdkUiEndTree();
				}
				SdkUiEndTree();
			}
		}

		if (ManamanagerOrbModeSelection == 2)
		{
			SdkUiBeginTree("Lane Clear Spell options", &ManamanagerLaneclearSpellManagementOptionsTree);
			if (ManamanagerLaneclearSpellManagementOptionsTree)
			{
				SdkUiText("Manage Q:");
				SdkUiForceOnSameLine();
				SdkUiCombo(" ", &ManamanagerLaneclearManageQSelection, managerModes, RTL_NUMBER_OF(managerModes), &changed);
				if (changed)
				{
					MenuSaveSettings();
				}
				SdkUiText("Manage W:");
				SdkUiForceOnSameLine();
				SdkUiCombo("  ", &ManamanagerLaneclearManageWSelection, managerModes, RTL_NUMBER_OF(managerModes), &changed);
				if (changed)
				{
					MenuSaveSettings();
				}
				SdkUiText("Manage E:");
				SdkUiForceOnSameLine();
				SdkUiCombo("   ", &ManamanagerLaneclearManageESelection, managerModes, RTL_NUMBER_OF(managerModes), &changed);
				if (changed)
				{
					MenuSaveSettings();
				}
				SdkUiText("Manage R:");
				SdkUiForceOnSameLine();
				SdkUiCombo("    ", &ManamanagerLaneclearManageRSelection, managerModes, RTL_NUMBER_OF(managerModes), &changed);
				if (changed)
				{
					MenuSaveSettings();
				}
				SdkUiEndTree();
			}
			SdkUiBeginTree("Lane Clear Mode Options", &ManamanagerLaneclearModeOptionsTree);
			if (ManamanagerLaneclearModeOptionsTree)
			{
				SdkUiBeginTree("Lane Clear Prioritize Options", &ManamanagerLaneclearPrioritizeModeOptionsTree);
				if (ManamanagerLaneclearPrioritizeModeOptionsTree)
				{
					if (ManamanagerLaneclearManageQSelection == 1)
					{
						SdkUiText("Q Priority:");
						SdkUiForceOnSameLine();
						SdkUiCombo(" ", &ManamanagerLaneclearQPrioritySelection, prioritizeSpells, RTL_NUMBER_OF(prioritizeSpells), &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerLaneclearManageWSelection == 1)
					{
						SdkUiText("W Priority:");
						SdkUiForceOnSameLine();
						SdkUiCombo("  ", &ManamanagerLaneclearWPrioritySelection, prioritizeSpells, RTL_NUMBER_OF(prioritizeSpells), &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerLaneclearManageESelection == 1)
					{
						SdkUiText("E Priority:");
						SdkUiForceOnSameLine();
						SdkUiCombo("   ", &ManamanagerLaneclearEPrioritySelection, prioritizeSpells, RTL_NUMBER_OF(prioritizeSpells), &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerLaneclearManageRSelection == 1)
					{
						SdkUiText("R Priority:");
						SdkUiForceOnSameLine();
						SdkUiCombo("    ", &ManamanagerLaneclearRPrioritySelection, prioritizeSpells, RTL_NUMBER_OF(prioritizeSpells), &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}
					SdkUiEndTree();
				}
				SdkUiBeginTree("Lane Clear Percentage Options", &ManamanagerLaneclearPercentageModeOptionsTree);
				if (ManamanagerLaneclearPercentageModeOptionsTree)
				{
					if (ManamanagerLaneclearManageQSelection == 2)
					{
						SdkUiText("Q Min Percent:");
						SdkUiForceOnSameLine();
						SdkUiDragFloat(" ", &ManamanagerLaneclearQMinPercentMana, 0.f, 100.f, "%.f", &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerLaneclearManageWSelection == 2)
					{
						SdkUiText("W Min Percent:");
						SdkUiForceOnSameLine();
						SdkUiDragFloat("  ", &ManamanagerLaneclearWMinPercentMana, 0.f, 100.f, "%.f", &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerLaneclearManageESelection == 2)
					{
						SdkUiText("E Min Percent:");
						SdkUiForceOnSameLine();
						SdkUiDragFloat("   ", &ManamanagerLaneclearEMinPercentMana, 0.f, 100.f, "%.f", &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}

					if (ManamanagerLaneclearManageRSelection == 2)
					{
						SdkUiText("R Min Percent:");
						SdkUiForceOnSameLine();
						SdkUiDragFloat("    ", &ManamanagerLaneclearRMinPercentMana, 0.f, 100.f, "%.f", &changed);
						if (changed)
						{
							MenuSaveSettings();
						}
					}
					SdkUiEndTree();
				}
				SdkUiEndTree();
			}
		}
		SdkUiEndTree();
	}
}

void ManamanagerMenu::MenuSaveSettings()
{
	const auto heroName = Player.GetCharName();
	char output[128];

#pragma region Combo Options
	//Manamanager Combo Spell Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboManageQSelection", heroName);
	SdkSetSettingNumber(output, ManamanagerComboManageQSelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboManageWSelection", heroName);
	SdkSetSettingNumber(output, ManamanagerComboManageWSelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboManageESelection", heroName);
	SdkSetSettingNumber(output, ManamanagerComboManageESelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboManageRSelection", heroName);
	SdkSetSettingNumber(output, ManamanagerComboManageRSelection);

	//Manamanager Combo Priority Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboQPrioritySelection", heroName);
	SdkSetSettingNumber(output, ManamanagerComboQPrioritySelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboWPrioritySelection", heroName);
	SdkSetSettingNumber(output, ManamanagerComboWPrioritySelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboEPrioritySelection", heroName);
	SdkSetSettingNumber(output, ManamanagerComboEPrioritySelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboRPrioritySelection", heroName);
	SdkSetSettingNumber(output, ManamanagerComboRPrioritySelection);

	//Manamanager Combo Percent Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboQMinPercentMana", heroName);
	SdkSetSettingFloat(output, ManamanagerComboQMinPercentMana);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboWMinPercentMana", heroName);
	SdkSetSettingFloat(output, ManamanagerComboWMinPercentMana);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboEMinPercentMana", heroName);
	SdkSetSettingFloat(output, ManamanagerComboEMinPercentMana);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboRMinPercentMana", heroName);
	SdkSetSettingFloat(output, ManamanagerComboRMinPercentMana);
#pragma endregion

#pragma region Harass Options
	//Manamanager Harass Spell Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassManageQSelection", heroName);
	SdkSetSettingNumber(output, ManamanagerHarassManageQSelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassManageWSelection", heroName);
	SdkSetSettingNumber(output, ManamanagerHarassManageWSelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassManageESelection", heroName);
	SdkSetSettingNumber(output, ManamanagerHarassManageESelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassManageRSelection", heroName);
	SdkSetSettingNumber(output, ManamanagerHarassManageRSelection);

	//Manamanager Harass Priority Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassQPrioritySelection", heroName);
	SdkSetSettingNumber(output, ManamanagerHarassQPrioritySelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassWPrioritySelection", heroName);
	SdkSetSettingNumber(output, ManamanagerHarassWPrioritySelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassEPrioritySelection", heroName);
	SdkSetSettingNumber(output, ManamanagerHarassEPrioritySelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassRPrioritySelection", heroName);
	SdkSetSettingNumber(output, ManamanagerHarassRPrioritySelection);

	//Manamanager Harass Percent Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassQMinPercentMana", heroName);
	SdkSetSettingFloat(output, ManamanagerHarassQMinPercentMana);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassWMinPercentMana", heroName);
	SdkSetSettingFloat(output, ManamanagerHarassWMinPercentMana);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassEMinPercentMana", heroName);
	SdkSetSettingFloat(output, ManamanagerHarassEMinPercentMana);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassRMinPercentMana", heroName);
	SdkSetSettingFloat(output, ManamanagerHarassRMinPercentMana);
#pragma endregion

#pragma region Laneclear Options
	//Manamanager Laneclear Spell Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearManageQSelection", heroName);
	SdkSetSettingNumber(output, ManamanagerLaneclearManageQSelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearManageWSelection", heroName);
	SdkSetSettingNumber(output, ManamanagerLaneclearManageWSelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearManageESelection", heroName);
	SdkSetSettingNumber(output, ManamanagerLaneclearManageESelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearManageRSelection", heroName);
	SdkSetSettingNumber(output, ManamanagerLaneclearManageRSelection);

	//Manamanager Laneclear Priority Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearQPrioritySelection", heroName);
	SdkSetSettingNumber(output, ManamanagerLaneclearQPrioritySelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearWPrioritySelection", heroName);
	SdkSetSettingNumber(output, ManamanagerLaneclearWPrioritySelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearEPrioritySelection", heroName);
	SdkSetSettingNumber(output, ManamanagerLaneclearEPrioritySelection);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearRPrioritySelection", heroName);
	SdkSetSettingNumber(output, ManamanagerLaneclearRPrioritySelection);

	//Manamanager Laneclear Percent Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearQMinPercentMana", heroName);
	SdkSetSettingFloat(output, ManamanagerLaneclearQMinPercentMana);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearWMinPercentMana", heroName);
	SdkSetSettingFloat(output, ManamanagerLaneclearWMinPercentMana);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearEMinPercentMana", heroName);
	SdkSetSettingFloat(output, ManamanagerLaneclearEMinPercentMana);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearRMinPercentMana", heroName);
	SdkSetSettingFloat(output, ManamanagerLaneclearRMinPercentMana);
#pragma endregion

}

void ManamanagerMenu::MenuLoadSettings()
{
	const auto heroName = Player.GetCharName();
	char output[128];

#pragma region Combo Options
	//Manamanager Combo Spell Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboManageQSelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerComboManageQSelection, 0);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboManageWSelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerComboManageWSelection, 0);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboManageESelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerComboManageESelection, 0);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboManageRSelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerComboManageRSelection, 0);

	//Manamanager Combo Priority Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboQPrioritySelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerComboQPrioritySelection, 0);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboWPrioritySelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerComboWPrioritySelection, 1);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboEPrioritySelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerComboEPrioritySelection, 2);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboRPrioritySelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerComboRPrioritySelection, 3);

	//Manamanager Combo Percent Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboQMinPercentMana", heroName);
	SdkGetSettingFloat(output, &ManamanagerComboQMinPercentMana, 50.f);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboWMinPercentMana", heroName);
	SdkGetSettingFloat(output, &ManamanagerComboWMinPercentMana, 50.f);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboEMinPercentMana", heroName);
	SdkGetSettingFloat(output, &ManamanagerComboEMinPercentMana, 50.f);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerComboRMinPercentMana", heroName);
	SdkGetSettingFloat(output, &ManamanagerComboRMinPercentMana, 50.f);
#pragma endregion

#pragma region Harass Options
	//Manamanager Harass Spell Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassManageQSelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerHarassManageQSelection, 0);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassManageWSelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerHarassManageWSelection, 0);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassManageESelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerHarassManageESelection, 0);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassManageRSelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerHarassManageRSelection, 0);

	//Manamanager Priority Spell Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassQPrioritySelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerHarassQPrioritySelection, 0);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassWPrioritySelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerHarassWPrioritySelection, 1);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassEPrioritySelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerHarassEPrioritySelection, 2);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassRPrioritySelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerHarassRPrioritySelection, 3);

	//Manamanager Harass Percent Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassQMinPercentMana", heroName);
	SdkGetSettingFloat(output, &ManamanagerHarassQMinPercentMana, 50.f);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassWMinPercentMana", heroName);
	SdkGetSettingFloat(output, &ManamanagerHarassWMinPercentMana, 50.f);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassEMinPercentMana", heroName);
	SdkGetSettingFloat(output, &ManamanagerHarassEMinPercentMana, 50.f);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerHarassRMinPercentMana", heroName);
	SdkGetSettingFloat(output, &ManamanagerHarassRMinPercentMana, 50.f);
#pragma endregion

#pragma region Laneclear Options
	//Manamanager Laneclear Spell Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearManageQSelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerLaneclearManageQSelection, 0);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearManageWSelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerLaneclearManageWSelection, 0);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearManageESelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerLaneclearManageESelection, 0);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearManageRSelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerLaneclearManageRSelection, 0);

	//Manamanager Laneclear Priority Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearQPrioritySelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerLaneclearQPrioritySelection, 0);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearWPrioritySelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerLaneclearWPrioritySelection, 1);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearEPrioritySelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerLaneclearEPrioritySelection, 2);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearRPrioritySelection", heroName);
	SdkGetSettingNumber(output, &ManamanagerLaneclearRPrioritySelection, 3);

	//Manamanager Laneclear Percent Options
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearQMinPercentMana", heroName);
	SdkGetSettingFloat(output, &ManamanagerLaneclearQMinPercentMana, 50.f);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearWMinPercentMana", heroName);
	SdkGetSettingFloat(output, &ManamanagerLaneclearWMinPercentMana, 50.f);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearEMinPercentMana", heroName);
	SdkGetSettingFloat(output, &ManamanagerLaneclearEMinPercentMana, 50.f);
	sprintf_s(output, "TimmyAIOManamanager.%s.ManamanagerLaneclearRMinPercentMana", heroName);
	SdkGetSettingFloat(output, &ManamanagerLaneclearRMinPercentMana, 50.f);
#pragma endregion
}

void ManamanagerMenu::Create()
{
	MenuLoadSettings();
	SdkRegisterOverlayScene(MenuDraw, nullptr);
}