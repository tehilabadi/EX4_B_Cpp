#pragma once
#include <iostream>
#include <string>
#include "Color.hpp"
#include <set>

namespace pandemic{

    enum class City{Algiers,Atlanta,Baghdad,Bangkok,Beijing,Bogota,BuenosAires,Cairo,Chennai,Chicago,
    Delhi,Essen,HoChiMinhCity,HongKong,Istanbul,Jakarta,Johannesburg,Karachi,Khartoum,Kinshasa,
    Kolkata,Lagos,Lima,London,LosAngeles,Madrid,Manila,MexicoCity,Miami,Milan,
    Montreal,Moscow,Mumbai,NewYork,Osaka,Paris,Riyadh,SanFrancisco,Santiago,SaoPaulo,
    Seoul,Shanghai,StPetersburg,Sydney,Taipei,Tehran,Tokyo,Washington};

    class cityDetails{
        public:
        cityDetails(){}
        cityDetails(City city1, Color color1,std::string name1):city(city1),color(color1),name(name1){}
        City city;
        Color color;
        std::string name;
        int num=0;
        bool station = false;
        std::set<City> ne;
    };
}