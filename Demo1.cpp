
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "GeneSplicer.hpp"
#include "Medic.hpp"
#include "FieldDoctor.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"


using namespace pandemic;

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	Board board; 
	board[City::Chicago] = 3;     
	board[City::Kinshasa] = 2;    
	board[City::MexicoCity] = 3;  
	board[City::Bangkok] = 1; 
	board[City::Chicago] = 1; 
	board[City::Bogota] = 5;
	cout<<"Bogota before Medic treat: "<<board[City::Bogota]<<endl;      
	Medic medic{board,City::Bogota};
	medic.take_card(City::Essen).take_card(City::London).take_card(City::Madrid).take_card(City::Milan).take_card(City::Montreal).take_card(City::Bogota);
	medic.treat(City::Bogota);
	cout<<"Bogota after Medic treat: "<<board[City::Bogota]<<endl;      
	medic.take_card(City::Essen).take_card(City::London).take_card(City::Madrid).take_card(City::Milan).take_card(City::Montreal).take_card(City::Bogota);
	medic.build();
	medic.discover_cure(Color::Blue);
	medic.take_card(City::London);
	board[City::London] = 5;
	cout<<"London before medic arrives: "<<board[City::London]<<endl;
	medic.fly_direct(City::London);
	cout<<"London after medic arrives: "<<board[City::London]<<endl;
	medic.take_card(City::Chicago).fly_direct(City::Chicago);
	board[City::LosAngeles]=5;
	FieldDoctor fieldDoctor(board,City::SanFrancisco);
	fieldDoctor.treat(City::LosAngeles).treat(City::LosAngeles).treat(City::LosAngeles).treat(City::LosAngeles);
	cout<<"LosAngeles after four treatments FieldDoctor:"<<board[City::LosAngeles]<<endl;
	// GeneSplicer geneSplicer{board,City::Bogota};
	// geneSplicer.take_card(City::Paris);
	// geneSplicer.build();
	// geneSplicer.take_card(City::Paris).take_card(City::Tokyo).take_card(City::Tehran).take_card(City::Atlanta).take_card(City::Miami);
	// geneSplicer.discover_cure(Color::Yellow);
	medic.take_card(City::MexicoCity).fly_direct(City::MexicoCity);
	cout<<"MexicoCity after curing Yellow:"<<board[City::MexicoCity]<<endl;
	Researcher researcher{board,City::Madrid};
	researcher.take_card(City::Seoul).take_card(City::Tokyo).take_card(City::Taipei).take_card(City::Sydney).take_card(City::Shanghai);
	researcher.discover_cure(Color::Red);
	board[City::Seoul]=3;
	Scientist scientist{board,City::Bogota,1};
	board.remove_cures();
	board[City::NewYork]=3;
	medic.take_card(City::NewYork).fly_direct(City::NewYork);
	scientist.take_card(City::NewYork).discover_cure(Color::Blue);
	board[City::Montreal]=1;
	medic.take_card(City::Montreal).take_card(City::NewYork).fly_direct(City::Montreal).fly_direct(City::NewYork);
	cout<<"the board before rermoving"<<endl;
	cout<<board<<endl;
	board.remove_cures();
	cout<<"the board after rermoving"<<endl;
	cout<<"does the board clean?"<<board.is_clean()<<endl;
	cout<<board<<endl;
	}

