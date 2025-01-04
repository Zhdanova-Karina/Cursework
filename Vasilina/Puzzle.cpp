#define _CRT_SECURE_NO_WARNINGS
#include "Puzzle.h"
#include <cwchar>

Puzzle::Puzzle() : correctAnswerIndex(0), attempts(0) {
    wcscpy(question, L"");
}

Puzzle::Puzzle(const wchar_t* question, int correctAnswerIndex, const wchar_t* hintText1, const wchar_t* hintText2, const wchar_t* hintText3, const wchar_t* option1, const wchar_t* option2, const wchar_t* option3) {
    wcscpy(this->question, question);
    this->correctAnswerIndex = correctAnswerIndex;
    hints[0].setText(hintText1);
    hints[1].setText(hintText2);
    hints[2].setText(hintText3);
    options[0].setText(option1);
    options[1].setText(option2);
    options[2].setText(option3);
    attempts = 0;
}

const wchar_t* Puzzle::getQuestion() const {
    return question;
}

const wchar_t* Puzzle::getOption(int index) const {
    return options[index].getText();
}

const wchar_t* Puzzle::getHint(int index) const {
    return hints[index].getText();
}

int Puzzle::getCorrectAnswerIndex() const {
    return correctAnswerIndex;
}

int Puzzle::getAttempts() const {
    return attempts;
}

void Puzzle::incrementAttempts() {
    attempts++;
}

void Puzzle::resetAttempts() {
    attempts = 0;
}
