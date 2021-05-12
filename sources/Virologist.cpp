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
        else if(game.world[city]==0){
            throw "there is nothing to treat viro";
        }
        else if(cards[game.det[city].color][city]==0){
            throw "there isn't matching card viro";
        }
        else if(game.cures[game.det[city].color]){
            game.world[city]=0;
            cards[game.det[city].color][city]=0;
        }
        else{
            game.world[city]--;
            cards[game.det[city].color][city]=0;
        }
        return *this;
    }
    string Virologist::role(){
        return "Virologist";
    }
}