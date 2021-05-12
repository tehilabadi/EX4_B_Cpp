#pragma once
#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    class Medic:public Player{
        public:
        Medic(Board &board, City city):Player(board,city){
            if(game.cures[game.det[myCity].color]){
            game.world[myCity]=0;
        }
        }
        Medic& treat(City city)override;
        string role()override;
    };
}

