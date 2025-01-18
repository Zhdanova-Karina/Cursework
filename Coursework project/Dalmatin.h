#define CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "string.h"
#include <locale.h>
#include <conio.h>
#include <stdio.h>

class Dalmatin {
private:
    bool found;

public:
    Dalmatin() {}
    Dalmatin(bool found) {
        this->found = found;
    }

    bool getDalmatinFound() { return found; }
};

