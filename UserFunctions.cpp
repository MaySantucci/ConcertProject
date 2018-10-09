#include "UserFunctions.h"
#include "Concert.h"
#include <iostream>
//Functions to manage Concerts
void UserFunctions::listConcerts() {
    handler->listConcerts();
}


void UserFunctions::detailsConcert(int id) {  
    handler->getConcertDetails(id);
}

void UserFunctions::insertConcert() {
    if(handler->checkAddConcertToConcerts()){
        showForm();
    } else {
        handler->resizeConcerts();
        showForm();
    }
}

void UserFunctions::showForm(){
        std::string input;

        std::cout << "Group name: " ;
        std::cin >> input;
        group_name = std::string(input);

        std::cout << "Place: " ;
        std::cin >> input;
        place = std::string(input);

        std::cout << "Date: " ;
        std::cin >> input;
        date = std::string(input);

        std::cout << "Price: " ;
        std::cin >> input;
        price = std::string(input);

        std::cout << "Available ticket: " ;
        std::cin >> input;
        available_ticket = std::string(input);

        handler->addConcertToConcerts(group_name, place, date, price, available_ticket);

}

bool UserFunctions::checkConcertsInit() {
    handler->checkIfConcertsEmpty();
}

void UserFunctions::updateConcert(int id) {
    std::cout << "Update concert. \n";
    handler->updateConcert(id);
}

void UserFunctions::deleteConcert(int id) {
    handler->deleteConcert(id);
}

//Functions to manage Prefered
void UserFunctions::listPreferedConcerts() {
    handler->listPreferedConcerts();
}
void UserFunctions::insertPrefered(int id) {
    if(handler->checkAddConcertToPrefered()){
        handler -> addConcertToPrefered(id);
    } else {
        handler->resizePrefered();
        handler->addConcertToPrefered(id);
    }
}

void UserFunctions::deletePrefered(int id){
    handler->deleteConcertToPrefered(id);
}
