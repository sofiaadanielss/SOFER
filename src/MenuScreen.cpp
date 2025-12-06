#include "MenuScreen.h"
#include "GameState.h"

void UpdateMenu(GameState &state) {
    if (IsKeyPressed(KEY_ENTER)) {
        state = PLAYING;  
    }
}

void DrawMenu(Texture2D menuBackground) {
    DrawTexture(menuBackground, 0, 0, WHITE);
}

void DrawGameOver(Texture2D gameOverBg) {
    DrawTexture(gameOverBg, 0, 0, WHITE);
}

void DrawGameBg(Texture2D gameBackground) {
    DrawTexture(gameBackground, 0, 0, WHITE);
}