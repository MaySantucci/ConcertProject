#include "Show.h"
 Show::Show(int id, std::string name, std::string place, std::string date, std::string price, std::string availableTicket): Event {id, name, place, date, price, availableTicket} {};

void Show::setName(std::string groupName) {
    Event::name() = groupName;
}
void Show::setPlace(std::string place) {
    Event::place() = place;
}
void Show::setDate(std::string date) {
    Event::date() = date;
}
void Show::setPrice(std::string price) {
    Event::price() = price;
}
void Show::setAvailableTicket(std::string availableTicket) {
    Event::availableTicket() = availableTicket;
}

