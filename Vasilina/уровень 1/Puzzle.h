#ifndef PUZZLE_H
#define PUZZLE_H

#include "Option.h"
#include "Hint.h"

#define MAX_HINTS 3

class Puzzle {
private:
    wchar_t question[MAX_HINT_LENGTH];
    Option options[3];
    int correctAnswerIndex;
    Hint hints[MAX_HINTS];
    int attempts;
public:
    Puzzle();
    Puzzle(const wchar_t* question, int correctAnswerIndex, const wchar_t* hintText1, const wchar_t* hintText2, const wchar_t* hintText3, const wchar_t* option1, const wchar_t* option2, const wchar_t* option3);
    const wchar_t* getQuestion() const;
    const wchar_t* getOption(int index) const;
    const wchar_t* getHint(int index) const;
    int getCorrectAnswerIndex() const;
    int getAttempts() const;
    void incrementAttempts();
    void resetAttempts();
};

#endif // PUZZLE_H

