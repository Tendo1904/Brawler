#ifndef battle.h
#include <iostream>
#include <chrono>
#include <thread>
#include "characters.h"
#endif

class Battle{
public:
    static void Announcer(Hero, Hero, int32_t);
    static void StartFight(Hero, Hero);
    static void Victory(Hero, Hero);
};