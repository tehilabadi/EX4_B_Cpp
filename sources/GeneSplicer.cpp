#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "GeneSplicer.hpp"

namespace pandemic{

    GeneSplicer& GeneSplicer::discover_cure(Color color){
        int count = 0;
        for(auto &a:cards){
            for( pair<City,int> b:a.second){
                if(cards[a.first][b.first]==1){
                    count++;
                }
            }
        }
        if(!game.det[myCity].station){
                throw "can't discover GEN";
            }
        if(count<num){
                throw "not enough cards";
            }    
            if(!game.cures[color]){
                int i = 0;
                for(auto &a:cards){
                    for(auto &b:a.second){
                        if(i<num){
                        cards[a.first][b.first] = 0;
                        i++;
                    }
                    }
                }

            }
            return *this;
    }
    string GeneSplicer::role(){
        return "GeneSplicer";
    }
    
}