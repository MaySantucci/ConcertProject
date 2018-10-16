#include "UserFunctions.h"
#include "Concert.h"
#include <iostream>

//Functions to manage Events

void UserFunctions::listEvents() {
    handler->listEvents();
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
}

void UserFunctions::addExtraInfo(int id) {
    handler->addExtra(id);
}

void UserFunctions::insertEvent(std::string type_event) {
    showForm(name, place, date, price, availableTicket);

    if(type_event == "a") {
        //add Show to Events
        std::cout << "Show. \n";
        handler->addShowToEvents(name, place, date, price, availableTicket);
    } else if (type_event == "b") {
        //add Ballet to Events
        std::cout << "Ballet. \n";
        handler->addBalletToEvents(name, place, date, price, availableTicket);        
    } else if (type_event == "c") {
        //add Concert to Events        
        std::cout << "Concert. \n";
        handler->addConcertToEvents(name, place, date, price, availableTicket);
    }
}
bool UserFunctions::checkEventsInit(){
    return handler->checkIfEventsEmpty();
}
void UserFunctions::detailsEvent(int id) {
    handler->getEventDetails(id);
}
void UserFunctions::updateEvent(int id) {
    handler->updateEvent(id);
}
void UserFunctions::deleteEvent(int id){
    handler->removeEvent(id);
}

//Functions to manage Preferred Events
void UserFunctions::listPreferredEvents() {
    handler->listPreferredEvents();
}
bool UserFunctions::checkPreferredEventsInit() {
    return handler->checkIfPreferredEventsEmpty();
}
void UserFunctions::insertPreferredEvent(int id) {
    handler->addToPreferred(id);
}
void UserFunctions::deletePreferredEvent(int id) {
    handler->removeFromPreferred(id);
} 