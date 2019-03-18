#include "TimmyAIO.h"
#include "Manamanager.h"
#include "Manamanager.Menu.h"

bool Manamanager::EnoughMana(SDK_SPELL spell, OrbwalkingMode mode)
{
	if (Player.GetResource().Type > ABILITY_TYPE_ENERGY)
	{
		return true;
	}

	if (spell.Slot == SPELL_Q)
	{
		if (mode == OrbwalkingMode::Combo && !ManamanagerComboManageQSelection)
		{
			return true;
		}
		if (mode == OrbwalkingMode::Mixed && !ManamanagerHarassManageQSelection)
		{
			return true;
		}
		if (mode == OrbwalkingMode::LaneClear && !ManamanagerLaneclearManageQSelection)
		{
			return true;
			
		}
	}
	else if (spell.Slot == SPELL_W)
	{
		if (mode == OrbwalkingMode::Combo && !ManamanagerComboManageWSelection)
		{
			return true;
		}
		if (mode == OrbwalkingMode::Mixed && !ManamanagerHarassManageWSelection)
		{
			return true;
		}
		if (mode == OrbwalkingMode::LaneClear && !ManamanagerLaneclearManageWSelection)
		{
			return true;
			
		}
	}
	else if (spell.Slot == SPELL_E)
	{
		if (mode == OrbwalkingMode::Combo && !ManamanagerComboManageESelection)
		{
			return true;
		}
		if (mode == OrbwalkingMode::Mixed && !ManamanagerHarassManageESelection)
		{
			return true;
		}
		if (mode == OrbwalkingMode::LaneClear && !ManamanagerLaneclearManageESelection)
		{
			return true;
			
		}
	}
	else if (spell.Slot == SPELL_R)
	{
		if (mode == OrbwalkingMode::Combo && !ManamanagerComboManageRSelection)
		{
			return true;
		}
		if (mode == OrbwalkingMode::Mixed && !ManamanagerHarassManageRSelection)
		{
			return true;
		}
		if (mode == OrbwalkingMode::LaneClear && !ManamanagerLaneclearManageRSelection)
		{
			return true;
			
		}
	}

	const auto heroSpellQManaCost = Player.GetSpell(SPELL_Q).ManaCost;
	const auto heroSpellWManaCost = Player.GetSpell(SPELL_W).ManaCost;
	const auto heroSpellEManaCost = Player.GetSpell(SPELL_E).ManaCost;
	const auto heroSpellRManaCost = Player.GetSpell(SPELL_R).ManaCost;

	const auto heroCurrentMana = Player.GetResource().Current;
	const auto heroMaxMana = Player.GetResource().Max;
	const auto heroManaPercent = heroCurrentMana / heroMaxMana * 100;

	if (mode == OrbwalkingMode::Combo)
	{
		//Priority logic
		if (spell.Slot == SPELL_Q && ManamanagerComboManageQSelection == 1)
		{
			if (ManamanagerComboQPrioritySelection == 0)
			{
				return true;
			}

			if (ManamanagerComboQPrioritySelection == 1)
			{
				if (ManamanagerComboManageWSelection == 1 && ManamanagerComboWPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellWManaCost >= heroSpellQManaCost;
				}
				if (ManamanagerComboManageESelection == 1 && ManamanagerComboEPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellEManaCost >= heroSpellQManaCost;
				}
				if (ManamanagerComboManageRSelection == 1 && ManamanagerComboRPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellRManaCost >= heroSpellQManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Combo Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerComboQPrioritySelection == 2)
			{
				if (ManamanagerComboManageWSelection == 1 && ManamanagerComboWPrioritySelection < 2 && ManamanagerComboManageESelection == 1 && ManamanagerComboEPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellEManaCost >= heroSpellQManaCost;
				}

				if (ManamanagerComboManageWSelection == 1 && ManamanagerComboWPrioritySelection < 2 && ManamanagerComboManageRSelection == 1 && ManamanagerComboRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellRManaCost >= heroSpellQManaCost;
				}

				if (ManamanagerComboManageESelection == 1 && ManamanagerComboEPrioritySelection < 2 && ManamanagerComboManageRSelection == 1 && ManamanagerComboRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellEManaCost - heroSpellRManaCost >= heroSpellQManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Combo Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerComboQPrioritySelection == 3)
			{
				if (ManamanagerComboManageWSelection == 1 && ManamanagerComboWPrioritySelection < 3 && ManamanagerComboManageESelection == 1 && ManamanagerComboEPrioritySelection < 3 && ManamanagerComboManageRSelection == 1 && ManamanagerComboRPrioritySelection < 3)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellEManaCost - heroSpellRManaCost >= heroSpellQManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Combo Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}
		}

		else if (spell.Slot == SPELL_W && ManamanagerComboManageWSelection == 1)
		{
			if (ManamanagerComboWPrioritySelection == 0)
			{
				return true;
			}

			if (ManamanagerComboWPrioritySelection == 1)
			{
				if (ManamanagerComboManageQSelection == 1 && ManamanagerComboQPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellQManaCost >= heroSpellWManaCost;
				}
				if (ManamanagerComboManageESelection == 1 && ManamanagerComboEPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellEManaCost >= heroSpellWManaCost;
				}
				if (ManamanagerComboManageRSelection == 1 && ManamanagerComboRPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellRManaCost >= heroSpellWManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Combo Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerComboWPrioritySelection == 2)
			{
				if (ManamanagerComboManageQSelection == 1 && ManamanagerComboQPrioritySelection < 2 && ManamanagerComboManageESelection == 1 && ManamanagerComboEPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellEManaCost >= heroSpellWManaCost;
				}

				if (ManamanagerComboManageQSelection == 1 && ManamanagerComboQPrioritySelection < 2 && ManamanagerComboManageRSelection == 1 && ManamanagerComboRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellRManaCost >= heroSpellWManaCost;
				}

				if (ManamanagerComboManageESelection == 1 && ManamanagerComboEPrioritySelection < 2 && ManamanagerComboManageRSelection == 1 && ManamanagerComboRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellEManaCost - heroSpellRManaCost >= heroSpellWManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Combo Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerComboWPrioritySelection == 3)
			{
				if (ManamanagerComboManageQSelection == 1 && ManamanagerComboQPrioritySelection < 3 && ManamanagerComboManageESelection == 1 && ManamanagerComboEPrioritySelection < 3 && ManamanagerComboManageRSelection == 1 && ManamanagerComboRPrioritySelection < 3)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellEManaCost - heroSpellRManaCost >= heroSpellWManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Combo Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}
		}

		else if (spell.Slot == SPELL_E && ManamanagerComboManageESelection == 1)
		{
			if (ManamanagerComboEPrioritySelection == 0)
			{
				return true;
			}

			if (ManamanagerComboEPrioritySelection == 1)
			{
				if (ManamanagerComboManageQSelection == 1 && ManamanagerComboQPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellQManaCost >= heroSpellEManaCost;
				}
				if (ManamanagerComboManageWSelection == 1 && ManamanagerComboWPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellWManaCost >= heroSpellEManaCost;
				}
				if (ManamanagerComboManageRSelection == 1 && ManamanagerComboRPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellRManaCost >= heroSpellEManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Combo Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerComboEPrioritySelection == 2)
			{
				if (ManamanagerComboManageQSelection == 1 && ManamanagerComboQPrioritySelection < 2 && ManamanagerComboManageWSelection == 1 && ManamanagerComboWPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellWManaCost >= heroSpellEManaCost;
				}

				if (ManamanagerComboManageQSelection == 1 && ManamanagerComboQPrioritySelection < 2 && ManamanagerComboManageRSelection == 1 && ManamanagerComboRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellRManaCost >= heroSpellEManaCost;
				}

				if (ManamanagerComboManageWSelection == 1 && ManamanagerComboWPrioritySelection < 2 && ManamanagerComboManageRSelection == 1 && ManamanagerComboRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellRManaCost >= heroSpellEManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Combo Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerComboEPrioritySelection == 3)
			{
				if (ManamanagerComboManageQSelection == 1 && ManamanagerComboQPrioritySelection < 3 && ManamanagerComboManageWSelection == 1 && ManamanagerComboWPrioritySelection < 3 && ManamanagerComboManageRSelection == 1 && ManamanagerComboRPrioritySelection < 3)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellWManaCost - heroSpellRManaCost >= heroSpellEManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Combo Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}
		}
		
		else if (spell.Slot == SPELL_R && ManamanagerComboManageRSelection == 1)
		{
			if (ManamanagerComboRPrioritySelection == 0)
			{
				return true;
			}

			if (ManamanagerComboRPrioritySelection == 1)
			{
				if (ManamanagerComboManageQSelection == 1 && ManamanagerComboQPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellQManaCost >= heroSpellRManaCost;
				}
				if (ManamanagerComboManageWSelection == 1 && ManamanagerComboWPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellWManaCost >= heroSpellRManaCost;
				}
				if (ManamanagerComboManageRSelection == 1 && ManamanagerComboRPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellEManaCost >= heroSpellRManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Combo Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerComboRPrioritySelection == 2)
			{
				if (ManamanagerComboManageQSelection == 1 && ManamanagerComboQPrioritySelection < 2 && ManamanagerComboManageWSelection == 1 && ManamanagerComboWPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellWManaCost >= heroSpellRManaCost;
				}

				if (ManamanagerComboManageQSelection == 1 && ManamanagerComboQPrioritySelection < 2 && ManamanagerComboManageESelection == 1 && ManamanagerComboEPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellEManaCost >= heroSpellRManaCost;
				}

				if (ManamanagerComboManageWSelection == 1 && ManamanagerComboWPrioritySelection < 2 && ManamanagerComboManageESelection == 1 && ManamanagerComboEPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellEManaCost >= heroSpellRManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Combo Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerComboRPrioritySelection == 3)
			{
				if (ManamanagerComboManageQSelection == 1 && ManamanagerComboQPrioritySelection < 3 && ManamanagerComboManageWSelection == 1 && ManamanagerComboWPrioritySelection < 3 && ManamanagerComboManageESelection == 1 && ManamanagerComboEPrioritySelection < 3)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellWManaCost - heroSpellEManaCost >= heroSpellRManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Combo Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}
		}

		//Percentage Logic
		else if (spell.Slot == SPELL_Q && ManamanagerComboManageQSelection == 2)
		{
			return heroManaPercent >= ManamanagerComboQMinPercentMana;
		}

		else if (spell.Slot == SPELL_W && ManamanagerComboManageWSelection == 2)
		{
			return heroManaPercent >= ManamanagerComboWMinPercentMana;
		}

		else if (spell.Slot == SPELL_E && ManamanagerComboManageESelection == 2)
		{
			return heroManaPercent >= ManamanagerComboEMinPercentMana;
		}

		else if (spell.Slot == SPELL_R && ManamanagerComboManageRSelection == 2)
		{
			return heroManaPercent >= ManamanagerComboRMinPercentMana;
		}
	}

	if (mode == OrbwalkingMode::Mixed)
	{
		if (spell.Slot == SPELL_Q && ManamanagerHarassManageQSelection == 1)
		{
			if (ManamanagerHarassQPrioritySelection == 0)
			{
				return true;
			}

			if (ManamanagerHarassQPrioritySelection == 1)
			{
				if (ManamanagerHarassManageWSelection == 1 && ManamanagerHarassWPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellWManaCost >= heroSpellQManaCost;
				}
				if (ManamanagerHarassManageESelection == 1 && ManamanagerHarassEPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellEManaCost >= heroSpellQManaCost;
				}
				if (ManamanagerHarassManageRSelection == 1 && ManamanagerHarassRPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellRManaCost >= heroSpellQManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Harass Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerHarassQPrioritySelection == 2)
			{
				if (ManamanagerHarassManageWSelection == 1 && ManamanagerHarassWPrioritySelection < 2 && ManamanagerHarassManageESelection == 1 && ManamanagerHarassEPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellEManaCost >= heroSpellQManaCost;
				}

				if (ManamanagerHarassManageWSelection == 1 && ManamanagerHarassWPrioritySelection < 2 && ManamanagerHarassManageRSelection == 1 && ManamanagerHarassRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellRManaCost >= heroSpellQManaCost;
				}

				if (ManamanagerHarassManageESelection == 1 && ManamanagerHarassEPrioritySelection < 2 && ManamanagerHarassManageRSelection == 1 && ManamanagerHarassRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellEManaCost - heroSpellRManaCost >= heroSpellQManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Harass Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerHarassQPrioritySelection == 3)
			{
				if (ManamanagerHarassManageWSelection == 1 && ManamanagerHarassWPrioritySelection < 3 && ManamanagerHarassManageESelection == 1 && ManamanagerHarassEPrioritySelection < 3 && ManamanagerHarassManageRSelection == 1 && ManamanagerHarassRPrioritySelection < 3)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellEManaCost - heroSpellRManaCost >= heroSpellQManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Harass Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}
		}

		else if (spell.Slot == SPELL_W && ManamanagerHarassManageWSelection == 1)
		{
			if (ManamanagerHarassWPrioritySelection == 0)
			{
				return true;
			}

			if (ManamanagerHarassWPrioritySelection == 1)
			{
				if (ManamanagerHarassManageQSelection == 1 && ManamanagerHarassQPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellQManaCost >= heroSpellWManaCost;
				}
				if (ManamanagerHarassManageESelection == 1 && ManamanagerHarassEPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellEManaCost >= heroSpellWManaCost;
				}
				if (ManamanagerHarassManageRSelection == 1 && ManamanagerHarassRPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellRManaCost >= heroSpellWManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Harass Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerHarassWPrioritySelection == 2)
			{
				if (ManamanagerHarassManageQSelection == 1 && ManamanagerHarassQPrioritySelection < 2 && ManamanagerHarassManageESelection == 1 && ManamanagerHarassEPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellEManaCost >= heroSpellWManaCost;
				}

				if (ManamanagerHarassManageQSelection == 1 && ManamanagerHarassQPrioritySelection < 2 && ManamanagerHarassManageRSelection == 1 && ManamanagerHarassRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellRManaCost >= heroSpellWManaCost;
				}

				if (ManamanagerHarassManageESelection == 1 && ManamanagerHarassEPrioritySelection < 2 && ManamanagerHarassManageRSelection == 1 && ManamanagerHarassRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellEManaCost - heroSpellRManaCost >= heroSpellWManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Harass Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerHarassWPrioritySelection == 3)
			{
				if (ManamanagerHarassManageQSelection == 1 && ManamanagerHarassQPrioritySelection < 3 && ManamanagerHarassManageESelection == 1 && ManamanagerHarassEPrioritySelection < 3 && ManamanagerHarassManageRSelection == 1 && ManamanagerHarassRPrioritySelection < 3)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellEManaCost - heroSpellRManaCost >= heroSpellWManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Harass Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}
		}

		else if (spell.Slot == SPELL_E && ManamanagerHarassManageESelection == 1)
		{
			if (ManamanagerHarassEPrioritySelection == 0)
			{
				return true;
			}

			if (ManamanagerHarassEPrioritySelection == 1)
			{
				if (ManamanagerHarassManageQSelection == 1 && ManamanagerHarassQPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellQManaCost >= heroSpellEManaCost;
				}
				if (ManamanagerHarassManageWSelection == 1 && ManamanagerHarassWPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellWManaCost >= heroSpellEManaCost;
				}
				if (ManamanagerHarassManageRSelection == 1 && ManamanagerHarassRPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellRManaCost >= heroSpellEManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Harass Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerHarassEPrioritySelection == 2)
			{
				if (ManamanagerHarassManageQSelection == 1 && ManamanagerHarassQPrioritySelection < 2 && ManamanagerHarassManageWSelection == 1 && ManamanagerHarassWPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellWManaCost >= heroSpellEManaCost;
				}

				if (ManamanagerHarassManageQSelection == 1 && ManamanagerHarassQPrioritySelection < 2 && ManamanagerHarassManageRSelection == 1 && ManamanagerHarassRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellRManaCost >= heroSpellEManaCost;
				}

				if (ManamanagerHarassManageWSelection == 1 && ManamanagerHarassWPrioritySelection < 2 && ManamanagerHarassManageRSelection == 1 && ManamanagerHarassRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellRManaCost >= heroSpellEManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Harass Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerHarassEPrioritySelection == 3)
			{
				if (ManamanagerHarassManageQSelection == 1 && ManamanagerHarassQPrioritySelection < 3 && ManamanagerHarassManageWSelection == 1 && ManamanagerHarassWPrioritySelection < 3 && ManamanagerHarassManageRSelection == 1 && ManamanagerHarassRPrioritySelection < 3)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellWManaCost - heroSpellRManaCost >= heroSpellEManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Harass Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}
		}
		
		else if (spell.Slot == SPELL_R && ManamanagerHarassManageRSelection == 1)
		{
			if (ManamanagerHarassRPrioritySelection == 0)
			{
				return true;
			}

			if (ManamanagerHarassRPrioritySelection == 1)
			{
				if (ManamanagerHarassManageQSelection == 1 && ManamanagerHarassQPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellQManaCost >= heroSpellRManaCost;
				}
				if (ManamanagerHarassManageWSelection == 1 && ManamanagerHarassWPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellWManaCost >= heroSpellRManaCost;
				}
				if (ManamanagerHarassManageRSelection == 1 && ManamanagerHarassRPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellEManaCost >= heroSpellRManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Harass Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerHarassRPrioritySelection == 2)
			{
				if (ManamanagerHarassManageQSelection == 1 && ManamanagerHarassQPrioritySelection < 2 && ManamanagerHarassManageWSelection == 1 && ManamanagerHarassWPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellWManaCost >= heroSpellRManaCost;
				}

				if (ManamanagerHarassManageQSelection == 1 && ManamanagerHarassQPrioritySelection < 2 && ManamanagerHarassManageESelection == 1 && ManamanagerHarassEPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellEManaCost >= heroSpellRManaCost;
				}

				if (ManamanagerHarassManageWSelection == 1 && ManamanagerHarassWPrioritySelection < 2 && ManamanagerHarassManageESelection == 1 && ManamanagerHarassEPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellEManaCost >= heroSpellRManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Harass Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerHarassRPrioritySelection == 3)
			{
				if (ManamanagerHarassManageQSelection == 1 && ManamanagerHarassQPrioritySelection < 3 && ManamanagerHarassManageWSelection == 1 && ManamanagerHarassWPrioritySelection < 3 && ManamanagerHarassManageESelection == 1 && ManamanagerHarassEPrioritySelection < 3)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellWManaCost - heroSpellEManaCost >= heroSpellRManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Harass Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}
		}

		else if (spell.Slot == SPELL_Q && ManamanagerHarassManageQSelection == 2)
		{
			return heroManaPercent >= ManamanagerHarassQMinPercentMana;
		}

		else if (spell.Slot == SPELL_W && ManamanagerHarassManageWSelection == 2)
		{
			return heroManaPercent >= ManamanagerHarassWMinPercentMana;
		}

		else if (spell.Slot == SPELL_E && ManamanagerHarassManageESelection == 2)
		{
			return heroManaPercent >= ManamanagerHarassEMinPercentMana;
		}

		else if (spell.Slot == SPELL_R && ManamanagerHarassManageRSelection == 2)
		{
			return heroManaPercent >= ManamanagerHarassRMinPercentMana;
		}
	}

	if (mode == OrbwalkingMode::LaneClear)
	{
		if (spell.Slot == SPELL_Q && ManamanagerLaneclearManageQSelection == 1)
		{
			if (ManamanagerLaneclearQPrioritySelection == 0)
			{
				return true;
			}

			if (ManamanagerLaneclearQPrioritySelection == 1)
			{
				if (ManamanagerLaneclearManageWSelection == 1 && ManamanagerLaneclearWPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellWManaCost >= heroSpellQManaCost;
				}
				if (ManamanagerLaneclearManageESelection == 1 && ManamanagerLaneclearEPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellEManaCost >= heroSpellQManaCost;
				}
				if (ManamanagerLaneclearManageRSelection == 1 && ManamanagerLaneclearRPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellRManaCost >= heroSpellQManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Laneclear Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerLaneclearQPrioritySelection == 2)
			{
				if (ManamanagerLaneclearManageWSelection == 1 && ManamanagerLaneclearWPrioritySelection < 2 && ManamanagerLaneclearManageESelection == 1 && ManamanagerLaneclearEPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellEManaCost >= heroSpellQManaCost;
				}

				if (ManamanagerLaneclearManageWSelection == 1 && ManamanagerLaneclearWPrioritySelection < 2 && ManamanagerLaneclearManageRSelection == 1 && ManamanagerLaneclearRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellRManaCost >= heroSpellQManaCost;
				}

				if (ManamanagerLaneclearManageESelection == 1 && ManamanagerLaneclearEPrioritySelection < 2 && ManamanagerLaneclearManageRSelection == 1 && ManamanagerLaneclearRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellEManaCost - heroSpellRManaCost >= heroSpellQManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Laneclear Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerLaneclearQPrioritySelection == 3)
			{
				if (ManamanagerLaneclearManageWSelection == 1 && ManamanagerLaneclearWPrioritySelection < 3 && ManamanagerLaneclearManageESelection == 1 && ManamanagerLaneclearEPrioritySelection < 3 && ManamanagerLaneclearManageRSelection == 1 && ManamanagerLaneclearRPrioritySelection < 3)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellEManaCost - heroSpellRManaCost >= heroSpellQManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Laneclear Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}
		}

		else if (spell.Slot == SPELL_W && ManamanagerLaneclearManageWSelection == 1)
		{
			if (ManamanagerLaneclearWPrioritySelection == 0)
			{
				return true;
			}

			if (ManamanagerLaneclearWPrioritySelection == 1)
			{
				if (ManamanagerLaneclearManageQSelection == 1 && ManamanagerLaneclearQPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellQManaCost >= heroSpellWManaCost;
				}
				if (ManamanagerLaneclearManageESelection == 1 && ManamanagerLaneclearEPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellEManaCost >= heroSpellWManaCost;
				}
				if (ManamanagerLaneclearManageRSelection == 1 && ManamanagerLaneclearRPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellRManaCost >= heroSpellWManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Laneclear Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerLaneclearWPrioritySelection == 2)
			{
				if (ManamanagerLaneclearManageQSelection == 1 && ManamanagerLaneclearQPrioritySelection < 2 && ManamanagerLaneclearManageESelection == 1 && ManamanagerLaneclearEPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellEManaCost >= heroSpellWManaCost;
				}

				if (ManamanagerLaneclearManageQSelection == 1 && ManamanagerLaneclearQPrioritySelection < 2 && ManamanagerLaneclearManageRSelection == 1 && ManamanagerLaneclearRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellRManaCost >= heroSpellWManaCost;
				}

				if (ManamanagerLaneclearManageESelection == 1 && ManamanagerLaneclearEPrioritySelection < 2 && ManamanagerLaneclearManageRSelection == 1 && ManamanagerLaneclearRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellEManaCost - heroSpellRManaCost >= heroSpellWManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Laneclear Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerLaneclearWPrioritySelection == 3)
			{
				if (ManamanagerLaneclearManageQSelection == 1 && ManamanagerLaneclearQPrioritySelection < 3 && ManamanagerLaneclearManageESelection == 1 && ManamanagerLaneclearEPrioritySelection < 3 && ManamanagerLaneclearManageRSelection == 1 && ManamanagerLaneclearRPrioritySelection < 3)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellEManaCost - heroSpellRManaCost >= heroSpellWManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Laneclear Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}
		}

		else if (spell.Slot == SPELL_E && ManamanagerLaneclearManageESelection == 1)
		{
			if (ManamanagerLaneclearEPrioritySelection == 0)
			{
				return true;
			}

			if (ManamanagerLaneclearEPrioritySelection == 1)
			{
				if (ManamanagerLaneclearManageQSelection == 1 && ManamanagerLaneclearQPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellQManaCost >= heroSpellEManaCost;
				}
				if (ManamanagerLaneclearManageWSelection == 1 && ManamanagerLaneclearWPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellWManaCost >= heroSpellEManaCost;
				}
				if (ManamanagerLaneclearManageRSelection == 1 && ManamanagerLaneclearRPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellRManaCost >= heroSpellEManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Laneclear Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerLaneclearEPrioritySelection == 2)
			{
				if (ManamanagerLaneclearManageQSelection == 1 && ManamanagerLaneclearQPrioritySelection < 2 && ManamanagerLaneclearManageWSelection == 1 && ManamanagerLaneclearWPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellWManaCost >= heroSpellEManaCost;
				}

				if (ManamanagerLaneclearManageQSelection == 1 && ManamanagerLaneclearQPrioritySelection < 2 && ManamanagerLaneclearManageRSelection == 1 && ManamanagerLaneclearRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellRManaCost >= heroSpellEManaCost;
				}

				if (ManamanagerLaneclearManageWSelection == 1 && ManamanagerLaneclearWPrioritySelection < 2 && ManamanagerLaneclearManageRSelection == 1 && ManamanagerLaneclearRPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellRManaCost >= heroSpellEManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Laneclear Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerLaneclearEPrioritySelection == 3)
			{
				if (ManamanagerLaneclearManageQSelection == 1 && ManamanagerLaneclearQPrioritySelection < 3 && ManamanagerLaneclearManageWSelection == 1 && ManamanagerLaneclearWPrioritySelection < 3 && ManamanagerLaneclearManageRSelection == 1 && ManamanagerLaneclearRPrioritySelection < 3)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellWManaCost - heroSpellRManaCost >= heroSpellEManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Laneclear Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}
		}
		
		else if (spell.Slot == SPELL_R && ManamanagerLaneclearManageRSelection == 1)
		{
			if (ManamanagerLaneclearRPrioritySelection == 0)
			{
				return true;
			}

			if (ManamanagerLaneclearRPrioritySelection == 1)
			{
				if (ManamanagerLaneclearManageQSelection == 1 && ManamanagerLaneclearQPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellQManaCost >= heroSpellRManaCost;
				}
				if (ManamanagerLaneclearManageWSelection == 1 && ManamanagerLaneclearWPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellWManaCost >= heroSpellRManaCost;
				}
				if (ManamanagerLaneclearManageRSelection == 1 && ManamanagerLaneclearRPrioritySelection == 0)
				{
					return heroCurrentMana - heroSpellEManaCost >= heroSpellRManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Laneclear Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerLaneclearRPrioritySelection == 2)
			{
				if (ManamanagerLaneclearManageQSelection == 1 && ManamanagerLaneclearQPrioritySelection < 2 && ManamanagerLaneclearManageWSelection == 1 && ManamanagerLaneclearWPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellWManaCost >= heroSpellRManaCost;
				}

				if (ManamanagerLaneclearManageQSelection == 1 && ManamanagerLaneclearQPrioritySelection < 2 && ManamanagerLaneclearManageESelection == 1 && ManamanagerLaneclearEPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellQManaCost - heroSpellEManaCost >= heroSpellRManaCost;
				}

				if (ManamanagerLaneclearManageWSelection == 1 && ManamanagerLaneclearWPrioritySelection < 2 && ManamanagerLaneclearManageESelection == 1 && ManamanagerLaneclearEPrioritySelection < 2)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellEManaCost >= heroSpellRManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Laneclear Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}

			else if (ManamanagerLaneclearRPrioritySelection == 3)
			{
				if (ManamanagerLaneclearManageQSelection == 1 && ManamanagerLaneclearQPrioritySelection < 3 && ManamanagerLaneclearManageWSelection == 1 && ManamanagerLaneclearWPrioritySelection < 3 && ManamanagerLaneclearManageESelection == 1 && ManamanagerLaneclearEPrioritySelection < 3)
				{
					return heroCurrentMana - heroSpellWManaCost - heroSpellWManaCost - heroSpellEManaCost >= heroSpellRManaCost;
				}
				SdkDisplayChatLocalPlayer("Error in Manamanager Laneclear Priority settings. Contact Timmy if you need help.", CHAT_FLAG_TURQUOISE);
			}
		}

		else if (spell.Slot == SPELL_Q && ManamanagerLaneclearManageQSelection == 2)
		{
			return heroManaPercent >= ManamanagerLaneclearQMinPercentMana;
		}

		else if (spell.Slot == SPELL_W && ManamanagerLaneclearManageWSelection == 2)
		{
			return heroManaPercent >= ManamanagerLaneclearWMinPercentMana;
		}

		else if (spell.Slot == SPELL_E && ManamanagerLaneclearManageESelection == 2)
		{
			return heroManaPercent >= ManamanagerLaneclearEMinPercentMana;
		}

		else if (spell.Slot == SPELL_R && ManamanagerLaneclearManageRSelection == 2)
		{
			return heroManaPercent >= ManamanagerLaneclearRMinPercentMana;
		}
	}
	return false;
}
