#include "UserFunctions.h"
#include <iostream>

// Functions to manage Events

void UserFunctions::listEvents() {
  std::vector<Show *> shows = handlerShow->listEvents();
  std::vector<Ballet *> ballets = handlerBallet->listEvents();
  std::vector<Concert *> concerts = handlerConcert->listEvents();
  if (!shows.empty()) {
    for (auto show : shows) {
      std::cout << "Id: " << show->id() << " Show: " << show->name() << "\n";
    }
  }
  if (!ballets.empty()) {
    for (auto ballet : ballets) {
      std::cout << "Id: " << ballet->id() << " Ballet: " << ballet->name()
                << "\n";
    }
  }
  if (!concerts.empty()) {
    for (auto concert : concerts) {
      std::cout << "Id: " << concert->id() << " Concert: " << concert->name()
                << "\n";
    }
  }

  if (shows.empty() && ballets.empty() && concerts.empty()) {
    std::cout << "No events stored. \n";
  }
}

void UserFunctions::showForm(std::string &n, std::string &pl, std::string &d,
                             std::string &pr, std::string &ticket) {
  std::cout << "name: ";
  std::cin.ignore();
  std::getline(std::cin, n);

  std::cout << "Place: ";
  std::getline(std::cin, pl);

  std::cout << "Date: ";
  std::getline(std::cin, d);

  std::cout << "Price: ";
  std::getline(std::cin, pr);

  std::cout << "Available ticket: ";
  std::getline(std::cin, ticket);
}

void UserFunctions::insertEvent(std::string type_event) {
  showForm(name, place, date, price, availableTicket);

  if (type_event == "a") {
    // add Show to Events
    std::cout << "Show. \n";
    handlerShow->addEventToEvents(codeEvent, name, place, date, price, availableTicket);
    codeEvent++;
  } else if (type_event == "b") {
    // add Ballet to Events
    std::cout << "Ballet. \n";
    handlerBallet->addEventToEvents(codeEvent, name, place, date, price, availableTicket);
    codeEvent++;
  } else if (type_event == "c") {
    // add Concert to Events
    std::cout << "Concert. \n";
    handlerConcert->addEventToEvents(codeEvent, name, place, date, price, availableTicket);
    codeEvent++;
  }
}

bool UserFunctions::checkEventsInit() {
  if (handlerShow->checkIfEventsEmpty() &&
      handlerBallet->checkIfEventsEmpty() &&
      handlerConcert->checkIfEventsEmpty()) {
    return true;
  }
  return false;
}

void UserFunctions::detailsEvent(int id) {
  int position = -1;
  Show *show = handlerShow->getEventById(id, position);
  Ballet *ballet = handlerBallet->getEventById(id, position);
  Concert *concert = handlerConcert->getEventById(id, position);

  if (show == nullptr && ballet == nullptr && concert == nullptr) {
    std::cout << "Event with this id not found. \n";
  } else if (show != nullptr) {
      printDetails(show);
  } else if (ballet != nullptr) {
      printDetails(ballet);
  } else if (concert != nullptr) {
      printDetails(concert);
  }
}

void UserFunctions::printDetails(Event *e) {
  std::cout << "Id: " << e->id() << " Name: " << e->name() << "\n";
  std::cout << "Place: " << e->place() << " Date: " << e->date() << "\n";
  std::cout << "Price: " << e->price()
            << " Available Ticket: " << e->availableTicket() << "\n";
}

void UserFunctions::addExtraInfo(int id) {
  // handler->addExtra(id);
}

void UserFunctions::listExtraInfo(int id) {
  // handler->printExtra(id);
}

void UserFunctions::updateExtraInfo(int id) {
  // handler->updateExtra(id);
}

void UserFunctions::deleteExtraInfo(int id) {
  // handler->deleteExtra(id);
}

void UserFunctions::updateEvent(int id) {
  // handler->updateEvent(id);
}
void UserFunctions::deleteEvent(int id) {
  // handler->removeEvent(id);
}

// Functions to manage Preferred Events
void UserFunctions::listPreferredEvents() {
  // handler->listPreferredEvents();
}
bool UserFunctions::checkPreferredEventsInit() {
  // return handler->checkIfPreferredEventsEmpty();
}
void UserFunctions::insertPreferredEvent(int id) {
  // handler->addToPreferred(id);
}
void UserFunctions::deletePreferredEvent(int id) {
  // handler->removeFromPreferred(id);
}

void UserFunctions::buyTicket(int id) {
  // handler->buyTicket(id);
}