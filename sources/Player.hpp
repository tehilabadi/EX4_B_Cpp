#pragma once
#include <iostream>
using namespace std;
#include "Board.hpp"
#include <unordered_map>


namespace pandemic{
    class Player{
        protected:
        Board &game;
        int num;
        int counter;
        City myCity;
        std::unordered_map<Color,std::unordered_map<City,int>>cards;
        public:
        Player(Board &board, City city):game(board), myCity(city), num(5){}
        Player(Board &board, City city, int num1):game(board), myCity(city), num(num1){}
        virtual Player& drive(City city);
        virtual Player& fly_direct(City city);
        virtual Player& fly_charter(City city);
        virtual Player& fly_shuttle(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color color);
        virtual Player& treat(City city);
        virtual std::string role();
        Player& take_card(City city);
    };
}