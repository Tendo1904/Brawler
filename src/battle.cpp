#include "../inc/battle.h"

void Battle::Announcer(Hero one, Hero two, int32_t punch){
    std::cout<<one.GetName()<<" attacks "<<two.GetName()<<" and deals "<<punch<<" damage"<<std::endl;
    std::cout<<two.GetName()<<" is down to "<<two.GetHp()<<std::endl;
}
void Battle::StartFight(Hero one, Hero two){
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
void Battle::Victory(Hero one, Hero two){
    if (one.GetHp() > two.GetHp()){
        std::cout<<two.GetName()<<" has died and "<<one.GetName()<<" was Victorious"<<std::endl;
    } else {
        std::cout<<one.GetName()<<" has died and "<<two.GetName()<<" was Victorious"<<std::endl;
    }
    std::cout<<"Game Over"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
}