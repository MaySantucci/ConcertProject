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

            
    std::vector<std::string> allowedAttributes() override;

  private:
    std::string m_artist;
    std::string m_genre;
};

#endif