#include "ScoreBoard.h"
#include "raylib.h"

ScoreBoard::ScoreBoard() : score(0) {}

void ScoreBoard::addPoints(int pts) { score += pts; }

int ScoreBoard::getScore() const { return score; }

void ScoreBoard::render() {
    DrawText(TextFormat("Score: %d", score), 10, 40, 20, WHITE);
}
