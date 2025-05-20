#include "GameManager.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;

GameManager::GameManager() : score(0), timeLimit(15) {
    questions = {
        {"C++ ���A��������r�Ψөw�q�`�ơH", {"const", "var", "define", "static"}, 0},
        {"���Ӹ�ƫ��A�i�H�x�s�p�ơH", {"int", "float", "bool", "char"}, 1},
        {"�b C++ ���A'cout' �O����H", {"��X���O", "��J���O", "�j��y�k", "����y�k"}, 0},
        {"���ӲŸ��ΨӦs�����Ъ��ȡH", {"&", "*", "#", "@"}, 1},
        {"�U�C���ӬO C++ ���j�鵲�c�H", {"if", "switch", "for", "try"}, 2}
    };
}

void GameManager::start() {
    cout << "�w��Ө�ְݧֵ��p�C���I\n";
    cout << "�A�� " << timeLimit << " ��ɶ��^���C�@�D�C\n\n";

    for (auto& q : questions) {
        q.display();
        int choice = getUserAnswerWithTimer();

        if (choice == -1) {
            cout << "�ɶ���I�o�D���p���C\n\n";
        } else if (q.isCorrect(choice)) {
            cout << "����F�I\n\n";
            score += 10;
        } else {
            cout << "�����F�I���T���׬O�� " << (q.isCorrect(1) ? 1 : 2) << " ���C\n\n";
        }
    }

    cout << "�C�������I�A���`���O�G" << score << " ���C\n";
    showRank();
}

int GameManager::getUserAnswerWithTimer() {
    int choice = -1;
    auto startTime = steady_clock::now();
    bool inputReceived = false;

    thread inputThread([&]() {
        cout << "�п�J�A�����ס]�Ʀr1-4�^: ";
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
        cout << "�j���D��j�L�C";
    } else if (score >= 20) {
        cout << "���礣����C\n";
    } else {
        cout << "��N�h�m�C\n";
    }
}
