#pragma warning(disable : 4996)
#define CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "string.h"
#include <locale.h>
#include <conio.h>
#include <stdio.h>

class Game {
private:
    bool start;

public:
    Game() {}
    Game(bool start) {
        this->start = start;
    }
    bool getGame() { return start; }
};
