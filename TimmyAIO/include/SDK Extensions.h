#pragma once

#include "Vectors.hpp"
#include "sdkapi.h"

#include "KeyCodes.h"
#include "ItemID.h"
#include "Macros.hpp"
#include "Common.hpp"
#include "Renderer.hpp"
#include "Game.hpp"
#include "GameObjects.hpp"
#include "Interruptible.hpp"
#include "Menu.hpp"

#include "Interface Structs.h"
#include "Spell.hpp"


#define SPELL_Q 0
#define SPELL_W 1
#define SPELL_E 2
#define SPELL_R 3

#define LIBRARY_SDK "Rift SDK Extensions"
#define LIBRARY_VERSION_SDK 4
#define LIBRARY_IMPORT_SDK "RETURN_SDK"

#define LIBRARY_ESSENTIALS "Rift Essentials"
#define LIBRARY_VERSION_ESSENTIALS 3
#define LIBRARY_IMPORT_ESSENTIALS "RETURN_ESSENTIALS"

__declspec(selectany) bool DevMode = true;