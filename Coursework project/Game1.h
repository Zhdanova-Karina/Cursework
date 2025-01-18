#define CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "string.h"
#include <locale.h>
#include <conio.h>
#include <stdio.h>

class Game1 {
private:
    bool start;

public:
    Game1() {}
    Game1(bool start) {
        this->start = start;
    }
    bool getGame() { return start; }
};
