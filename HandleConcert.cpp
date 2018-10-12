#include "HandleConcert.h"
#include "Concert.h"
#include <iostream>

Concert* HandleConcert::getConcertById(int id) {    
    /*
    Concert* found = nullptr;
    int i = 0;

    for (i = 0; i < num_registered_concerts; ++i) {
        if(concerts[i]->id() == id) {
            found = concerts[i];
            break;          
        }
    }
   // concert_position = i;
    return found;
    */
}

//Functions to manage Concerts
void HandleConcert::listConcerts() {
    if(concerts.empty()) {
        std::cout << "No concerts stored. \n";
    } else {
        std::cout << "CONCERTS: \n";
        for(auto it = concerts.begin(); it != concerts.end(); it++) {
            std::cout << "Id: " << (*it)->id() << " Group: " << (*it)->groupName()<< "\n";
        }
    }
}

bool HandleConcert::checkAddConcertToConcerts() {
    /*
    std::cout << "registered concert & size: " << num_registered_concerts << " & " << size_concerts << "\n";
    if(num_registered_concerts < size_concerts){
        return true;
    } else {
        return false;
    }
    */
}

bool HandleConcert::checkIfConcertsEmpty() {
    return concerts.empty();
}


void HandleConcert::addConcertToConcerts(std::string groupName, std::string place, std::string date, std::string price, std::string availableTicket) {
    Concert* concertToAdd = new Concert (code, groupName, place, date, price, availableTicket);
    concerts.push_back(concertToAdd);
    code++;  
}

void HandleConcert::updateConcert(int id) {
    int position = -1;    
    if(getConcertById(id, position) != nullptr) {        
        std::cout << "Concert found. \n";
        std::cout << "Id: " << concerts.at(position)->id() << "\n";
        
        std::string group_name, place, date, price, available_ticket;
        
        std::cout << "Group name: " << concerts.at(position)->groupName() << "\n";
        std::cout << "New group name: ";       
        std::cin.ignore();
        std::getline (std::cin,group_name);
        if(!group_name.empty()) {
            concerts.at(position)->setGroupName(group_name);
        }

        std::cout << "Place: " << concerts.at(position)->place() << "\n";
        std::cout << "New place: " ;
        std::getline (std::cin,place);  
        if(!place.empty()) {
            concerts.at(position)->setPlace(place);
        }             

        std::cout << "Date: " << concerts.at(position)->date() << "\n";
        std::cout << "New date: " ;
        std::getline (std::cin,date);
        if(!date.empty()) {
            concerts.at(position)->setDate(date);
        }
        std::cout << "Price: " << concerts.at(position)->price() << "\n";
        std::cout << "New price: " ;
        std::getline (std::cin,price);        
        if(!price.empty()) {
            concerts.at(position)->setPrice(price);
        }
        std::cout << "Available ticket: " << concerts.at(position)->availableTicket() << "\n";
        std::cout << " New available ticket: " ;
        std::getline (std::cin,available_ticket);
        if(!available_ticket.empty()) {
            concerts.at(position)->setAvailableTicket(available_ticket);
        }

    } else {
        std::cout << "concert not found.";
    }
}


Concert* HandleConcert::getConcertById(int id, int& position) {   
    if(!concerts.empty()) {
        int pos = 0;
        for(auto it = concerts.begin(); it != concerts.end(); it++) {
            if ((*it)->id() == id) {
                position = pos;
                return *it;
            }
            pos ++;
        }
    }
    return nullptr;
}

void HandleConcert::shiftConcertToLeft(int startingPosition) {
    /*
    for (int j = startingPosition + 1; j < num_registered_concerts; ++j) {
        concerts[j-1] = concerts[j];
        concerts[j] = nullptr;
    }
    */
}

void HandleConcert::deleteConcert(int id) {
    int concert_position = -1;
    if(getConcertById(id, concert_position) != nullptr) {
        //check if concert is in favourite and delete from it.
        deleteConcertToPreferred(id);
        concerts.erase(concerts.begin() + concert_position);
    }
}

void HandleConcert::getConcertDetails(int id) { 
    int position = -1;
    if(getConcertById(id, position) != nullptr) {
        std::cout << "CONCERT: \n" << "Id: " << concerts.at(position)->id()<< " Group: " << concerts.at(position)->groupName()<< "\n";
        std::cout << "\tPlace: " << concerts.at(position)->place() << " Date: " << concerts.at(position)->date()<< "\n";
        std::cout << "\tPrice: " << concerts.at(position)->price() << "$ Available Ticket: " << concerts.at(position)->availableTicket()<< "\n";   
    } else {
        std::cout << "No concert found with this id. \n";
    }
}


//Functions to manage preferred
void HandleConcert::addConcertToPreferred(int id) {
    int position = -1;
    Concert* found = getConcertById(id, position);
    if(found != nullptr) {
        preferredConcerts.push_back(found);
    } else {
        std::cout << "Id not found. Impossible to add to preferred. \n";
    }
}

void HandleConcert::listPreferredConcerts() {
    if(preferredConcerts.empty()) {
        std::cout << "No concerts in favourite. \n";
    } else {
        std::cout << "FAVOURITE CONCERTS: \n";
        for(auto it = preferredConcerts.begin(); it != preferredConcerts.end(); it++) {       
            std::cout  << "Id: " << (*it)->id() << "\tGroup: " << (*it)->groupName()<< "\n";
            std::cout << "\tPlace: " << (*it)->place() << " Date: " << (*it)->date()<< "\n";
            std::cout << "\tPrice: " << (*it)->price() << "$ Available Ticket: " << (*it)->availableTicket()<< "\n";
        }
    }
}


bool HandleConcert::checkIfPreferredEmpty() {
    return preferredConcerts.empty();
}

bool HandleConcert::checkAddConcertToPreferred() {
    /*
    if(num_preferred_concerts < size_preferred){
        return true;
    } else {
        return false;
    }
    */
}



void HandleConcert::deleteConcertToPreferred(int id) {
    int position = -1;

    if(getPreferredById(id, position) != nullptr) {
        
        preferredConcerts.erase(preferredConcerts.begin() + position);
        std::cout << "Concert successfully deleted from preferred. \n";
    } else {
        std::cout << "Concert not found in preferred. \n";
    }
}

Concert* HandleConcert::getPreferredById(int id, int& position) {
    int i = 0;
    for(auto it = preferredConcerts.begin(); it != preferredConcerts.end(); it++) {
        if((*it)->id() == id) {
            position = i;
            return *it;
        }
        i++;
    }
    return nullptr;
}
