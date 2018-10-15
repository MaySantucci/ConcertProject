#include "Concert.h"
 Concert::Concert(int id, std::string name, std::string place, std::string date, std::string price, std::string availableTicket): Event {id, name, place, date, price, availableTicket} {};

void Concert::setName(std::string groupName) {
    Event::name() = groupName;
}
void Concert::setPlace(std::string place) {
    Event::place() = place;
}
void Concert::setDate(std::string date) {
    Event::date() = date;
}
void Concert::setPrice(std::string price) {
    Event::price() = price;
}
void Concert::setAvailableTicket(std::string availableTicket) {
    Event::availableTicket() = availableTicket;
}

