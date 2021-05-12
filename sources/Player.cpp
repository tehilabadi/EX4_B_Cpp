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
            if(game.det[myCity].ne.find(city)==game.det[myCity].ne.end()&&
            game.det[city].ne.find(myCity)==game.det[city].ne.end()){
                throw "can't";
            }   
            myCity = city;
            if((this->role()=="Medic")&&game.cures[game.det[myCity].color]){
                game.world[this->myCity] = 0;
            }
            
            return *this;
        }
        Player& Player::fly_direct(City city){
            if(city==myCity){
                throw "same city";
            }
            if(cards[game.det[city].color][city]==1){
                cards[game.det[city].color][city]=0;
                myCity = city;
                if((this->role()=="Medic")&&game.cures[game.det[myCity].color]){
                    game.world[this->myCity] = 0;
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
            if(cards[game.det[myCity].color][myCity]==1){
                cards[game.det[myCity].color][myCity]=0;
                myCity = city;
                if((this->role()=="Medic")&&game.cures[game.det[this->myCity].color]){
                    game.world[this->myCity] = 0;
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
            if(!game.det[city].station||
            !game.det[myCity].station){
                throw "there is no station";
            }
            
            myCity = city;
            if((this->role()=="Medic")&&game.cures[game.det[myCity].color]){
                game.world[myCity] = 0;
            }
            
            return *this;
        }
        Player& Player::build(){
            if(cards[game.det[myCity].color][myCity]==0){
                throw "there is no card";
            }
            if(!game.det[myCity].station){
                game.det[myCity].station =true;
                cards[game.det[myCity].color][myCity]=0;
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
            if(!game.det[myCity].station){
                throw "can't discover player";
            }
            if(count<num){
                throw "there are not enough cards player";
            }
            if(!(game.cures[color])){
                game.cures[color]=true;
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
            if(game.world[myCity]==0||city!=myCity){
                throw "there is nothing to treat player";
            }
            if(game.cures[game.det[myCity].color]){
                game.world[myCity]=0;
            }
            else{
                game.world[myCity]--;
                counter--;

            }
            return *this;
        }
        string Player::role(){
            return "hi";
        }
        Player& Player::take_card(City city){
            cards[game.det[city].color][city]=1;
            return *this;
        }
        
}