#pragma once
#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    class Medic:public Player{
        public:
        Medic(Board &board, City city):Player(board,city){
            if(game.getCures()[game.getDet()[myCity].color]){
            game.getDet()[city].num=0;
        }
        }
        Medic& treat(City city)override;
        string role()override;
    };
}

