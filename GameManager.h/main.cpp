#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include "Question.h"

class GameManager {
private:
    std::vector<Question> questions;
    int score;
    const int timeLimit;

public:
    GameManager();
    void start();

private:
    int getUserAnswerWithTimer();
    void showRank();
};

#endif
