#ifndef GAME_H
#define GAME_H

#include "Puzzle.h"
#include "Player.h"
#include "Phrase.h"

#define MAX_PUZZLES 3
#define MAX_PHRASES 3

class Game {
private:
    Puzzle puzzles[MAX_PUZZLES];
    Player player;
    int currentPuzzle;
    Phrase phrases[MAX_PHRASES];
public:
    Game();
    void initializePuzzles();
    void initializePhrases();
    void setPlayerName(const wchar_t* playerName);
    const wchar_t* getPlayerName() const;
    int getPlayerScore() const;
    const wchar_t* getRandomPhrase() const;
    bool checkAnswer(int puzzleIndex, int answerIndex);
    Puzzle& getPuzzle(int index);
    void nextPuzzle();
    int getCurrentPuzzleIndex() const;
    void startGame();
};

#endif // GAME_H

