/*
#pragma once

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
extern bool MiscAxeOptions;
extern bool MiscExpandedHitchance;

//Drawing menu variables
extern bool DravenDrawAxes;
extern bool DravenDrawAxeRange;

extern bool DravenDrawERange;

//Miscellaneous Menu Variables
extern int DravenEPredHitchance;
extern int DravenRPredHitchance;

extern bool DravenCatchAxesAttack;
extern bool DravenCatchAxesLaneClear;
extern bool DravenCatchAxesLastHit;
extern bool DravenCatchAxesCombo;
extern bool DravenCatchAxesMixed;

//Lasthit Spell menu Variables
extern bool UseQInLasthit;
extern bool LasthitSecondAxeOption;

//Harass Spell menu variables
extern bool UseQInHarass;
extern bool HarassSecondAxeOption;
extern bool UseWInHarass;

//Laneclear Spell menu variables
extern bool UseQInLaneclear;
extern bool LaneclearSecondAxeOption;

//Combo Spell menu Variables
extern bool UseQInCombo;
extern bool UseWInCombo;
extern bool UseEOnLowHealth;
extern bool UseEOnOutOfRange;

//Flee Spell menu Variables
extern bool UseWInFlee;
extern bool UseEInFlee;

//Auto Menu Variables
extern bool KillstealR;
extern float KillstealRRange;
extern bool KillstealE;
extern bool UseEOnMelee;
#pragma endregion

namespace Draven
{
	class Menu
	{
	public:
		static void __cdecl MenuDraw(void* UserData);
		static void Create();

		static void MenuLoadSettings();
		static void MenuSaveSettings();
	};
}

*/