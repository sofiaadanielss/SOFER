
#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "raylib.h"
#include "GameState.h"

void UpdateMenu(GameState &state);
void DrawMenu(Texture2D menuBackground);  
void DrawGameOver(Texture2D gameOverBg);
void DrawGameBg(Texture2D gameBackground);

#endif
