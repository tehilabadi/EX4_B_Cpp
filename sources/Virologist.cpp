#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "Virologist.hpp"

namespace pandemic{
    Virologist& Virologist::treat(City city){
        if(city==myCity){
            Player::treat(city);
        }
        else if(game.getDet()[city].num==0){
            throw "there is nothing to treat viro";
        }
        else if(cards[game.getDet()[city].color][city]==0){
            throw "there isn't matching card viro";
        }
        else if(game.getCures()[game.getDet()[city].color]){
            game.getDet()[city].num=0;
            cards[game.getDet()[city].color][city]=0;
        }
        else{
            game.getDet()[city].num--;
            cards[game.getDet()[city].color][city]=0;
        }
        return *this;
    }
    string Virologist::role(){
        return "Virologist";
    }
}