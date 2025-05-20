#include "GameManager.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;

GameManager::GameManager() : score(0), timeLimit(15) {
    questions = {
        {"C++ 中，哪個關鍵字用來定義常數？", {"const", "var", "define", "static"}, 0},
        {"哪個資料型態可以儲存小數？", {"int", "float", "bool", "char"}, 1},
        {"在 C++ 中，'cout' 是什麼？", {"輸出指令", "輸入指令", "迴圈語法", "條件語法"}, 0},
        {"哪個符號用來存取指標的值？", {"&", "*", "#", "@"}, 1},
        {"下列哪個是 C++ 的迴圈結構？", {"if", "switch", "for", "try"}, 2}
    };
}

void GameManager::start() {
    cout << "歡迎來到快問快答小遊戲！\n";
    cout << "你有 " << timeLimit << " 秒時間回答每一題。\n\n";

    for (auto& q : questions) {
        q.display();
        int choice = getUserAnswerWithTimer();

        if (choice == -1) {
            cout << "時間到！這題不計分。\n\n";
        } else if (q.isCorrect(choice)) {
            cout << "答對了！\n\n";
            score += 10;
        } else {
            cout << "答錯了！正確答案是第 " << (q.isCorrect(1) ? 1 : 2) << " 項。\n\n";
        }
    }

    cout << "遊戲結束！你的總分是：" << score << " 分。\n";
    showRank();
}

int GameManager::getUserAnswerWithTimer() {
    int choice = -1;
    auto startTime = steady_clock::now();
    bool inputReceived = false;

    thread inputThread([&]() {
        cout << "請輸入你的答案（數字1-4）: ";
        cin >> choice;
        inputReceived = true;
    });

    while (duration_cast<seconds>(steady_clock::now() - startTime).count() < timeLimit) {
        if (inputReceived) break;
        this_thread::sleep_for(milliseconds(100));
    }

    if (!inputReceived) {
        inputThread.detach();
        return -1;
    } else {
        inputThread.join();
        return choice;
    }
}

void GameManager::showRank() {
    if (score >= 40) {
        cout << "大神求抱大腿。";
    } else if (score >= 20) {
        cout << "唉呦不錯呦。\n";
    } else {
        cout << "菜就多練。\n";
    }
}
