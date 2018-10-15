#ifndef __CONCERT_H__
#define __CONCERT_H__
#include "Event.h"
#include <iostream>
#include <string>

class Concert : public Event
{
  public:
    Concert(int id, std::string name, std::string place, std::string date,
            std::string price, std::string availableTicket);
};

#endif