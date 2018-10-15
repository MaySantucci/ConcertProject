#include "Show.h"
 Show::Show(int id, std::string name, std::string place, std::string date, std::string price, std::string availableTicket): Event {id, name, place, date, price, availableTicket} {};

void Show::setName(std::string name) {
    Event::setName(name);
}
void Show::setPlace(std::string place) {
    Event::setPlace(place);
}
void Show::setDate(std::string date) {
    Event::setDate(date);
}
void Show::setPrice(std::string price) {
    Event::setPrice(price);
}
void Show::setAvailableTicket(std::string availableTicket) {
    Event::setAvailableTicket(availableTicket);
}

