#include "Concert.h"
 Concert::Concert(int id, std::string name, std::string place, std::string date, std::string price, std::string availableTicket): Event {id, name, place, date, price, availableTicket} {};

void Concert::setName(std::string name) {
    Event::setName(name);
}
void Concert::setPlace(std::string place) {
    Event::setPlace(place);
}
void Concert::setDate(std::string date) {
    Event::setDate(date);
}
void Concert::setPrice(std::string price) {
    Event::setPrice(price);
}
void Concert::setAvailableTicket(std::string availableTicket) {
    Event::setAvailableTicket(availableTicket);
}

