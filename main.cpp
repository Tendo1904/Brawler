#include <iostream>
#include "string"
#include <stdlib.h>
#include <chrono>
#include <thread>


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
    std::string laugh = "bugagagagaga";
    std::string university;
public:
    std::string GetUniversity(){return university;}
    std::string GetLaugh(){ return laugh;}
    AntiHero();
    AntiHero(std::string, int32_t, int32_t, int32_t, std::string);
};

AntiHero::AntiHero(std::string name, int32_t hp, int32_t attck, int32_t def, std::string university)
    :Hero(name,
        hp, attck, def){
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

class Battle{
public:
    static void Announcer(Hero one, Hero two, int32_t punch){
        std::cout<<one.GetName()<<" attacks "<<two.GetName()<<" and deals "<<punch<<" damage"<<std::endl;
        std::cout<<two.GetName()<<" is down to "<<two.GetHp()<<std::endl;
    }
    static void StartFight(Hero one, Hero two){
        srand (time(NULL));
        while (one.GetHp()>0 && two.GetHp()>0){
            int32_t one_punch = (rand() % (one.GetAttack()) + two.GetDef() + 1 - rand() % two.GetDef() + 1);
            two.hp -= one_punch;
            Announcer(one, two, one_punch);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (two.hp<=0){break;}
            int32_t two_punch = (rand() % (two.GetAttack()) + one.GetDef() + 1 - rand() % one.GetDef() + 1);
            one.hp -= two_punch;
            Announcer(two, one, two_punch);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        Victory(one, two);
    }
    static void Victory(Hero one, Hero two){
        if (one.GetHp() > two.GetHp()){
            std::cout<<two.GetName()<<" has died and "<<one.GetName()<<" was Victorious"<<std::endl;
        } else {
            std::cout<<one.GetName()<<" has died and "<<two.GetName()<<" was Victorious"<<std::endl;
        }
        std::cout<<"Game Over"<<std::endl;
    }
};

int main() {
    Hero thor("Thor", 120, 35, 10);
    Hero hulk("Hulk", 200, 10, 11);
    Battle::StartFight(thor, hulk);
    AntiHero prihodko("Maxim Prihod'ko", 500, 50, 1, "Vishaya Shkola of Ekonomika");
    std::cout<< prihodko.GetName()<< " of "<<prihodko.GetUniversity()<<" says:"<<std::endl;
    std::cout<< prihodko.GetLaugh()<< std::endl;
    return 0;
}