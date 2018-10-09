#include "Concert.h"

Concert::Concert () {
    
}

Concert::Concert (int id, std::string groupName, std::string place, std::string date, std::string price, std::string availableTicket) {
    m_id = id;
    m_groupName = groupName;
    m_place = place;
    m_date = date;
    m_price = price;
    m_availableTicket = availableTicket;    
}

int Concert::id() {
    return m_id;
}
std::string Concert::groupName() {
    return m_groupName;
}
std::string Concert::place() {
    return m_place;
}
std::string Concert::date() {
    return m_date;
}
std::string Concert::price() {
    return m_price;
}
std::string Concert::availableTicket() {
    return m_availableTicket;
}

void Concert::setGroupName(std::string groupName){
    m_groupName = groupName;
}
void Concert::setPlace(std::string place){
    m_place = place;
}
void Concert::setDate(std::string date){
    m_date = date;
}
void Concert::setPrice(std::string price){
    m_price = price;
}
void Concert::setAvailableTicket(std::string availableTicket){
    m_availableTicket = availableTicket;
}
