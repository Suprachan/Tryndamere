#pragma once

#pragma region Manamanager Variables
//Manamanager Tree Expanded Variables
extern bool ManamanagerTree;

//Manamanager Combo Tree Expanded Variables
extern bool ManamanagerComboSpellManagementOptionsTree;
extern bool ManamanagerComboModeOptionsTree;
extern bool ManamanagerComboPrioritizeModeOptionsTree;
extern bool ManamanagerComboPercentageModeOptionsTree;

//Manamanager Harass Tree Expanded Variables
extern bool ManamanagerHarassSpellManagementOptionsTree;
extern bool ManamanagerHarassModeOptionsTree;
extern bool ManamanagerHarassPrioritizeModeOptionsTree;
extern bool ManamanagerHarassPercentageModeOptionsTree;

//Manamanager Laneclear Tree Expanded Variables
extern bool ManamanagerLaneclearSpellManagementOptionsTree;
extern bool ManamanagerLaneclearModeOptionsTree;
extern bool ManamanagerLaneclearPrioritizeModeOptionsTree;
extern bool ManamanagerLaneclearPercentageModeOptionsTree;

//Manamanager Orbmode selection
extern int ManamanagerOrbModeSelection;

//Manamanager Combo Spell Variables
extern int ManamanagerComboManageQSelection;
extern int ManamanagerComboManageWSelection;
extern int ManamanagerComboManageESelection;
extern int ManamanagerComboManageRSelection;

//Manamanager Combo Priority Varibles
extern int ManamanagerComboQPrioritySelection;
extern int ManamanagerComboWPrioritySelection;
extern int ManamanagerComboEPrioritySelection;
extern int ManamanagerComboRPrioritySelection;

//Manamanager Combo Percent Variables
extern float ManamanagerComboQMinPercentMana;
extern float ManamanagerComboWMinPercentMana;
extern float ManamanagerComboEMinPercentMana;
extern float ManamanagerComboRMinPercentMana;

//Manamanager Harass Spell Variables
extern int ManamanagerHarassManageQSelection;
extern int ManamanagerHarassManageWSelection;
extern int ManamanagerHarassManageESelection;
extern int ManamanagerHarassManageRSelection;

//Manamanager Harass Priority Varibles
extern int ManamanagerHarassQPrioritySelection;
extern int ManamanagerHarassWPrioritySelection;
extern int ManamanagerHarassEPrioritySelection;
extern int ManamanagerHarassRPrioritySelection;

//Manamanager Harass Percent Variables
extern float ManamanagerHarassQMinPercentMana;
extern float ManamanagerHarassWMinPercentMana;
extern float ManamanagerHarassEMinPercentMana;
extern float ManamanagerHarassRMinPercentMana;

//Manamanager Laneclear Spell Variables
extern int ManamanagerLaneclearManageQSelection;
extern int ManamanagerLaneclearManageWSelection;
extern int ManamanagerLaneclearManageESelection;
extern int ManamanagerLaneclearManageRSelection;

//Manamanager Laneclear Priority Varibles
extern int ManamanagerLaneclearQPrioritySelection;
extern int ManamanagerLaneclearWPrioritySelection;
extern int ManamanagerLaneclearEPrioritySelection;
extern int ManamanagerLaneclearRPrioritySelection;

//Manamanager Laneclear Percent Variables
extern float ManamanagerLaneclearQMinPercentMana;
extern float ManamanagerLaneclearWMinPercentMana;
extern float ManamanagerLaneclearEMinPercentMana;
extern float ManamanagerLaneclearRMinPercentMana;
#pragma endregion

class ManamanagerMenu
{
public:
	static void __cdecl MenuDraw(void* UserData);
	static void Create();

	static void MenuLoadSettings();
	static void MenuSaveSettings();
};

