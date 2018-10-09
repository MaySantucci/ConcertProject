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
        std::cout << "resize.. \n";
        handler->resizeConcerts();
        showForm();
    }
}

void UserFunctions::showForm(){

        std::cout << "Group name: " ;
        std::cin.ignore();
        std::getline (std::cin,group_name);

        std::cout << "Place: " ;
        std::getline (std::cin,place);

        std::cout << "Date: " ;
        std::getline (std::cin,date);

        std::cout << "Price: " ;
        std::getline (std::cin,price);

        std::cout << "Available ticket: " ;
        std::getline (std::cin,available_ticket);

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

bool UserFunctions::checkPreferedInit() {
    handler->checkIfPreferedEmpty();
}

void UserFunctions::insertPrefered(int id) {
    if(handler->checkAddConcertToPrefered()){
        handler -> addConcertToPrefered(id);
    } else {
        std::cout << "resize.. \n";
        handler->resizePrefered();
        handler->addConcertToPrefered(id);
    }
}

void UserFunctions::deletePrefered(int id){
    handler->deleteConcertToPrefered(id);
}
