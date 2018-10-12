#include "HandleConcert.h"
#include "Concert.h"
#include <iostream>

HandleConcert::HandleConcert() {
    //size_concerts = 1;
    size_preferred = 1;
    //concerts = new Concert* [size_concerts];
    preferredConcerts = new Concert* [size_preferred];
}

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
    /*
    int position = -1;
    Concert* found = getConcertById(id, position);

    if (found != nullptr) {
        // delete from preferred list         
        deleteConcertToPreferred(id);
        

        delete found;
        concerts[position] = nullptr;

        // shift elements after deleted concert to the left to fill the array
        shiftConcertToLeft(position);
    
        num_registered_concerts--;

    } else {
        std::cout << "No concert found. \n";
    }

    std::cout << "num elem after delete: " << num_registered_concerts << "\n";
    */
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


Concert* HandleConcert::getPreferredById(int id, int& position) {
   /*
    for(int i = 0; i < num_preferred_concerts; ++i) {
        if(preferredConcerts[i]->id() == id) {
            position = i;
            return preferredConcerts[i];
        }
    }
    return nullptr;
    */
}

//Functions to manage preferred
void HandleConcert::listPreferredConcerts() {
    /*
    if(preferredConcerts != nullptr && num_preferred_concerts == 0) {
        std::cout << "No concerts stored in preferred. \n";
    } else {
        std::cout << "preferred CONCERT: \n";

        for (int i = 0; i < num_preferred_concerts; i++){        
            std::cout  << "Id: " << preferredConcerts[i]->id() << "\tGroup: " << preferredConcerts[i]->groupName()<< "\n";
            std::cout << "\tPlace: " << preferredConcerts[i]->place() << " Date: " << preferredConcerts[i]->date()<< "\n";
            std::cout << "\tPrice: " << preferredConcerts[i]->price() << "$ Available Ticket: " << preferredConcerts[i]->availableTicket()<< "\n";
        }
    }
    */
}


bool HandleConcert::checkIfPreferredEmpty() {
    //return num_preferred_concerts == 0;
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

void HandleConcert::addConcertToPreferred(int id) {
    /*
    int concertPosition = -1;
    Concert* found = getConcertById(id, concertPosition);

    if(found != nullptr){
        preferredConcerts[num_preferred_concerts] = concerts[concertPosition];
        std::cout << "Concert succesfully added to preferred. \n";
        num_preferred_concerts++;
    } else {
        std::cout << "Id not found. Impossible to add to preferred. \n";
    }
    */
}

void HandleConcert::shiftPreferredToLeft(int startingPosition) {
/*
       for (int j = startingPosition + 1; j < num_preferred_concerts; ++j) {
           preferredConcerts[j-1] = preferredConcerts[j];
           preferredConcerts[j] = nullptr;
       }
*/
}

void HandleConcert::deleteConcertToPreferred(int id) {
    /*
    int startingPosition = -1;
    Concert* found = getPreferredById(id, startingPosition);

    if(found != nullptr) {

        found = nullptr;
        shiftConcertToLeft(startingPosition);
        num_preferred_concerts--;
        std::cout << "Concert successfully deleted from preferred. \n";

    } else {
        std::cout << "Concert not found in preferred. \n";
    }
    */
}

void HandleConcert::resizePreferred() {
    /*
    int newSizePreferred = size_preferred * 2;
    Concert** temp = new Concert* [newSizePreferred];
    for (int i = 0; i < size_preferred; i++){
        temp[i] = preferredConcerts[i];
    }

    delete [] preferredConcerts;
    
    size_preferred = newSizePreferred;
    preferredConcerts = temp;
    */
}
