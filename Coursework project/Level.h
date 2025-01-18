#pragma warning(disable : 4996)
#define CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "string.h"
#include <locale.h>
#include <conio.h>
#include <stdio.h>

class Level {
private:
    bool lvl = false;
public:
    Level() {}
    Level(bool begin) {
        lvl = begin;
    }

    bool getlvl() { return lvl; }
};
