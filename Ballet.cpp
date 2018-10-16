#include "Ballet.h"
Ballet::Ballet(int id, std::string name, std::string place, std::string date,
               std::string price, std::string availableTicket)
    : Event{id, name, place, date, price, availableTicket} {};

std::vector<std::string> Ballet::allowedAttributes() {    
    std::vector<std::string> attributes;
    attributes.push_back("first_dancer");
    attributes.push_back("num_dancers");
    return attributes;
}