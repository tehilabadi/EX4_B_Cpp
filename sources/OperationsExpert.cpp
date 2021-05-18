#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "OperationsExpert.hpp"

namespace pandemic{
   
    OperationsExpert& OperationsExpert::build(){
        game.getDet()[myCity].station=true;     
        return *this;
    }
    string OperationsExpert::role(){
        return "OperationsExpert";
    }

}