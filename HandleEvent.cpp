#include "HandleEvent.h"
#include <iostream>

//Destructor
HandleEvent::~HandleEvent() {
    for (int i = 0; i < events.size(); i++) {
        delete events.at(i);
    }
}

//Functions to manage Events
void HandleEvent::listEvents() {
    if(events.empty()) {
        std::cout << "No events stored. \n";
    } else {
        std::cout << "EVENTS: \n";
        for(auto it = events.begin(); it != events.end(); it++) {
            
            //std::cout << "Id: " << (*it)->id() << " Event: " << (*it)->name()<< "\n";
            if(dynamic_cast<Show*>(*it)) {                
                std::cout << "Id: " << (*it)->id() << " Show: " << (*it)->name()<< "\n";
            } else if(dynamic_cast<Ballet*>(*it)) {                
                std::cout << "Id: " << (*it)->id() << " Ballet: " << (*it)->name()<< "\n";
            } else if(dynamic_cast<Concert*>(*it)) {                
                std::cout << "Id: " << (*it)->id() << " Concert: " << (*it)->name()<< "\n";
            } else {
                std::cout << "Id: " << (*it)->id() << " Event: " << (*it)->name()<< "\n";
            }
        
        }
    }

}
void HandleEvent::addShowToEvents(std::string name, std::string place, std::string date, std::string price, std::string availableTicket) {
    Show* showToAdd = new Show (code, name, place, date, price, availableTicket);
    events.push_back(showToAdd);
    code++;  
}
void HandleEvent::addBalletToEvents(std::string name, std::string place, std::string date, std::string price, std::string availableTicket) {
    Ballet* balletToAdd = new Ballet (code, name, place, date, price, availableTicket);
    events.push_back(balletToAdd);
    code++;  
}
void HandleEvent::addConcertToEvents(std::string groupName, std::string place, std::string date, std::string price, std::string availableTicket) {
    Concert* concertToAdd = new Concert (code, groupName, place, date, price, availableTicket);
    events.push_back(concertToAdd);
    code++;  
}
bool HandleEvent::checkIfEventsEmpty() {
    return events.empty();
}
Event* HandleEvent::getEventById(int id, int& position) {
        int i = 0;
        for (auto it = events.begin(); it != events.end(); it++) {
            if((*it)->id() == id) {
                position = i;
                return *it;
            }
            i++;
        }
    return nullptr;
}
void HandleEvent::getEventDetails(int id) {
    int position = -1;
    Event* found = getEventById(id, position); 
    if(found != nullptr) {   
        
        //std::cout << "Id: " << (found)->id() << " Event: " << (found)->name()<< "\n";
           
        if(dynamic_cast<Show*>(found)) {                
            std::cout << "Id: " << (found)->id() << "\tShow: " << (found)->name()<< "\n";
        } else if(dynamic_cast<Ballet*>(found)) {                
            std::cout << "Id: " << (found)->id() << "\tBallet: " << (found)->name()<< "\n";
        } else if(dynamic_cast<Concert*>(found)) {                
            std::cout << "Id: " << (found)->id() << "\tConcert: " << (found)->name()<< "\n";
        } 

        std::cout << "\tDate: " << found->date() << "\n";
        std::cout << "\tPlace: " << found->place() << "\n";
        std::cout << "\tPrice: " << found->price() << "\tAvailable Ticket: " << found->availableTicket() << "\n";

    } else {
        std::cout << "Event not found. \n";
    }    
}
void HandleEvent::updateEvent(int id) {
    int position = -1;

    if(getEventById(id, position) != nullptr) {
        //show form
        std::cout << "Id: " << events.at(position)->id() << "\n";
        
        std::string name, place, date, price, availableTicket;
        
        std::cout << "name: " << events.at(position)->name() << "\n";
        std::cout << "New name: ";       
        std::cin.ignore();
        std::getline (std::cin,name);
        if(!name.empty()) {
            events.at(position)->setName(name);
        }

        std::cout << "Place: " << events.at(position)->place() << "\n";
        std::cout << "New place: " ;
        std::getline (std::cin,place);  
        if(!place.empty()) {
            events.at(position)->setPlace(place);
        }             

        std::cout << "Date: " << events.at(position)->date() << "\n";
        std::cout << "New date: " ;
        std::getline (std::cin,date);
        if(!date.empty()) {
            events.at(position)->setDate(date);
        }
        std::cout << "Price: " << events.at(position)->price() << "\n";
        std::cout << "New price: " ;
        std::getline (std::cin,price);        
        if(!price.empty()) {
            events.at(position)->setPrice(price);
        }
        std::cout << "Available ticket: " << events.at(position)->availableTicket() << "\n";
        std::cout << " New available ticket: " ;
        std::getline (std::cin,availableTicket);
        if(!availableTicket.empty()) {
            events.at(position)->setAvailableTicket(availableTicket);
        }

    } else {
        std::cout << "Event not found.";
    }
}
void HandleEvent::removeEvent(int id) {
    int position = -1;
    if(getPreferredById(id, position) != nullptr) {
        removeFromPreferred(id);
        delete events.at(position);
        events.erase(events.begin() + position);
    } else {
        std::cout << "Event not found with this id. \n";
    }
}

//Functions to manage Preferred Events
bool HandleEvent::checkIfPreferredEventsEmpty() {
    return preferredEvents.empty();
}
void HandleEvent::addToPreferred(int id) {
    int position = -1;
    Event* found = getEventById(id, position);

    if(found != nullptr) {
        preferredEvents.push_back(found);
        std::cout << "Event successfully added in preferred. \n";
    } else {
        std::cout << "Event not added to preferred. Id not found. \n";
    }
}
void HandleEvent::listPreferredEvents() {
    if(checkIfPreferredEventsEmpty()) {
        std::cout << "No preferred events stored. \n";
    } else {
         std::cout << "FAVOURITE EVENTS: \n"; 
        for (auto it = preferredEvents.begin(); it != preferredEvents.end(); it++) {               
          
            if(dynamic_cast<Show*>(*it)) {                
                std::cout << "Id: " << (*it)->id() << " Show: " << (*it)->name()<< "\n";
            } else if(dynamic_cast<Ballet*>(*it)) {                
                std::cout << "Id: " << (*it)->id() << " Ballet: " << (*it)->name()<< "\n";
            } else if(dynamic_cast<Concert*>(*it)) {                
                std::cout << "Id: " << (*it)->id() << " Concert: " << (*it)->name()<< "\n";
            } 
            
           // std::cout << "Id: " << (*it)->id() << " Event: " << (*it)->name()<< "\n";
            std::cout << "\tPlace: " << (*it)->place() << " Date: " << (*it)->date()<< "\n";
            std::cout << "\tPrice: " << (*it)->price() << "$ Available Ticket: " << (*it)->availableTicket()<< "\n";      
        }
    }
}
Event* HandleEvent::getPreferredById(int id, int& position) {
    int i = 0;
    for(auto it = preferredEvents.begin(); it != preferredEvents.end(); it++) {
        if((*it)->id() == id) {
            position = i;
            return *it;
        }
        i++;
    }
    return nullptr;    
}
void HandleEvent::removeFromPreferred(int id) {
    int position = -1;
    if(getPreferredById(id, position) != nullptr) {
        preferredEvents.erase(preferredEvents.begin() + position);
    } else {
        std::cout << "Event not found with this id. \n";
    }
}

//Function to manage extraInfo

void HandleEvent::addExtra(int id) {
    int position = -1;
    if(getEventById(id, position) != nullptr) {
        std::cout << "event found. \n";        
        std::string results;

        if(dynamic_cast<Show*>(events[position])) {                
            std::cout << "SHOW. \n";
            std::vector<std::string> att = events[position]->allowedAttributes();
            for(auto it = att.begin(); it != att.end(); it++) {
                std::cout << *it << ": \n";
                std::cin.ignore();
                std::getline (std::cin, results);
                events[position]->setAttributes(*it, results);
            }
        } else if(dynamic_cast<Ballet*>(events[position])) {       
            std::cout << "BALLET. \n";
            std::vector<std::string> att = events[position]->allowedAttributes();
            for(auto it = att.begin(); it != att.end(); it++) {
                std::cout << *it << ": \n";
                std::cin.ignore();
                std::getline (std::cin, results);
                events[position]->setAttributes(*it, results);
            }           
        } else if(dynamic_cast<Concert*>(events[position])) {      
            std::cout << "CONCERT. \n"; 
            std::vector<std::string> att = events[position]->allowedAttributes();
            for(auto it = att.begin(); it != att.end(); it++) {
                std::cout << *it << ": \n";
                std::cin.ignore();
                std::getline (std::cin, results);
                events[position]->setAttributes(*it, results);
            }             

        } 
    } else {
        std::cout << "event not found. \n";
    }
}