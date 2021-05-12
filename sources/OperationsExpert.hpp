#pragma once
#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    class OperationsExpert:public Player{
        public:
        OperationsExpert(Board &board, City city):Player(board,city){}
        OperationsExpert& build()override;
        string role() override;
    };
}

