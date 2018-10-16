#include "Concert.h"
Concert::Concert(int id, std::string name, std::string place, std::string date,
                 std::string price, std::string availableTicket)
    : Event{id, name, place, date, price, availableTicket} {};

        
std::vector<std::string> Concert::allowedAttributes() {
    std::vector<std::string> attributes;
    attributes.push_back("artist");
    attributes.push_back("genre");
    setAttributes("artist", nullptr);
    setAttributes("genre", nullptr);
    return attributes;
}
