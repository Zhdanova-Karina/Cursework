#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include <cstdlib>

Game::Game() : currentPuzzle(0) {}

void Game::initializePuzzles() {
    puzzles[0] = Puzzle(L"��� ����� ���� ����� � ����, \n   �� ��� ���� �� ���������?", 0, L"� ����� �������� ���� ���������.", L"�� ������ ��������� ��� � ������.", L"��� �������� ����� ������������ ����� �������.", L"��������", L"���������", L"����");
    puzzles[1] = Puzzle(L"    �� �� �����, �� �� �������, \n ���������� - � ����� �������.", 1, L"��� ����������� ����������.", L"� ���� ���� ������ � ����� �������.", L"�� ��� ����� ������ �������.", L"���������", L"�������", L"������");
    puzzles[2] = Puzzle(L"    � ������ ��� ��� � ����� \n        ��� ����. ��� � �����?", 1, L"��� ��������� �������, ������� �� ������ ��������.", L"��� ���������, ����� ���� ���������� �� �����������.", L"�� ������ ������� ��� � ����� ��� �������.", L"�����", L"���", L"�����");
}

void Game::initializePhrases() {
    phrases[0] = Phrase(L"� ���� ������� ������� �����.");
    phrases[1] = Phrase(L"� ���� ������� ������� �����.");
    phrases[2] = Phrase(L"��� ������� �������� �� �������.");
}

void Game::setPlayerName(const wchar_t* playerName) {
    player = Player(playerName);
}

const wchar_t* Game::getPlayerName() const {
    return player.getName();
}

int Game::getPlayerScore() const {
    return player.getScore();
}

const wchar_t* Game::getRandomPhrase() const {
    int randomIndex = rand() % MAX_PHRASES;
    return phrases[randomIndex].getText();
}

bool Game::checkAnswer(int puzzleIndex, int answerIndex) {
    if (answerIndex == puzzles[puzzleIndex].getCorrectAnswerIndex()) {
        player.incrementScore();
        return true;
    }
    else {
        puzzles[puzzleIndex].incrementAttempts();
        return false;
    }
}

Puzzle& Game::getPuzzle(int index) {
    return puzzles[index];
}

void Game::nextPuzzle() {
    currentPuzzle++;
    if (currentPuzzle >= MAX_PUZZLES) {
        currentPuzzle = 0;
        startGame();
    }
}

int Game::getCurrentPuzzleIndex() const {
  return currentPuzzle;
}

void Game::startGame() {
    player.resetScore();
    for (int i = 0; i < MAX_PUZZLES; i++) {
        puzzles[i].resetAttempts();
    }
    currentPuzzle = 0;
}
