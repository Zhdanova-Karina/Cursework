#define _CRT_SECURE_NO_WARNINGS
#include "Option.h"
#include <cwchar>

Option::Option() {
    wcscpy(text, L"");
}

Option::Option(const wchar_t* optionText) {
    wcscpy(text, optionText);
}

const wchar_t* Option::getText() const {
    return text;
}

void Option::setText(const wchar_t* optionText) {
    wcscpy(text, optionText);
}