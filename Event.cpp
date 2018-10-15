#include "Event.h"

Event::Event(int id, std::string name, std::string place, std::string date, std::string price, std::string availableTicket) {
    m_id = id;
    m_name = name;
    m_place = place;
    m_date = date;
    m_price = price;
    m_availableTicket = availableTicket;
}
//getter methods
int Event::id() {
    return m_id;
}

std::string Event::name() {
    return m_name;
}

std::string Event::date() {
    return m_date;
}

std::string Event::place() {
    return m_place;
}

std::string Event::price() {
    return m_price;
}

std::string Event::availableTicket() {
    return m_availableTicket;
}
