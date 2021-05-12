#pragma once
#include <iostream>
#include <unordered_map>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Board{
    public:
    Board();
    std::unordered_map<City,int> world;
    std::unordered_map<Color,bool> cures;
    std::unordered_map<City,cityDetails> det;
    void fillTheN();
    void fillCures();
    void fillTheMap();
    int& operator[](const City city);
    bool is_clean();
    std::unordered_map<Color,bool> getCures();
    std::unordered_map<City,int> getWorld();
    std::unordered_map<City,cityDetails> getDet();
    void remove_cures();
    friend std::ostream& operator<< (std::ostream& output, const Board& c);
    friend std::istream& operator>> (std::istream& input , Board& c);
    };
}