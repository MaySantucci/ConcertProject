#include "Ballet.h"
 Ballet::Ballet(int id, std::string name, std::string place, std::string date, std::string price, std::string availableTicket): Event {id, name, place, date, price, availableTicket} {};

void Ballet::setName(std::string name) {
    Event::setName(name);
}
void Ballet::setPlace(std::string place) {
    Event::setPlace(place);
}
void Ballet::setDate(std::string date) {
    Event::setDate(date);
}
void Ballet::setPrice(std::string price) {
    Event::setPrice(price);
}
void Ballet::setAvailableTicket(std::string availableTicket) {
    Event::setAvailableTicket(availableTicket);
}

