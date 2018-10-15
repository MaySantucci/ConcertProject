#ifndef __SHOW_H__
#define __SHOW_H__
#include "Event.h"
#include <iostream>
#include <string>

class Show : public Event
{
  public:
    Show(int id, std::string name, std::string place, std::string date,
         std::string price, std::string availableTicket);
};

#endif