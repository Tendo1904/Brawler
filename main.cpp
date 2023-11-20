//#include "inc/characters.h"
#include "inc/battle.h"



int main() {
    Hero thor("Thor", 120, 35, 10);
    Hero hulk("Hulk", 200, 10, 11);
    Battle::StartFight(thor, hulk);
    AntiHero prihodko("Maxim Prihod'ko", 500, 50, 1, "Vishaya Shkola of Ekonomika");
    std::cout<< prihodko.GetName()<< " of "<<prihodko.GetUniversity()<<" says:"<<std::endl;
    std::cout<< prihodko.GetLaugh()<< std::endl;
    return 0;
}