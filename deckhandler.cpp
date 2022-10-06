#include <iostream>
#include <string>
#include <optional>
#include <Windows.h>

std::string front [10][20];
std::string back [10][20];
std::string decknames [10];
int decknums [10];
size_t deckcount {};

void draw(const int& a, const char& c);

bool check_data(const std::string& str, int& number){
    
    try{
        number = std::stoi(str);
        
    }catch(std::invalid_argument){
        std::cout << "What you typed was not valid" << std::endl;
        Sleep(1000);
        return false;
    }
    
    return true;
}

void makedeck(){

    std::string word, definition;

    
    //Check the user wants to before hand

    std::string check;

    std::cout << "Are you sure that you want to make a new deck?" << std::endl;

    std::cin >> check;

    if(check!="yes" && check!="Yes" && check!="YES" && check!="Y" && check!="y"){
        return;
    }

    //Making the decks

    size_t wordcount {};
    std::string choice;


    std::cout << "What do you want to name this deck?" << std::endl;

    std::getline(std::cin >> std::ws, decknames[deckcount]);

    do{
    std::string temp1, temp2;
        system("cls");
        std::cout << "Type \"done\" when your are done" << std::endl;
        draw(50,'-');
        std::cout << "Word #" << wordcount+1 << std::endl;

        std::cin >> temp1;
        draw(50,'-');

        std::cout << "Enter Definition" << std::endl;

        std::cin >> temp2;
        draw(50,'-');

        std::cout << "Ready to add these on or do you want to restart?" << std::endl;

        std::cin >> choice;

        if(choice=="no" || choice=="No" || choice=="N" || choice=="n")
            continue;  

        front[deckcount][wordcount] = temp1;
        back[deckcount][wordcount++] = temp2;

        
    }while(choice!="done");

    decknums[deckcount] = wordcount;

    std::cout << "Deck finished" << std::endl;
    ++deckcount;
    Sleep(1000);
    
    
}

void displaydeck(){
    
    std::string checknum;
    int actualnum;
    bool end {false}; //In case the user wants to run it again

    
    do{
        system("cls");
        if(deckcount==0){
        std::cout << "Sorry but you don't have any decks" << std::endl;
        Sleep(1000);
        break;
        }
        
        std::cout << "\tALL DECKS (\"exit\") to go back" << std::endl;
        draw(50 ,'-');
        for(size_t i{}; i<deckcount; ++i){
            
            std::cout << "\t" << (i+1) << ". " << decknames[i] << std::endl;
        }
        draw(50 ,'-');

        std::cin >> checknum;


        
        if(checknum=="exit"){
            break;
            
        }
        
        if(!check_data(checknum,actualnum)){
            continue;
        }
        
        //Displaying the deck
        
        actualnum-=1; //Because I changed the numbers by 1 for looks


    //Getting the size of the array
        int amountindeck = decknums[actualnum];

        --amountindeck;



        std::string temp;

        //Key : 
        // Def = Give user the definition
        // Done = Let user leave

        bool continuefactor {false};


        do{


        system("cls");
        draw(50,'-');
        std::cout << "\tDeck : " << decknames[actualnum] << std::endl;
        draw(50,'-');
        std::cout << "\t\"exit\" to leave, \"def\" for the definition" << std::endl;
        draw(50,'-');

        std::cout << "Word : " << front[actualnum][amountindeck] << std::endl;

        std::cout << "Definition : ";

        std::cin >> temp;

        if(temp=="def"){
            std::cout << "The definition is : " << back[actualnum][amountindeck] << std::endl;
            system("pause");
            continue;
        }

        if(temp=="exit" || temp=="Exit"){
            end = true;
            continue;
        }

        if(temp != back[actualnum][amountindeck]){
            std::cout << "You got it wrong..." << std::endl;
            Sleep(1200);
            continue;
        }

        
        
        --amountindeck;
        }while(amountindeck!=-1);

        system("cls");

    std::cout << "You have finished the deck" << std::endl;

    std::string again;

    std::cout << "Would you like to do this again?" << std::endl;

    std::cin >> again;

    end = (again=="y" || again=="Y" || again=="Yes" || again=="yes") ? false : true;

    }while(!end);

    
}

void draw(const int& a, const char& c){
    for(size_t i{}; i<a; ++i){
        std::cout << " " << c;
    }
    
    std::cout << std::endl;
}