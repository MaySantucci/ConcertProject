#include "UserFunctions.h"
#include "Ballet.h"
#include "Concert.h"
#include "Show.h"
#include <iostream>
#include <string>


// Functions to manage Events

void UserFunctions::listEvents() {

  std::vector<Event *> events = handler->listEvents();
  if (!events.empty()) {
    for (auto event : events) {
      printDetails(event);
    }
  } else {
    std::cout << "No events stored. \n";
  }
}

void UserFunctions::printDetails(Event *e) {
  std::cout << "Id: " << e->id() << " Name: " << e->name() << "\n";
  std::cout << "Place: " << e->place() << " Date: " << e->date() << "\n";
  std::cout << "Price: " << e->price()
            << " Available Ticket: " << e->availableTicket() << "\n";
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
  Event *event = nullptr;

  if (type_event == "a") {
    // add Show to Events
    event = new Show(idEvent, name, place, date, price, availableTicket);
    handler->addEventToEvents(event);
    idEvent++;
  } else if (type_event == "b") {
    // add Ballet to Events
    event = new Ballet(idEvent, name, place, date, price, availableTicket);
    handler->addEventToEvents(event);
    idEvent++;
  } else if (type_event == "c") {
    // add Concert to Events
    event = new Concert(idEvent, name, place, date, price, availableTicket);
    handler->addEventToEvents(event);
    idEvent++;
  }
}

bool UserFunctions::checkEventsInit() {
  if (handler->checkIfEventsEmpty()) {
    return true;
  }
  return false;
}

void UserFunctions::detailsEvent(int id) {
  int position = -1;
  Event *event = handler->getEventById(id, position);

  if (event == nullptr) {
    std::cout << "Event with this id not found. \n";
  } else {
    printDetails(event);
  }
}

void UserFunctions::updateEvent(int id) {
    int position = -1;
    Event* found = handler->getEventById(id, position);
    if(found != nullptr) {
      showForm(name, place, date, price, availableTicket);
      handler->updateEvent(position, name, place, date, price, availableTicket);      
      std::cout << "Event updated. \n";
    } else {
      std::cout << "Event not found. \n";
    }
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