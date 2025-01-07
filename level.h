#pragma warning(disable : 4996)
#define CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "string.h"
#include <locale.h>
#include <conio.h>
#include <stdio.h>

#include "Game.h"

class Level {
private:
    bool lvl = false;
    bool answer;

public:
    Level(){}
    Level(bool begin) {
        lvl = begin;
    }
   
    bool getlvl() { return lvl; }

    int PrintLocationPlace(Level& level, int countPlace);
    void dalmatianFound(Level& level, Game& game, int number);
};
