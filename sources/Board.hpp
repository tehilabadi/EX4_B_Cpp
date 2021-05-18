#pragma once
#include <iostream>
#include <unordered_map>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Board{
    std::unordered_map<Color,bool> cures;
    std::unordered_map<City,cityDetails> det;
    void fillTheN();
    void fillCures();
    void fillTheMap();
    public:
    Board();
    int& operator[](const City city);
    bool is_clean();
    std::unordered_map<Color,bool>& getCures();
    std::unordered_map<City,cityDetails>& getDet();
    std::unordered_map<Color,bool> getCures2();
    std::unordered_map<City,cityDetails> getDet2();
    void remove_cures();
    friend std::ostream& operator<< (std::ostream& output, const Board& c);
    friend std::istream& operator>> (std::istream& input , Board& c);
    };
}