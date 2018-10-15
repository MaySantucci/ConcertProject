#include "Ballet.h"
 Ballet::Ballet(int id, std::string name, std::string place, std::string date, std::string price, std::string availableTicket): Event {id, name, place, date, price, availableTicket} {};

void Ballet::setName(std::string groupName) {
    Event::name() = groupName;
}
void Ballet::setPlace(std::string place) {
    Event::place() = place;
}
void Ballet::setDate(std::string date) {
    Event::date() = date;
}
void Ballet::setPrice(std::string price) {
    Event::price() = price;
}
void Ballet::setAvailableTicket(std::string availableTicket) {
    Event::availableTicket() = availableTicket;
}

