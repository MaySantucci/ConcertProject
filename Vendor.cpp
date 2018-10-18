#include "Vendor.h"
#include <iostream>
#include <string>

void Vendor::buyTicket(Event *e) {
  try {
    int ticket = stoi(e->availableTicket());
    std::cout << "available ticket: " << ticket << "\n";
    if (ticket > 0) {
      // TODO: decrease ticket and print bought
      ticket--;
      e->setAvailableTicket(std::to_string(ticket));

      std::cout << "available ticket: " << std::to_string(ticket) << "\n";
      std::cout << "Ticket Bought. \n";
    } else {
      std::cout << "There are not any available ticket for this event. \n";
    }
  } catch (std::invalid_argument) {
    std::cout << "Impossible to convert availableTicket in int. \n";
  }
}