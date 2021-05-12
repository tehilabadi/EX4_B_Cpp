#pragma once
#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    class GeneSplicer:public Player{
        public:
        GeneSplicer(Board &board, City city):Player(board,city){}
        GeneSplicer& discover_cure(Color color)override;
        string role()override;

    };
}

