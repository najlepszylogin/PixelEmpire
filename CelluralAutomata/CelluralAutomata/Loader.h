#pragma once
#include "Player.h"
#include "Map.h"
#include "HUD.h"
#include "Empire.h"
#include "WorkManager.h"
#include "strings_PL.h"



inline void LoadEngine()
{

	LoadMap();
	LoadTextures();
	UpdateButtons();
	LoadCursors();
	GenerateSettingsButtons();

	srand(time(NULL));
	LoadText();



}

