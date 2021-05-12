#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "FieldDoctor.hpp"

namespace pandemic{
    FieldDoctor& FieldDoctor::treat(City city){
        if(game.world[city]==0){
            throw "nothing to treat Doc";
        }
        if(city!=myCity&&(game.det[myCity].ne.find(city)==game.det[myCity].ne.end())&&
        game.det[city].ne.find(myCity)==game.det[city].ne.end()){
            throw "can't treat Doc";
        }
        
            if(game.cures[game.det[city].color]){
                game.world[city]=0;
            }
            else{
                game.world[city]--;
            }
        
        return *this;
    }
    string FieldDoctor::role(){
        return "FieldDoctor";
    }
}
