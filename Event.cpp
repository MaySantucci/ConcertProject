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
int Event::id() const {
    return m_id;
}

std::string Event::name() const {
    return m_name;
}

std::string Event::date() const {
    return m_date;
}

std::string Event::place() const {
    return m_place;
}

std::string Event::price() const {
    return m_price;
}

std::string Event::availableTicket() const {
    return m_availableTicket;
}

std::map<std::string, std::string> Event::attributes() const {
    return m_attributes;
}

// setter methods
void Event::setName(const std::string& name) {
    m_name = name;
}
void Event::setPlace(const std::string& place) {
    m_place = place;
}
void Event::setDate(const std::string& date) {
    m_date = date;
}
void Event::setPrice(const std::string& price) {
    m_price = price;
}
void Event::setAvailableTicket(const std::string& availableTicket) {
    m_availableTicket = availableTicket;
}

void Event::setAttributes(std::string key, std::string value) {
    //TODO: populate map with key and value 
    std::map<std::string, std::string>::iterator it; 
    it = m_attributes.begin();
    m_attributes.insert(it, std::pair<std::string, std::string>(key, value));
}
