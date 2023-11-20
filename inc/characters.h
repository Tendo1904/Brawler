#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstdint>


class Hero{
protected:
    int32_t attck_rt;
    int32_t def_rt;
    std::string name;
public:
    int32_t hp;
    int32_t GetHp();
    int32_t GetAttack();
    int32_t GetDef();
    std::string GetName();
    Hero(std::string, int32_t, int32_t, int32_t);
    Hero();
};

class AntiHero: public Hero{
protected:
    std::string laugh;
    std::string university;
public:
    std::string GetUniversity();
    std::string GetLaugh();
    AntiHero();
    AntiHero(std::string, int32_t, int32_t, int32_t, std::string);
};
