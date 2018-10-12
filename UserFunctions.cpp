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
    showForm();
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
    handler->updateConcert(id);
}

void UserFunctions::deleteConcert(int id) {
    handler->deleteConcert(id);
}

//Functions to manage Preferred
void UserFunctions::listPreferredConcerts() {
    handler->listPreferredConcerts();
}

bool UserFunctions::checkPreferredInit() {
    handler->checkIfPreferredEmpty();
}

void UserFunctions::insertPreferred(int id) {
    if(handler->checkAddConcertToPreferred()){
        handler -> addConcertToPreferred(id);
    } else {
        std::cout << "resize.. \n";
        handler->resizePreferred();
        handler->addConcertToPreferred(id);
    }
}

void UserFunctions::deletePreferred(int id){
    handler->deleteConcertToPreferred(id);
}
