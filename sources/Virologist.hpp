#pragma once
#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    class Virologist:public Player{
        public:
        Virologist(Board &board, City city):Player(board,city){}
        Virologist& treat(City city)override;
        string role()override;
    };
}