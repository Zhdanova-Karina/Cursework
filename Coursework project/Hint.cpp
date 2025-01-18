#define _CRT_SECURE_NO_WARNINGS
#include "Hint.h"
#include <cwchar>

Hint::Hint() {
    wcscpy(text, L"");
}

Hint::Hint(const wchar_t* hintText) {
    wcscpy(text, hintText);
}

const wchar_t* Hint::getText() const {
    return text;
}

void Hint::setText(const wchar_t* hintText) {
    wcscpy(text, hintText);
}
