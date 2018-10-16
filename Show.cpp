#include "Show.h"
Show::Show(int id, std::string name, std::string place, std::string date,
           std::string price, std::string availableTicket)
    : Event{id, name, place, date, price, availableTicket} {};
    
std::vector<std::string> Show::allowedAttributes() {    
    std::vector<std::string> attributes;
    attributes.push_back("director");
    setAttributes("director", nullptr);
    return attributes;
}
