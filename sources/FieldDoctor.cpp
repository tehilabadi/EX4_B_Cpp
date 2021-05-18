#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "FieldDoctor.hpp"

namespace pandemic{
    FieldDoctor& FieldDoctor::treat(City city){
        if(game.getDet()[city].num==0){
            throw "nothing to treat Doc";
        }
        if(city!=myCity&&(game.getDet()[myCity].ne.find(city)==game.getDet()[myCity].ne.end())&&
        game.getDet()[city].ne.find(myCity)==game.getDet()[city].ne.end()){
            throw "can't treat Doc";
        }
        
            if(game.getCures()[game.getDet()[city].color]){
                game.getDet()[city].num=0;
            }
            else{
                game.getDet()[city].num--;
            }
        
        return *this;
    }
    string FieldDoctor::role(){
        return "FieldDoctor";
    }
}
