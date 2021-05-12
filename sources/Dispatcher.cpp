#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "Dispatcher.hpp"

namespace pandemic{
    
    Dispatcher& Dispatcher::fly_direct(City city){
        if(city==myCity){
                throw "same city";
        }
        if(!game.det[myCity].station&&(cards[game.det[city].color][city]==0)){
            throw "therer is no station Dispatcher";
        }
        myCity = city;
        return *this;
            
    }
    string Dispatcher::role(){
        return "Dispatcher";
    }

}