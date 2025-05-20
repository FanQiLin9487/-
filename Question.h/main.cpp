#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

class Question {
private:
    std::string text;
    std::vector<std::string> options;
    int correctIndex;

public:
    Question(std::string t, std::vector<std::string> opts, int correct);
    void display() const;
    bool isCorrect(int choice) const;
};

#endif
