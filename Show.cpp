#include "Show.h"
Show::Show(int id, std::string name, std::string place, std::string date,
           std::string price, std::string availableTicket)
    : Event{id, name, place, date, price, availableTicket} {};
