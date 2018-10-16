#ifndef __BALLET_H__
#define __BALLET_H__
#include "Event.h"


class Ballet : public Event
{
public:
  Ballet(int id, std::string name, std::string place, std::string date,
         std::string price, std::string availableTicket);
  
    std::vector<std::string> allowedAttributes() override;
};

#endif