#include "../inc/characters.h"

AntiHero::AntiHero(std::string name, int32_t hp, int32_t attck, int32_t def, std::string university)
    :Hero(name,hp, attck, def){
    this->university = university;

}

Hero::Hero(std::string name, int32_t hp, int32_t attck, int32_t def) {
    this->name = name;
    this->attck_rt = attck;
    this->def_rt = def;
    this->hp = hp;
}

Hero::Hero() {
    this->name = "Joe";
    this->attck_rt = 1;
    this->def_rt = 1;
    this->hp = 1;
}

int32_t Hero::GetHp(){
    return this->hp;
}

int32_t Hero::GetAttack(){
    return this->attck_rt;
}

int32_t Hero::GetDef(){
    return this->def_rt;
}
std::string Hero::GetName(){
    return this->name;
}

std::string AntiHero::GetLaugh(){
    return this->laugh;
}

std::string AntiHero::GetUniversity(){
    return this->university;
}