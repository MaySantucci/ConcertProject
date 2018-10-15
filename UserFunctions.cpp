#include "UserFunctions.h"
#include "Concert.h"
#include <iostream>

//Functions to manage Events

void UserFunctions::insertEvent(std::string type_event) {
    showForm(name, place, date, price, availableTicket);

    if(type_event == "a") {
        //add Show to Events
        std::cout << "Show. \n";
    } else if (type_event == "b") {
        //add Ballet to Events        
        std::cout << "Ballet. \n";
    } else if (type_event == "c") {
        //add Concert to Events        
        std::cout << "Concert. \n";
    }
}


//Functions to manage Concerts
void UserFunctions::listConcerts() {
    handler->listConcerts();
}

void UserFunctions::detailsConcert(int id) {  
    handler->getConcertDetails(id);
}

void UserFunctions::insertConcert() {
    //showForm();
}

void UserFunctions::showForm(std::string& n, std::string& pl, std::string& d, std::string& pr, std::string& ticket){
        std::cout << "name: " ;
        std::cin.ignore();
        std::getline (std::cin,n);

        std::cout << "Place: " ;
        std::getline (std::cin,pl);

        std::cout << "Date: " ;
        std::getline (std::cin,d);

        std::cout << "Price: " ;
        std::getline (std::cin,pr);

        std::cout << "Available ticket: " ;
        std::getline (std::cin, ticket);

        handler->addConcertToConcerts(n, pl, d, pr, ticket);
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
        handler->addConcertToPreferred(id);
}

void UserFunctions::deletePreferred(int id){
    handler->deleteConcertToPreferred(id);
}
