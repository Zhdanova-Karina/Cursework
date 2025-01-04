#define _CRT_SECURE_NO_WARNINGS
#include "Phrase.h"
#include <cwchar>

Phrase::Phrase() {
    wcscpy(text, L"");
}

Phrase::Phrase(const wchar_t* phraseText) {
    wcscpy(text, phraseText);
}

const wchar_t* Phrase::getText() const {
    return text;
}

void Phrase::setText(const wchar_t* phraseText) {
    wcscpy(text, phraseText);
}