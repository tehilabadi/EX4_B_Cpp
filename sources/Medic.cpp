#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "Medic.hpp"

namespace pandemic{
    
    Medic& Medic::treat(City city){
        if(game.getDet()[city].num==0){
            throw "there is nothing to treat medic";
        }
        game.getDet()[city].num=0;
        return *this;
    }
    string Medic::role(){
        return "Medic";
    }    


}