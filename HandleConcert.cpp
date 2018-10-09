#include "HandleConcert.h"
#include "Concert.h"
#include <iostream>

HandleConcert::HandleConcert() {
    size_concerts = 1;
    size_prefered = 1;
    concerts = new Concert* [size_concerts];
    preferedConcerts = new Concert* [size_prefered];
}

//Functions to manage Concerts
void HandleConcert::listConcerts() {
    if(concerts != nullptr && num_registered_concerts == 0) {
        std::cout << "No concerts stored. \n";
    } else {
        std::cout << "CONCERTS: \n ";
        for (int i = 0; i < num_registered_concerts; i++){        
                std::cout << "Id: " << concerts[i]->id() << " Group: " << concerts[i]->groupName()<< "\n";
            //std::cout << "\tPlace: " << concerts[i]->place() << " Date: " << concerts[i]->date()<< "\n";
            //std::cout << "\tPrice: " << concerts[i]->price() << "$ Available Ticket: " << concerts[i]->availableTicket()<< "\n";

        }
     }
}

bool HandleConcert::checkAddConcertToConcerts() {
    if(num_registered_concerts < size_concerts){
        return true;
    } else {
        return false;
    }
}

bool HandleConcert::checkIfConcertsEmpty() {
    std::cout << "elementi: " << num_registered_concerts << "\n";
    return num_registered_concerts == 0;
}

void HandleConcert::addConcertToConcerts(std::string groupName, std::string place, std::string date, std::string price, std::string availableTicket){
   
    concerts[num_registered_concerts] = new Concert (code, groupName, place, date, price, availableTicket);
    num_registered_concerts ++;
    code++;
}

void HandleConcert::updateConcert(int id) {
    int results = 0;
    if (concerts != nullptr && num_registered_concerts > 0) {
        for(int i = 0; i < num_registered_concerts; i++) {
            if(concerts[i]->id() == id) {
                results ++;
                std::cout << "Concert found. \n";
                std::cout << "Id: " << concerts[i]->id() << "\n";

                std::string input;
                std::cout << "Group name: " << concerts[i]->groupName() << "\n";
                std::cout << "New group name: " ;
                std::cin >> input;
                std::string group_name = std::string(input);
                concerts[i]->setGroupName(group_name);

                std::cout << "Place: " << concerts[i]->place() << "\n";
                std::cout << "New place: " ;
                std::cin >> input;
                std::string place = std::string(input);                
                concerts[i]->setPlace(place);

                std::cout << "Date: " << concerts[i]->date() << "\n";
                std::cout << "New date: " ;
                std::cin >> input;
                std::string date = std::string(input);
                concerts[i]->setDate(date);

                std::cout << "Price: " << concerts[i]->price() << "\n";
                std::cout << "New price: " ;
                std::cin >> input;
                std::string price = std::string(input);
                concerts[i]->setPrice(price);

                std::cout << "Available ticket: " << concerts[i]->availableTicket() << "\n";
                std::cout << " New available ticket: " ;
                std::cin >> input;
                std::string available_ticket = std::string(input);
                concerts[i]->setAvailableTicket(available_ticket);
                break;
            }
        }
    } else {
        std::cout << "no concerts.";
    }

}

void HandleConcert::deleteConcert(int id) {
    bool found = false;
    int results;
    for(int i = 0; i < num_registered_concerts; i ++) {
        if(concerts[i]->id() == id) {
            found = true;
            results = i;
            break;          
        }
    }
    if(found) {
        deleteConcertToPrefered(id);
        for (int i = results ; i < num_registered_concerts; i++) {
                    
            if(results == num_registered_concerts - 1){        
                concerts[results] = nullptr;
            } else {
                concerts[i] = concerts[i+1];
            }
    }
        
        delete concerts[results];
        concerts[results] = nullptr;
        num_registered_concerts--;

    } else {
            std::cout << "No concert found. \n";
    }
}

void HandleConcert::getConcertDetails(int id) { 
    int results = 0;
    if (concerts != nullptr && num_registered_concerts > 0) {
        for(int i = 0; i < num_registered_concerts; i++) {
            if(concerts[i]->id() == id) {
                results ++;
                std::cout << "CONCERT: \n " << "Id: " << concerts[i]->id() << " Group: " << concerts[i]->groupName()<< "\n";
                std::cout << "\tPlace: " << concerts[i]->place() << " Date: " << concerts[i]->date()<< "\n";
                std::cout << "\tPrice: " << concerts[i]->price() << "$ Available Ticket: " << concerts[i]->availableTicket()<< "\n";
                break;
            }
        }
    } else {
        std::cout << "No concerts.";
    }

    if(results == 0) {
        std::cout << "No concert with this id. \n";
    }
}

void HandleConcert::resizeConcerts() {
    std::cout << "resize..\n";
    int newSizeConcerts = size_concerts * 2;
    Concert** temp = new Concert* [newSizeConcerts];
    for (int i = 0; i < size_concerts; i++){
        temp[i] = concerts[i];
    }

    delete [] concerts;
    
    size_concerts = newSizeConcerts;
    concerts = temp;
       
}


//Functions to manage Prefered
void HandleConcert::listPreferedConcerts() {
    if(preferedConcerts != nullptr && num_prefered_concerts == 0) {
        std::cout << "No concerts stored in prefered. \n";
    } else {
        std::cout << "PREFERED CONCERT: \n";

        for (int i = 0; i < num_prefered_concerts; i++){        
            std::cout  << "Id: " << preferedConcerts[i]->id() << " Group: " << preferedConcerts[i]->groupName()<< "\n";
            std::cout << "\tPlace: " << concerts[i]->place() << " Date: " << concerts[i]->date()<< "\n";
            std::cout << "\tPrice: " << concerts[i]->price() << "$ Available Ticket: " << concerts[i]->availableTicket()<< "\n";

        }
     }
}

bool HandleConcert::checkAddConcertToPrefered() {
    if(num_prefered_concerts < size_prefered){
        return true;
    } else {
        return false;
    }
}

void HandleConcert::addConcertToPrefered(int id){
    bool found = false;
    int i;
    for (i= 0; i < num_registered_concerts; i ++) {
        if(concerts[i]->id() == id) {
            found = true;
            break;
        }
    }
    if(found){
        preferedConcerts[num_prefered_concerts] = concerts[i];
        std::cout << "Concert succesfully added to prefered. \n";
        num_prefered_concerts++;
    } else {
        std::cout << "Id not found. Impossible to add to prefered. \n";
    }

}

void HandleConcert::deleteConcertToPrefered(int id){
    int results = 0;
    bool found = false;
    std::cout << "id " << id << "\n";
    if(num_prefered_concerts == 0){
        std::cout << "There are not some prefered concerts. \n";
    } else {
        std::cout << "sono nell'else. \n";
        for (int i = 0; i < num_prefered_concerts; i++) {
            std::cout << "prefered id: " << preferedConcerts[i]->id() << "\n";
            if(preferedConcerts[i]->id() == id){
                found = true;
                delete preferedConcerts[i];
                preferedConcerts[i] = nullptr;
               std::cout << "Concert deleted from prefered. \n";
                results = i;
                break;
            }
        }
        if(found) {
            for(int i = results; i < num_prefered_concerts; i++){
                preferedConcerts[i] = preferedConcerts[i+1];
            }
            num_prefered_concerts--;
            std::cout << "Concert successfully deleted. \n";
        } else {
            std::cout << "Concert not deleted. \n";
        }
    }
}

void HandleConcert::resizePrefered() {

    std::cout << "resize.. \n";
    int newSizePrefered = size_prefered * 2;
    Concert** temp = new Concert* [newSizePrefered];
    for (int i = 0; i < size_prefered; i++){
        temp[i] = preferedConcerts[i];
    }

    delete [] preferedConcerts;
    
    size_prefered = newSizePrefered;
    preferedConcerts = temp;
}