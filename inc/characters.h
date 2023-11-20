#ifndef characters.h
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstdint>
#endif


class Hero{
protected:
    int32_t attck_rt;
    int32_t def_rt;
    std::string name;
public:
    int32_t hp;
    int32_t GetHp(){return hp;}
    int32_t GetAttack(){return attck_rt;}
    int32_t GetDef(){return def_rt;}
    std::string GetName(){return name;}
    Hero(std::string, int32_t, int32_t, int32_t);
    Hero();
};

class AntiHero: public Hero{
protected:
    std::string laugh;
    std::string university;
public:
    std::string GetUniversity(){return university;}
    std::string GetLaugh(){ return laugh;}
    AntiHero();
    AntiHero(std::string, int32_t, int32_t, int32_t, std::string);
};
