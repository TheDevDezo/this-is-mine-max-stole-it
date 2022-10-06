//Flash card software
#include <iostream>
#include <string>
#include <Windows.h>

//Custom libraries
#include "functions.h"

using std::cout,std::endl,std::cin;


template<typename T>

T print(const T& a){
    std::cout << a << std::endl;
}


void drawline(const int& a, const char& b);


int main(int argc, char** argv){
    
    std::string number;
    int intnumber;
    
    auto check_value = [&]()-> bool {
        
        try{
            intnumber = std::stoi(number);
        }catch(std::invalid_argument){
            std::cout << "What you typed was invalid" << std::endl;
            Sleep(1000);
            return false;
        }
        
        return true;
    };
    
    do{
        system("cls");
        
        std::cout << "\tMenu" << endl;
        drawline(50,'-');
        cout << "\t 1. Make new deck" << endl;
        cout << "\t 2. Study decks" << endl;
        cout << "\t 3. Leave" << endl;
        drawline(50,'-');
        cin >> number;
        
        
        if(!check_value()){
            continue;
        }
        
        if(intnumber!=1 && intnumber!=2 && intnumber!=3){
            std::cout << "What you typed was not a choice" << endl;
            Sleep(1000);
            continue;
        }
        
        //Different output based off of input
        
        switch(intnumber){
            case 1:
            makedeck();
            break;
            case 2:
            displaydeck();
            break;
            
        }
        
    }while(intnumber!=3);
}

void drawline(const int& a, const char& b){
    for(size_t i{}; i<a; ++i){
        std::cout << " " << b;
    }
    
    std::cout << std::endl;
}