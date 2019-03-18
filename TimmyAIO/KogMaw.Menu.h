/*#pragma once

#pragma region KogMaw Menu Variables
//Tree variables
extern bool KogmawDrawingsTree;
extern bool KogMawAutoTree;
extern bool KogMawAutoHarassTree;
extern bool KogMAwAutoKillstealTree;
extern bool KogMawComboTree;
extern bool KogMawHarassTree;
extern bool KogMawLaneclearTree;
extern bool KogMawFleeTree;
extern bool MiscTree;
extern bool MiscTreeHitchance;

//Drawings Options
extern bool KogMawDrawQRange;
extern bool KogMawDrawWRange;
extern bool KogMawDrawERange;
extern bool KogMawDrawRRange;

//Auto Options
extern bool KogMawAutoQHarass;
extern bool KogMawAutoRHarass;
extern int KogMawAutoRHarassMaxStacks;

extern bool KogMawLasthitQ;

extern bool KogMawQKillSteal;
extern bool KogMawEKillSteal;
extern bool KogMawRKillSteal;

//Combo Options
extern bool KogMawComboUseQ;
extern bool KogMawComboUseW;
extern bool KogMawComboUseE;
extern bool KogMawComboUseR;
extern int KogMawComboMaxStacks;
extern bool KogMawCombo40Percent;

//Harass Options
extern bool KogMawHarassUseQ;
extern bool KogMawHarassUseW;
extern bool KogMawHarassUseR;
extern int KogMawHarassMaxStacks;

//Laneclear Options
extern bool KogMawLaneclearUseW;
extern bool KogMawLaneclearWTower;
extern bool KogMawLaneclearUseE;

//Flee Options
extern bool KogMawFleeUseE;

//Misc Options
extern int KogMawQPredHitchance;
extern int KogMawEPredHitchance;
extern int KogMawRPredHitchance;
#pragma endregion

namespace KogMaw
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