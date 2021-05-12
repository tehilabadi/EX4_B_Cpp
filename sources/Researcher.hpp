#pragma once
#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    class Researcher:public Player{
        public:
        Researcher();
        Researcher(Board &board, City city):Player(board,city){}
        Researcher& discover_cure(Color color)override;
        string role()override;
    };
}