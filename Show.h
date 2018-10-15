#ifndef __SHOW_H__
#define __SHOW_H__
#include "Event.h"
#include <string>
#include <iostream>
class Show : public Event {
    public:    
    Show(int id, std::string name, std::string place, std::string date, std::string price, std::string availableTicket);
    
    //setter methods
    virtual void setName(std::string name);
    virtual void setDate(std::string date);
    virtual void setPlace(std::string place);
    virtual void setPrice(std::string price);
    virtual void setAvailableTicket(std::string availableTicket); 
};

#endif