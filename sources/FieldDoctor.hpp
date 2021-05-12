#pragma once
#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    class FieldDoctor:public Player{
        public:
        FieldDoctor(Board &board, City city):Player(board,city){}
        FieldDoctor& treat(City city)override;
        string role()override;
    };
}

