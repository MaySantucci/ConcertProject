#ifndef __EVENT_H__
#define __EVENT_H__
#include <iostream>

class Event {
    public:    
    Event(int id, std::string name, std::string place, std::string date, std::string price, std::string availableTicket);

    //getter methods
    int id();
    std::string name();
    std::string date();
    std::string place();
    std::string price();
    std::string availableTicket();

    //setter methods
    virtual void setName(std::string name) = 0;
    virtual void setDate(std::string date) = 0;
    virtual void setPlace(std::string place) = 0;
    virtual void setPrice(std::string price) = 0;
    virtual void setAvailableTicket(std::string availableTicket) = 0;   

    private:
    int m_id;
    std::string m_name;
    std::string m_date;
    std::string m_place;
    std::string m_price;
    std::string m_availableTicket;
};
#endif