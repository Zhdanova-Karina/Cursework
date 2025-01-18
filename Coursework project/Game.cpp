#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include <cstdlib>

Game::Game() : currentPuzzle(0) {}

void Game::initializePuzzles() {
    puzzles[0] = Puzzle(L"Что может идти вверх и вниз, \n   но при этом не двигается?", 0, L"У этого предмета есть ступеньки.", L"Ты можешь встретить его в здании.", L"Это помогает людям перемещаться между этажами.", L"Лестница", L"Эскалатор", L"Лифт");
    puzzles[1] = Puzzle(L"    То ли зебра, то ли лесенка, \n прикоснись - и будет песенка.", 1, L"Это музыкальный инструмент.", L"У него есть черные и белые клавиши.", L"На нем можно играть мелодии.", L"Эскалатор", L"Пианино", L"Гитара");
    puzzles[2] = Puzzle(L"    Я говорю без рта и слышу \n        без ушей. Что я такое?", 1, L"Это природное явление, которое ты можешь услышать.", L"Оно возникает, когда звук отражается от поверхности.", L"Ты можешь слышать его в горах или пещерах.", L"Голос", L"Эхо", L"Ветер");
}

void Game::initializePhrases() {
    phrases[0] = Phrase(L"У дома Круэллы красная крыша.");
    phrases[1] = Phrase(L"У дома Круэллы красная дверь.");
    phrases[2] = Phrase(L"Дом Круэллы построен из кирпича.");
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
