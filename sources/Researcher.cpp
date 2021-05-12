#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "Researcher.hpp"

namespace pandemic{
    Researcher& Researcher::discover_cure(Color color){
        if(game.cures[color]){
        return  *this;
        }
        int count = 0;
        for(auto a:cards[color]){
            if(a.second==1){
                count +=1;
            }
        }
        if(count<num){
            throw "not enough cards reasercher";
        }
        game.cures[color]=true;
        int i = 0;
        for(auto a:cards[color]){
            if(i<num){
            if(a.second==1){
                cards[color][a.first]=0;
                i++;
            }
            }
        }
        return *this;

    }
    string Researcher::role(){
        return "Researcher";
    }
}