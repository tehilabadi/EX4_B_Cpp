#include <iostream>
using namespace std;
#include "Player.hpp"
#include <string>
#include "Board.hpp"


namespace pandemic{
        Player& Player::drive(City city){
            if(city==myCity){
                throw "can't";
            }
            if(game.getDet()[myCity].ne.find(city)==game.getDet()[myCity].ne.end()&&
            game.getDet()[city].ne.find(myCity)==game.getDet()[city].ne.end()){
                throw "can't";
            }   
            myCity = city;
            if((this->role()=="Medic")&&game.getCures()[game.getDet()[myCity].color]){
                game.getDet()[city].num = 0;
            }
            
            return *this;
        }
        Player& Player::fly_direct(City city){
            if(city==myCity){
                throw "same city";
            }
            if(cards[game.getDet()[city].color][city]==1){
                cards[game.getDet()[city].color][city]=0;
                myCity = city;
                if((this->role()=="Medic")&&game.getCures()[game.getDet()[myCity].color]){
                    game.getDet()[city].num = 0;
                }
            }
            else{
                throw "out_of_range";
            }
            return *this;
        }
        Player& Player::fly_charter(City city){
            if(city==myCity){
                throw "same city";
            }
            if(cards[game.getDet()[myCity].color][myCity]==1){
                cards[game.getDet()[myCity].color][myCity]=0;
                myCity = city;
                if((this->role()=="Medic")&&game.getCures()[game.getDet()[this->myCity].color]){
                    game.getDet()[city].num = 0;
                }
            }
            else{
                throw "out_of_range";
            }
            return *this;
        }
        Player& Player::fly_shuttle(City city){
            if(city==myCity){
                throw "same";
            }
            if(!game.getDet()[city].station||
            !game.getDet()[myCity].station){
                throw "there is no station";
            }
            
            myCity = city;
            if((this->role()=="Medic")&&game.getCures()[game.getDet()[myCity].color]){
                game.getDet()[city].num = 0;
            }
            
            return *this;
        }
        Player& Player::build(){
            if(cards[game.getDet()[myCity].color][myCity]==0){
                throw "there is no card";
            }
            if(!game.getDet()[myCity].station){
                game.getDet()[myCity].station =true;
                cards[game.getDet()[myCity].color][myCity]=0;
            }
            
            return *this;
        }

        Player& Player::discover_cure(Color color){
            int count = 0;
            for(pair<City,int> a:cards[color]){
                if(a.second==1){
                    count++;
                }
            }
            if(!game.getDet()[myCity].station){
                throw "can't discover player";
            }
            if(count<num){
                throw "there are not enough cards player";
            }
            if(!(game.getCures()[color])){
                game.getCures()[color]=true;
                int i = 0;
                for(auto a:cards[color]){
                    if(i<num&&(a.second==1)){
                        cards[color][a.first]=0;
                        i++;
                    }
                }
            }
            return *this;
        }
        Player& Player::treat(City city){
            if(game.getDet()[city].num==0||city!=myCity){
                throw "there is nothing to treat player";
            }
            if(game.getCures()[game.getDet()[myCity].color]){
                game.getDet()[city].num=0;
            }
            else{
                game.getDet()[city].num--;
                counter--;

            }
            return *this;
        }
        string Player::role(){
            return "hi";
        }
        Player& Player::take_card(City city){
            cards[game.getDet()[city].color][city]=1;
            return *this;
        }
        
}