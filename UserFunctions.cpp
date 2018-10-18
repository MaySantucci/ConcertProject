#include "UserFunctions.h"
#include <iostream>


//Functions to manage Events

void UserFunctions::listEvents() {
    std::vector<Show*> shows = handlerShow->listEvents() ;
    std::vector<Ballet*> ballets = handlerBallet->listEvents() ;
    std::vector<Concert*> concerts = handlerConcert->listEvents() ;
    if(!shows.empty()) {
        for(auto show : shows) {
            std::cout << "Id: " << show->id() << " Show: " << show->name() << "\n";
        }
    }
    if(!ballets.empty()) {
        for(auto ballet : ballets) {
            std::cout << "Id: " << ballet->id() << " Ballet: " << ballet->name() << "\n";
        }
    }
    if(!concerts.empty()) {
        for(auto concert : concerts) {
            std::cout << "Id: " << concert->id() << " Concert: " << concert->name() << "\n";
        }
    }

    if(shows.empty() && ballets.empty() && concerts.empty()) {
        std::cout << "No events stored. \n";
    }
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

void UserFunctions::insertEvent(std::string type_event) {
    showForm(name, place, date, price, availableTicket);
    
    if(type_event == "a") {
        //add Show to Events
        std::cout << "Show. \n";
        handlerShow->addEventToEvents(name, place, date, price, availableTicket);
    } else if (type_event == "b") {
        //add Ballet to Events
        std::cout << "Ballet. \n";
        handlerBallet->addEventToEvents(name, place, date, price, availableTicket);        
    } else if (type_event == "c") {
        //add Concert to Events        
        std::cout << "Concert. \n";
        handlerConcert->addEventToEvents(name, place, date, price, availableTicket);
    }
}

bool UserFunctions::checkEventsInit() {
    if(handlerShow->checkIfEventsEmpty() && handlerBallet->checkIfEventsEmpty() && handlerConcert->checkIfEventsEmpty()) {
        return true;
    }
    return false;
}


void UserFunctions::detailsEvent(int id) {
    int position = -1;
    Show* show = handlerShow->getEventById(id, position);
    Ballet* ballet = handlerBallet->getEventById(id, position);
    Concert* concert = handlerConcert->getEventById(id, position);

    if (show == nullptr && ballet == nullptr && concert == nullptr) {
        std::cout << "Event with this id not found. \n";
    } else if (show != nullptr) {
        std::cout << "Id: " << show->id() << " Name: " << show->name() << "\n";
        std::cout << "Place: " << show->place() << " Date: " << show->date() << "\n";
        std::cout << "Price: " << show->price() << " Available Ticket: " << show->availableTicket() << "\n";
    } else if (ballet != nullptr) {        
        std::cout << "Id: " << ballet->id() << " Name: " << ballet->name() << "\n";
        std::cout << "Place: " << ballet->place() << " Date: " << ballet->date() << "\n";
        std::cout << "Price: " << ballet->price() << " Available Ticket: " << ballet->availableTicket() << "\n";
    } else if (concert != nullptr) {        
        std::cout << "Id: " << concert->id() << " Name: " << concert->name() << "\n";
        std::cout << "Place: " << concert->place() << " Date: " << concert->date() << "\n";
        std::cout << "Price: " << concert->price() << " Available Ticket: " << concert->availableTicket() << "\n";
    }
}







void UserFunctions::addExtraInfo(int id) {
    //handler->addExtra(id);
}

void UserFunctions::listExtraInfo(int id) {
   // handler->printExtra(id);
}

void UserFunctions::updateExtraInfo(int id) {
    //handler->updateExtra(id);
}

void UserFunctions::deleteExtraInfo(int id) {
   //handler->deleteExtra(id);
}

void UserFunctions::updateEvent(int id) {
   // handler->updateEvent(id);
}
void UserFunctions::deleteEvent(int id){
    //handler->removeEvent(id);
}

//Functions to manage Preferred Events
void UserFunctions::listPreferredEvents() {
   // handler->listPreferredEvents();
}
bool UserFunctions::checkPreferredEventsInit() {
   // return handler->checkIfPreferredEventsEmpty();
}
void UserFunctions::insertPreferredEvent(int id) {
    //handler->addToPreferred(id);
}
void UserFunctions::deletePreferredEvent(int id) {
   // handler->removeFromPreferred(id);
} 

void UserFunctions::buyTicket(int id) {
    //handler->buyTicket(id);
}