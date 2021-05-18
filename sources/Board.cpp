#include <iostream>
using namespace std;
#include <unordered_map>
#include "Board.hpp"
#include <list>

namespace pandemic{

    
    Board::Board(){
        fillCures();
        fillTheMap();
        fillTheN();
    }

    int& Board::operator[](const City city){
        return det[city].num;
    }

    bool Board::is_clean(){
        for(auto a:det){
            if(a.second.num!=0){
                return false;
            }
        }
        return true;
    }

    void Board::remove_cures(){
        for(auto &a:cures){
            a.second = false;
        }
    }
    std::ostream& operator<< (std::ostream& output, const Board& c){
        string black;
        cout<<"_____________________pandemic board_____________________"<<endl;
        for(auto temp:c.cures){
            switch(temp.first){
                case Color::Black:
                    cout<<"Black cities:"<<temp.second<<endl;
                    for(auto a:c.det){
                        if(a.second.color==Color::Black){
                            cout<<a.second.name<<" number of cubes: "<<a.second.num<<" station: "<<a.second.station<<endl;
                        }
                    }
                    break;
                case Color::Blue:
                    cout<<"Blue cities:"<<temp.second<<endl;
                    for(auto a:c.det){
                        if(a.second.color==Color::Blue){
                            cout<<a.second.name<<" number of cubes: "<<a.second.num<<" station: "<<a.second.station<<endl;
                        }
                    }
                    break;
                case Color::Red:
                    cout<<"Red cities:"<<temp.second<<endl;
                    for(auto a:c.det){
                        if(a.second.color==Color::Red){
                            cout<<a.second.name<<" number of cubes: "<<a.second.num<<" station: "<<a.second.station<<endl;
                        }
                    }
                    break;
                case Color::Yellow:
                    cout<<"Yellow cities:"<<temp.second<<endl;
                    for(auto a:c.det){
                        if(a.second.color==Color::Yellow){
                            cout<<a.second.name<<" number of cubes: "<<a.second.num<<" station: "<<a.second.station<<endl;
                        }
                    }
                    break;
            }   
        
        }
        return output;
    }


    unordered_map<Color,bool>& Board::getCures(){
        return cures;
    }
    unordered_map<City,cityDetails>& Board::getDet(){
        return det;
    }
    unordered_map<Color,bool> Board::getCures2(){
        return cures;
    }
    unordered_map<City,cityDetails> Board::getDet2(){
        return det;
    }

    void Board::fillCures(){
        
        cures[Color::Black] = false;
        cures[Color::Blue] = false;
        cures[Color::Red] = false;
        cures[Color::Yellow] = false;

    }
    void Board::fillTheN(){
        det[City::Algiers].ne.insert(City::Madrid);
        det[City::Algiers].ne.insert(City::Paris);
        det[City::Algiers].ne.insert(City::Istanbul);
        det[City::Algiers].ne.insert(City::Cairo);

        det[City::Atlanta].ne.insert(City::Chicago);
        det[City::Atlanta].ne.insert(City::Miami);
        det[City::Atlanta].ne.insert(City::Washington);

        det[City::Baghdad].ne.insert(City::Tehran);
        det[City::Baghdad].ne.insert(City::Istanbul);
        det[City::Baghdad].ne.insert(City::Cairo);
        det[City::Baghdad].ne.insert(City::Riyadh);
        det[City::Baghdad].ne.insert(City::Karachi);

        det[City::Bangkok].ne.insert(City::Kolkata);
        det[City::Bangkok].ne.insert(City::Chennai);
        det[City::Bangkok].ne.insert(City::Jakarta);
        det[City::Bangkok].ne.insert(City::HoChiMinhCity);
        det[City::Bangkok].ne.insert(City::HongKong);

        det[City::Beijing].ne.insert(City::Shanghai);
        det[City::Beijing].ne.insert(City::Seoul);

        det[City::Bogota].ne.insert(City::Lima);
        det[City::Bogota].ne.insert(City::MexicoCity);
        det[City::Bogota].ne.insert(City::Miami);
        det[City::Bogota].ne.insert(City::SaoPaulo);
        det[City::Bogota].ne.insert(City::BuenosAires);

        det[City::BuenosAires].ne.insert(City::Bogota);
        det[City::BuenosAires].ne.insert(City::SaoPaulo);
       
        det[City::Cairo].ne.insert(City::Algiers);
        det[City::Cairo].ne.insert(City::Istanbul);
        det[City::Cairo].ne.insert(City::Baghdad);
        det[City::Cairo].ne.insert(City::Khartoum);
        det[City::Cairo].ne.insert(City::Riyadh);

        det[City::Chennai].ne.insert(City::Mumbai);
        det[City::Chennai].ne.insert(City::Delhi);
        det[City::Chennai].ne.insert(City::Kolkata);
        det[City::Chennai].ne.insert(City::Bangkok);
        det[City::Chennai].ne.insert(City::Jakarta);

        det[City::Chicago].ne.insert(City::SanFrancisco);
        det[City::Chicago].ne.insert(City::LosAngeles);
        det[City::Chicago].ne.insert(City::MexicoCity);
        det[City::Chicago].ne.insert(City::Atlanta);
        det[City::Chicago].ne.insert(City::Montreal);

        det[City::Delhi].ne.insert(City::Tehran);
        det[City::Delhi].ne.insert(City::Karachi);
        det[City::Delhi].ne.insert(City::Mumbai);
        det[City::Delhi].ne.insert(City::Chennai);
        det[City::Delhi].ne.insert(City::Kolkata);

        det[City::Essen].ne.insert(City::London);
        det[City::Essen].ne.insert(City::Paris);
        det[City::Essen].ne.insert(City::Milan);
        det[City::Essen].ne.insert(City::StPetersburg);

        det[City::HoChiMinhCity].ne.insert(City::Jakarta);
        det[City::HoChiMinhCity].ne.insert(City::Bangkok);
        det[City::HoChiMinhCity].ne.insert(City::HongKong);
        det[City::HoChiMinhCity].ne.insert(City::Manila);

        det[City::HongKong].ne.insert(City::Bangkok);
        det[City::HongKong].ne.insert(City::Kolkata);
        det[City::HongKong].ne.insert(City::HoChiMinhCity);
        det[City::HongKong].ne.insert(City::Shanghai);
        det[City::HongKong].ne.insert(City::Manila);
        det[City::HongKong].ne.insert(City::Taipei);

        det[City::Istanbul].ne.insert(City::Milan);
        det[City::Istanbul].ne.insert(City::Algiers);
        det[City::Istanbul].ne.insert(City::StPetersburg);
        det[City::Istanbul].ne.insert(City::Cairo);
        det[City::Istanbul].ne.insert(City::Baghdad);
        det[City::Istanbul].ne.insert(City::Moscow);

        det[City::Jakarta].ne.insert(City::Chennai);
        det[City::Jakarta].ne.insert(City::Bangkok);
        det[City::Jakarta].ne.insert(City::HoChiMinhCity);
        det[City::Jakarta].ne.insert(City::Sydney);

        det[City::Johannesburg].ne.insert(City::Kinshasa);
        det[City::Johannesburg].ne.insert(City::Khartoum);

        det[City::Karachi].ne.insert(City::Tehran);
        det[City::Karachi].ne.insert(City::Baghdad);
        det[City::Karachi].ne.insert(City::Riyadh);
        det[City::Karachi].ne.insert(City::Mumbai);
        det[City::Karachi].ne.insert(City::Delhi);

        det[City::Khartoum].ne.insert(City::Cairo);
        det[City::Khartoum].ne.insert(City::Lagos);
        det[City::Khartoum].ne.insert(City::Kinshasa);
        det[City::Khartoum].ne.insert(City::Johannesburg);

        det[City::Kinshasa].ne.insert(City::Lagos);
        det[City::Kinshasa].ne.insert(City::Khartoum);
        det[City::Kinshasa].ne.insert(City::Johannesburg);

        det[City::Kolkata].ne.insert(City::Delhi);
        det[City::Kolkata].ne.insert(City::Chennai);
        det[City::Kolkata].ne.insert(City::Bangkok);
        det[City::Kolkata].ne.insert(City::HongKong);

        det[City::Lagos].ne.insert(City::SaoPaulo);
        det[City::Lagos].ne.insert(City::Khartoum);
        det[City::Lagos].ne.insert(City::Kinshasa);

        det[City::Lima].ne.insert(City::MexicoCity);
        det[City::Lima].ne.insert(City::Bogota);
        det[City::Lima].ne.insert(City::Santiago);

        det[City::London].ne.insert(City::NewYork);
        det[City::London].ne.insert(City::Madrid);
        det[City::London].ne.insert(City::Essen);
        det[City::London].ne.insert(City::Paris);

        det[City::LosAngeles].ne.insert(City::SanFrancisco);
        det[City::LosAngeles].ne.insert(City::Chicago);
        det[City::LosAngeles].ne.insert(City::MexicoCity);
        det[City::LosAngeles].ne.insert(City::Sydney);

        det[City::Madrid].ne.insert(City::London);
        det[City::Madrid].ne.insert(City::NewYork);
        det[City::Madrid].ne.insert(City::Paris);
        det[City::Madrid].ne.insert(City::SaoPaulo);
        det[City::Madrid].ne.insert(City::Algiers);

        det[City::Manila].ne.insert(City::Taipei);
        det[City::Manila].ne.insert(City::SanFrancisco);
        det[City::Manila].ne.insert(City::HoChiMinhCity);
        det[City::Manila].ne.insert(City::Sydney);
        det[City::Manila].ne.insert(City::HongKong);

        det[City::MexicoCity].ne.insert(City::LosAngeles);
        det[City::MexicoCity].ne.insert(City::Chicago);
        det[City::MexicoCity].ne.insert(City::Miami);
        det[City::MexicoCity].ne.insert(City::Lima);
        det[City::MexicoCity].ne.insert(City::Bogota);

        det[City::Miami].ne.insert(City::Atlanta);
        det[City::Miami].ne.insert(City::MexicoCity);
        det[City::Miami].ne.insert(City::Washington);
        det[City::Miami].ne.insert(City::Bogota);

        det[City::Milan].ne.insert(City::Essen);
        det[City::Milan].ne.insert(City::Paris);
        det[City::Milan].ne.insert(City::Istanbul);

        det[City::Montreal].ne.insert(City::Chicago);
        det[City::Montreal].ne.insert(City::Washington);
        det[City::Montreal].ne.insert(City::NewYork);

        det[City::Moscow].ne.insert(City::StPetersburg );
        det[City::Moscow].ne.insert(City::Istanbul);
        det[City::Moscow].ne.insert(City::Tehran);

        det[City::Mumbai].ne.insert(City::Karachi);
        det[City::Mumbai].ne.insert(City::Delhi);
        det[City::Mumbai].ne.insert(City::Chennai);

        det[City::NewYork].ne.insert(City::Montreal);
        det[City::NewYork].ne.insert(City::Washington);
        det[City::NewYork].ne.insert(City::London);
        det[City::NewYork].ne.insert(City::Madrid);

        det[City::Osaka].ne.insert(City::Taipei);
        det[City::Osaka].ne.insert(City::Tokyo);

        det[City::Paris].ne.insert(City::Algiers);
        det[City::Paris].ne.insert(City::Essen);
        det[City::Paris].ne.insert(City::Madrid );
        det[City::Paris].ne.insert(City::Milan);
        det[City::Paris].ne.insert(City::London);

        det[City::Riyadh].ne.insert(City::Baghdad);
        det[City::Riyadh].ne.insert(City::Cairo);
        det[City::Riyadh].ne.insert(City::Karachi);

        det[City::SanFrancisco].ne.insert(City::LosAngeles);
        det[City::SanFrancisco].ne.insert(City::Chicago);
        det[City::SanFrancisco].ne.insert(City::Tokyo);
        det[City::SanFrancisco].ne.insert(City::Manila);

        det[City::Santiago].ne.insert(City::Lima);
      
        det[City::SaoPaulo].ne.insert(City::Bogota);
        det[City::SaoPaulo].ne.insert(City::BuenosAires);
        det[City::SaoPaulo].ne.insert(City::Lagos);
        det[City::SaoPaulo].ne.insert(City::Madrid);

        det[City::Seoul].ne.insert(City::Beijing);
        det[City::Seoul].ne.insert(City::Shanghai);
        det[City::Seoul].ne.insert(City::Tokyo);

        det[City::Shanghai].ne.insert(City::Beijing);
        det[City::Shanghai].ne.insert(City::HongKong);
        det[City::Shanghai].ne.insert(City::Taipei);
        det[City::Shanghai].ne.insert(City::Seoul);
        det[City::Shanghai].ne.insert(City::Tokyo);

        det[City::StPetersburg].ne.insert(City::Essen);
        det[City::StPetersburg].ne.insert(City::Istanbul);
        det[City::StPetersburg].ne.insert(City::Moscow);

        det[City::Sydney].ne.insert(City::Jakarta);
        det[City::Sydney].ne.insert(City::Manila);
        det[City::Sydney].ne.insert(City::LosAngeles);

        det[City::Taipei].ne.insert(City::Shanghai);
        det[City::Taipei].ne.insert(City::HongKong);
        det[City::Taipei].ne.insert(City::Osaka);
        det[City::Taipei].ne.insert(City::Manila);

        det[City::Tehran].ne.insert(City::Baghdad);
        det[City::Tehran].ne.insert(City::Moscow);
        det[City::Tehran].ne.insert(City::Karachi);
        det[City::Tehran].ne.insert(City::Delhi);

        det[City::Tokyo].ne.insert(City::Seoul);
        det[City::Tokyo].ne.insert(City::Shanghai);
        det[City::Tokyo].ne.insert(City::Osaka);
        det[City::Tokyo].ne.insert(City::SanFrancisco);

        det[City::Washington].ne.insert(City::Atlanta);
        det[City::Washington].ne.insert(City::NewYork);
        det[City::Washington].ne.insert(City::Montreal);
        det[City::Washington].ne.insert(City::Miami);
    }

void Board::fillTheMap(){
        cityDetails AlgiersD(City::Algiers,Color::Black, "Algiers" );
        pair<City,cityDetails> a(City::Algiers,AlgiersD);
        det.insert(a);

        cityDetails AtlantaD(City::Atlanta,Color::Blue, "Atlanta" );
        a={City::Atlanta,AtlantaD};
        det.insert(a);

        cityDetails BaghdadD(City::Baghdad,Color::Black, "Baghdad" );
        a={City::Baghdad,BaghdadD};
        det.insert(a);

        cityDetails BangkokD(City::Bangkok,Color::Red, "Bangkok" );
        a={City::Bangkok,BangkokD};
        det.insert(a);

        cityDetails Beijing(City::Beijing,Color::Red, "Beijing" );
        a={City::Beijing,Beijing};
        det.insert(a);

        cityDetails Bogota(City::Bogota,Color::Yellow, "Bogota" );
        a={City::Bogota,Bogota};
        det.insert(a);

        cityDetails BuenosAires(City::BuenosAires,Color::Yellow, "BuenosAires" );
        a={City::BuenosAires,BuenosAires};
        det.insert(a);
        
        cityDetails Cairo(City::Cairo,Color::Black, "Cairo" );
        a={City::Cairo,Cairo};
        det.insert(a);

        cityDetails Chennai(City::Chennai,Color::Black, "Chennai" );
        a={City::Chennai,Chennai};
        det.insert(a);

        cityDetails Chicago(City::Chicago,Color::Blue, "Chicago" );
        a={City::Chicago,Chicago};
        det.insert(a);

        cityDetails Delhi(City::Delhi,Color::Black, "Delhi" );
        a={City::Delhi,Delhi};
        det.insert(a);

        cityDetails Essen(City::Essen,Color::Blue, "Essen" );
        a={City::Essen,Essen};
        det.insert(a);

        cityDetails HoChiMinhCity(City::HoChiMinhCity,Color::Red, "HoChiMinhCity" );
        a={City::HoChiMinhCity,HoChiMinhCity};
        det.insert(a);

        cityDetails HongKong(City::HongKong,Color::Red, "HongKong" );
        a={City::HongKong,HongKong};
        det.insert(a);

        cityDetails Istanbul(City::Istanbul,Color::Black, "Istanbul" );
        a={City::Istanbul,Istanbul};
        det.insert(a);

        cityDetails Jakarta(City::Jakarta,Color::Red, "Jakarta" );
        a={City::Jakarta,Jakarta};
        det.insert(a);

        cityDetails Johannesburg(City::Johannesburg,Color::Yellow, "Johannesburg" );
        a={City::Johannesburg,Johannesburg};
        det.insert(a);

        cityDetails Karachi(City::Karachi,Color::Black, "Karachi" );
        a={City::Karachi,Karachi};
        det.insert(a);

        cityDetails Khartoum(City::Khartoum,Color::Yellow, "Khartoum" );
        a={City::Khartoum,Khartoum};
        det.insert(a);

        cityDetails Kinshasa(City::Kinshasa,Color::Yellow, "Kinshasa" );
        a={City::Kinshasa,Kinshasa};
        det.insert(a);

        cityDetails Kolkata(City::Kolkata,Color::Black, "Kolkata" );
        a={City::Kolkata,Kolkata};
        det.insert(a);

        cityDetails Lagos(City::Lagos,Color::Yellow, "Lagos" );
        a={City::Lagos,Lagos};
        det.insert(a);

        cityDetails Lima(City::Lima,Color::Yellow, "Lima" );
        a={City::Lima,Lima};
        det.insert(a);

        cityDetails London(City::London,Color::Blue, "London" );
        a={City::London,London};
        det.insert(a);

        cityDetails LosAngeles(City::LosAngeles,Color::Yellow, "LosAngeles" );
        a={City::LosAngeles,LosAngeles};
        det.insert(a);

        cityDetails Madrid(City::Madrid,Color::Blue, "Madrid" );
        a={City::Madrid,Madrid};
        det.insert(a);

        cityDetails Manila(City::Manila,Color::Red, "Manila" );
        a={City::Manila,Manila};
        det.insert(a);

        cityDetails MexicoCity(City::MexicoCity,Color::Yellow, "MexicoCity" );
        a={City::MexicoCity,MexicoCity};
        det.insert(a);

        cityDetails Miami(City::Miami,Color::Yellow, "Miami" );
        a={City::Miami,Miami};
        det.insert(a);

        cityDetails Milan(City::Milan,Color::Blue, "Milan" );
        a={City::Milan,Milan};
        det.insert(a);

        cityDetails Montreal(City::Montreal,Color::Blue, "Montreal" );
        a={City::Montreal,Montreal};
        det.insert(a);

        cityDetails Moscow(City::Moscow,Color::Black, "Moscow" );
        a={City::Moscow,Moscow};
        det.insert(a);

        cityDetails Mumbai(City::Mumbai,Color::Black, "Mumbai" );
        a={City::Mumbai,Mumbai};
        det.insert(a);

        cityDetails NewYork(City::NewYork,Color::Blue, "NewYork" );
        a={City::NewYork,NewYork};
        det.insert(a);

        cityDetails Osaka(City::Osaka,Color::Red, "Osaka" );
        a={City::Osaka,Osaka};
        det.insert(a);

        cityDetails Paris(City::Paris,Color::Blue, "Paris" );
        a={City::Paris,Paris};
        det.insert(a);

        cityDetails Riyadh(City::Riyadh,Color::Black, "Riyadh" );
        a={City::Riyadh,Riyadh};
        det.insert(a);
        
        cityDetails SanFrancisco(City::SanFrancisco,Color::Blue, "SanFrancisco" );
        a={City::SanFrancisco,SanFrancisco};
        det.insert(a);

        cityDetails Santiago(City::Santiago,Color::Yellow, "Santiago" );
        a={City::Santiago,Santiago};
        det.insert(a);

        cityDetails SaoPaulo(City::SaoPaulo,Color::Yellow, "SaoPaulo" );
        a={City::SaoPaulo,SaoPaulo};
        det.insert(a);

        cityDetails Seoul(City::Seoul,Color::Red, "Seoul" );
        a={City::Seoul,Seoul};
        det.insert(a);

        cityDetails Shanghai(City::Shanghai ,Color::Red, "Shanghai" );
        a={City::Shanghai,Shanghai};
        det.insert(a);

        cityDetails StPetersburg(City::StPetersburg ,Color::Blue, "StPetersburg" );
        a={City::StPetersburg,StPetersburg};
        det.insert(a);

        cityDetails Sydney(City::Sydney ,Color::Red, "Sydney" );
        a={City::Sydney,Sydney};
        det.insert(a);

        cityDetails Taipei(City::Taipei ,Color::Red, "Taipei" );
        a={City::Taipei,Taipei};
        det.insert(a);

        cityDetails Tehran(City::Tehran ,Color::Black, "Tehran" );
        a={City::Tehran,Tehran};
        det.insert(a);

        cityDetails Tokyo(City::Tokyo ,Color::Red, "Tokyo" );
        a={City::Tokyo,Tokyo};
        det.insert(a);

        cityDetails Washington(City::Washington ,Color::Blue, "Washington" );
        a={City::Washington,Washington};
        det.insert(a);
    }
    
}