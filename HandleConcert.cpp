#include "HandleConcert.h"
#include "Concert.h"
#include <iostream>

HandleConcert::HandleConcert() {
    size_concerts = 1;
    size_preferred = 1;
    concerts = new Concert* [size_concerts];
    preferredConcerts = new Concert* [size_preferred];
}

Concert* HandleConcert::getConcertById(int id) {    
    Concert* found = nullptr;
    int i = 0;

    for (i = 0; i < num_registered_concerts; ++i) {
        if(concerts[i]->id() == id) {
            found = concerts[i];
            break;          
        }
    }
    concert_position = i;
    return found;
}
//Functions to manage Concerts
void HandleConcert::listConcerts() {
    if(concerts != nullptr && num_registered_concerts == 0) {
        std::cout << "No concerts stored. \n";
    } else {
        std::cout << "CONCERTS: \n";
        for (int i = 0; i < num_registered_concerts; i++){        
                std::cout << "Id: " << concerts[i]->id() << " Group: " << concerts[i]->groupName()<< "\n";
        }
     }
}

bool HandleConcert::checkAddConcertToConcerts() {
    std::cout << "registered concert & size: " << num_registered_concerts << " & " << size_concerts << "\n";
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

bool HandleConcert::checkIfPreferredEmpty() {
    std::cout << "elementi: " << num_preferred_concerts << "\n";
    return num_preferred_concerts == 0;
}

void HandleConcert::addConcertToConcerts(std::string groupName, std::string place, std::string date, std::string price, std::string availableTicket) {
   
    std::cout << "before num_registered_concerts: " << num_registered_concerts << "\n";
    std::cout << groupName << " " << place << " " << date << " " << price << " " << availableTicket << "\n";
    concerts[num_registered_concerts] = new Concert (code, groupName, place, date, price, availableTicket);
    num_registered_concerts ++;
    code++;  
    std::cout << "after num_registered_concerts: " << num_registered_concerts << "\n";
 
}

void HandleConcert::updateConcert(int id) {
    Concert * found = getConcertById(id);
    
    if(found != nullptr) {        
        std::cout << "Concert found. \n";
        std::cout << "Id: " << concerts[concert_position]->id() << "\n";

        std::string input;
        std::cout << "Group name: " << concerts[concert_position]->groupName() << "\n";
        std::cout << "New group name: " ;
        std::cin >> input;
        std::string group_name = std::string(input);
        concerts[concert_position]->setGroupName(group_name);

        std::cout << "Place: " << concerts[concert_position]->place() << "\n";
        std::cout << "New place: " ;
        std::cin >> input;
        std::string place = std::string(input);                
        concerts[concert_position]->setPlace(place);

        std::cout << "Date: " << concerts[concert_position]->date() << "\n";
        std::cout << "New date: " ;
        std::cin >> input;
        std::string date = std::string(input);
        concerts[concert_position]->setDate(date);

        std::cout << "Price: " << concerts[concert_position]->price() << "\n";
        std::cout << "New price: " ;
        std::cin >> input;
        std::string price = std::string(input);
        concerts[concert_position]->setPrice(price);

        std::cout << "Available ticket: " << concerts[concert_position]->availableTicket() << "\n";
        std::cout << " New available ticket: " ;
        std::cin >> input;
        std::string available_ticket = std::string(input);
        concerts[concert_position]->setAvailableTicket(available_ticket);

    } else {
        std::cout << "concert not found.";
    }
}

void HandleConcert::deleteConcert(int id) {
    Concert* found = getConcertById(id);

    if (found != nullptr) {
        // delete from preferred list
        // TODO:
        if (getPreferredById(id) != nullptr) {            
            deleteConcertToPreferred(id);
            
            concerts[concert_position] = nullptr;
            
            for (int j = concert_position + 1; j < num_registered_concerts; ++j) {
                concerts[j-1] = concerts[j];
                concerts[j] = nullptr;
            }
        } else {
            delete found;
            concerts[concert_position] = nullptr;

            // shift elements after deleted concert to the left to fill the array
            for (int j = concert_position + 1; j < num_registered_concerts; ++j) {
                concerts[j-1] = concerts[j];
                concerts[j] = nullptr;
            }
        }
        num_registered_concerts--;

    } else {
        std::cout << "No concert found. \n";
    }

    std::cout << "num elem after delete: " << num_registered_concerts << "\n";
}

void HandleConcert::getConcertDetails(int id) { 
    int results = 0;
    if (concerts != nullptr && num_registered_concerts > 0) {
        for(int i = 0; i < num_registered_concerts; i++) {
            if(concerts[i]->id() == id) {
                results ++;
                std::cout << "CONCERT: \n" << "Id: " << concerts[i]->id() << " Group: " << concerts[i]->groupName()<< "\n";
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
    std::cout << "old size: " << size_concerts << "\n";
    int newSizeConcerts = size_concerts * 2;
    std::cout << "new size: " << newSizeConcerts << "\n";
    Concert** temp = new Concert* [newSizeConcerts];
    for (int i = 0; i < newSizeConcerts; i++){
        if(i < size_concerts) {
            temp[i] = concerts[i];
        } else {
            temp[i] = nullptr;
        }
    }

    for (int i = 0; i < newSizeConcerts; i++){
        if(temp[i] == nullptr){
            std::cout << "nullptr \n";
        } else {
            std::cout << "elemento " << i << "valore " << temp[i]->groupName() << "\n";
        }
    }

    delete [] concerts;
    
    size_concerts = newSizeConcerts;

    concerts = temp;

    for (int i = 0; i < size_concerts; i++){
        if(concerts[i] == nullptr){
            std::cout << "nullptr \n";
        } else {
            std::cout << "concerto " << i << "valore " << concerts[i]->groupName() << "\n";
        }
    }
       
}

Concert* HandleConcert::getPreferredById(int id) {
    Concert* found = nullptr;
    int i;
    for(i = 0; i < num_preferred_concerts; ++i) {
        if(preferredConcerts[i]->id() == id) {
            found = preferredConcerts[i];
            break;
        }
    }
    preferred_position = i;
    return found;
}

//Functions to manage preferred
void HandleConcert::listPreferredConcerts() {
    if(preferredConcerts != nullptr && num_preferred_concerts == 0) {
        std::cout << "No concerts stored in preferred. \n";
    } else {
        std::cout << "preferred CONCERT: \n";

        for (int i = 0; i < num_preferred_concerts; i++){        
            std::cout  << "Id: " << preferredConcerts[i]->id() << "\tGroup: " << preferredConcerts[i]->groupName()<< "\n";
            std::cout << "\tPlace: " << concerts[i]->place() << " Date: " << concerts[i]->date()<< "\n";
            std::cout << "\tPrice: " << concerts[i]->price() << "$ Available Ticket: " << concerts[i]->availableTicket()<< "\n";

        }
     }
}

bool HandleConcert::checkAddConcertToPreferred() {
    if(num_preferred_concerts < size_preferred){
        return true;
    } else {
        return false;
    }
}

void HandleConcert::addConcertToPreferred(int id) {

    Concert* found = getConcertById(id);

    if(found != nullptr){
        preferredConcerts[num_preferred_concerts] = concerts[concert_position];
        std::cout << "Concert succesfully added to preferred. \n";
        num_preferred_concerts++;
    } else {
        std::cout << "Id not found. Impossible to add to preferred. \n";
    }

}

void HandleConcert::deleteConcertToPreferred(int id) {
   Concert* found = getPreferredById(id);

    if(found != nullptr) {
       delete found;
       found = nullptr;

       for (int j = preferred_position + 1; j < num_preferred_concerts; ++j) {
           preferredConcerts[j-1] = preferredConcerts[j];
           preferredConcerts[j] = nullptr;
       }

    num_preferred_concerts--;
    std::cout << "Concert successfully deleted. \n";
    } else {
        std::cout << "Concert not found. \n";
    }
}

void HandleConcert::resizePreferred() {

    std::cout << "resize.. \n";
    int newSizePreferred = size_preferred * 2;
    Concert** temp = new Concert* [newSizePreferred];
    for (int i = 0; i < size_preferred; i++){
        temp[i] = preferredConcerts[i];
    }

    delete [] preferredConcerts;
    
    size_preferred = newSizePreferred;
    preferredConcerts = temp;
}