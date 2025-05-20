#include "Question.h"
#include <iostream>

using namespace std;

Question::Question(string t, vector<string> opts, int correct)
    : text(t), options(opts), correctIndex(correct) {}

void Question::display() const {
    cout << text << endl;
    for (size_t i = 0; i < options.size(); ++i) {
        cout << i + 1 << ". " << options[i] << endl;
    }
}

bool Question::isCorrect(int choice) const {
    return choice == correctIndex + 1;
}
