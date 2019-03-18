#pragma once
#pragma region Menu Variables

#pragma region Menu Variables
//Menu tree variables
extern bool DrawingTreeExpanded;
extern bool ComboSpellTreeExpanded;
extern bool LastHitSpellTreeExpanded;
extern bool HarassSpellTreeExpanded;
extern bool LaneclearSpellTreeExpanded;
extern bool FleeSpellTreeExpanded;
extern bool AutoTreeExpanded;
extern bool MiscExpanded;
extern bool MiscSwordOptions;
extern bool MiscExpandedHitchance;

//Drawing menu variables
extern bool TryndamereDrawERange;
extern bool TryndamereDrawWRange; //i know what to do, thats not the problem, those variables are registred somewhere else

//Miscellaneous Menu Variables
extern int  TryndamereEPredHitchance;


extern bool TrydamereR;

//Lasthit Spell menu Variables
extern bool UseEInLasthit;

//Harass Spell menu variables
extern bool UseEInHarass;
extern bool HarassWOption;
extern bool UseWInHarass;

//Laneclear Spell menu variables
extern bool UseQInLaneclear;
extern bool UseEInLaneclear;

//Combo Spell menu Variables
extern bool UseEInCombo;
extern bool UseWInCombo;
extern bool UseQOnLowHealth;
extern bool UseEOnOutOfRange;
extern bool UseROnLowHealth;

//Flee Spell menu Variables
extern bool UseEInFlee;

//Auto Menu Variables
extern bool KillstealE;
#pragma endregion

namespace Tryndamere
{

	class Menu

	{
	public:
		static void __cdecl MenuDraw(void* UserData);
		static void Create();
		static void SliderFloat();
		static void MenuLoadSettings();
		static void MenuSaveSettings();
	};
}

	