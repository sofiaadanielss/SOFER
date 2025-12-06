#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class ScoreBoard {
    int score;

public:
    ScoreBoard();
    void addPoints(int pts);
    int getScore() const;
    void reset() { score = 0; }
    void render();
};

#endif
