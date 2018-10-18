#include "HandleEvent.h"
#include <iostream>
template <typename T> HandleEvent<T>::HandleEvent() { vendor = new T; }
// Destructor
template <typename T> HandleEvent<T>::~HandleEvent<T>() {
  for (int i = 0; i < events.size(); i++) {
    delete events.at(i);
  }
}

// Functions to manage Events
template <typename T> void HandleEvent<T>::listEvents() {
  if (events.empty()) {
    std::cout << "No events stored. \n";
  } else {
    std::cout << "EVENTS: \n";
    for (auto it = events.begin(); it != events.end(); it++) {

      // std::cout << "Id: " << (*it)->id() << " Event: " << (*it)->name()<<
      // "\n";
      if (dynamic_cast<Show *>(*it)) {
        std::cout << "Id: " << (*it)->id() << " Show: " << (*it)->name()
                  << "\n";
      } else if (dynamic_cast<Ballet *>(*it)) {
        std::cout << "Id: " << (*it)->id() << " Ballet: " << (*it)->name()
                  << "\n";
      } else if (dynamic_cast<Concert *>(*it)) {
        std::cout << "Id: " << (*it)->id() << " Concert: " << (*it)->name()
                  << "\n";
      } else {
        std::cout << "Id: " << (*it)->id() << " Event: " << (*it)->name()
                  << "\n";
      }
    }
  }
}
template <typename T>
void HandleEvent<T>::addShowToEvents(std::string name, std::string place,
                                     std::string date, std::string price,
                                     std::string availableTicket) {
  Show *showToAdd = new Show(code, name, place, date, price, availableTicket);
  events.push_back(showToAdd);
  code++;
}

template <typename T>
void HandleEvent<T>::addBalletToEvents(std::string name, std::string place,
                                       std::string date, std::string price,
                                       std::string availableTicket) {
  Ballet *balletToAdd =
      new Ballet(code, name, place, date, price, availableTicket);
  events.push_back(balletToAdd);
  code++;
}

template <typename T>
void HandleEvent<T>::addConcertToEvents(std::string groupName,
                                        std::string place, std::string date,
                                        std::string price,
                                        std::string availableTicket) {
  Concert *concertToAdd =
      new Concert(code, groupName, place, date, price, availableTicket);
  events.push_back(concertToAdd);
  code++;
}

template <typename T> bool HandleEvent<T>::checkIfEventsEmpty() {
  return events.empty();
}

template <typename T>
Event *HandleEvent<T>::getEventById(int id, int &position) {
  int i = 0;
  for (auto it = events.begin(); it != events.end(); it++) {
    if ((*it)->id() == id) {
      position = i;
      return *it;
    }
    i++;
  }
  return nullptr;
}

template <typename T> void HandleEvent<T>::getEventDetails(int id) {
  int position = -1;
  Event *found = getEventById(id, position);
  if (found != nullptr) {

    // std::cout << "Id: " << (found)->id() << " Event: " << (found)->name()<<
    // "\n";

    if (dynamic_cast<Show *>(found)) {
      std::cout << "Id: " << (found)->id() << "\tShow: " << (found)->name()
                << "\n";
    } else if (dynamic_cast<Ballet *>(found)) {
      std::cout << "Id: " << (found)->id() << "\tBallet: " << (found)->name()
                << "\n";
    } else if (dynamic_cast<Concert *>(found)) {
      std::cout << "Id: " << (found)->id() << "\tConcert: " << (found)->name()
                << "\n";
    }

    std::cout << "\tDate: " << found->date() << "\n";
    std::cout << "\tPlace: " << found->place() << "\n";
    std::cout << "\tPrice: " << found->price()
              << "\tAvailable Ticket: " << found->availableTicket() << "\n";

    if (!found->attributes().empty()) {
      std::cout << "EXTRA INFO: \n";
      printExtra(id);
    }
  } else {
    std::cout << "Event not found. \n";
  }
}

template <typename T> void HandleEvent<T>::updateEvent(int id) {
  int position = -1;

  if (getEventById(id, position) != nullptr) {
    // show form
    std::cout << "Id: " << events.at(position)->id() << "\n";

    std::string name, place, date, price, availableTicket;

    std::cout << "name: " << events.at(position)->name() << "\n";
    std::cout << "New name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    if (!name.empty()) {
      events.at(position)->setName(name);
    }

    std::cout << "Place: " << events.at(position)->place() << "\n";
    std::cout << "New place: ";
    std::getline(std::cin, place);
    if (!place.empty()) {
      events.at(position)->setPlace(place);
    }

    std::cout << "Date: " << events.at(position)->date() << "\n";
    std::cout << "New date: ";
    std::getline(std::cin, date);
    if (!date.empty()) {
      events.at(position)->setDate(date);
    }
    std::cout << "Price: " << events.at(position)->price() << "\n";
    std::cout << "New price: ";
    std::getline(std::cin, price);
    if (!price.empty()) {
      events.at(position)->setPrice(price);
    }
    std::cout << "Available ticket: " << events.at(position)->availableTicket()
              << "\n";
    std::cout << " New available ticket: ";
    std::getline(std::cin, availableTicket);
    if (!availableTicket.empty()) {
      events.at(position)->setAvailableTicket(availableTicket);
    }
  } else {
    std::cout << "Event not found.";
  }
}

template <typename T> void HandleEvent<T>::removeEvent(int id) {
  int position = -1;
  if (getEventById(id, position) != nullptr) {
    removeFromPreferred(id);
    delete events.at(position);
    events.erase(events.begin() + position);
  } else {
    std::cout << "Event not found with this id. \n";
  }
}

// Functions to manage Preferred Events

template <typename T> bool HandleEvent<T>::checkIfPreferredEventsEmpty() {
  return preferredEvents.empty();
}

template <typename T> void HandleEvent<T>::addToPreferred(int id) {
  int position = -1;
  Event *found = getEventById(id, position);

  if (found != nullptr) {
    preferredEvents.push_back(found);
    std::cout << "Event successfully added in preferred. \n";
  } else {
    std::cout << "Event not added to preferred. Id not found. \n";
  }
}

template <typename T> void HandleEvent<T>::listPreferredEvents() {
  if (checkIfPreferredEventsEmpty()) {
    std::cout << "No preferred events stored. \n";
  } else {
    std::cout << "FAVOURITE EVENTS: \n";
    for (auto it = preferredEvents.begin(); it != preferredEvents.end(); it++) {

      if (dynamic_cast<Show *>(*it)) {
        std::cout << "Id: " << (*it)->id() << " Show: " << (*it)->name()
                  << "\n";
      } else if (dynamic_cast<Ballet *>(*it)) {
        std::cout << "Id: " << (*it)->id() << " Ballet: " << (*it)->name()
                  << "\n";
      } else if (dynamic_cast<Concert *>(*it)) {
        std::cout << "Id: " << (*it)->id() << " Concert: " << (*it)->name()
                  << "\n";
      }

      // std::cout << "Id: " << (*it)->id() << " Event: " << (*it)->name()<<
      // "\n";
      std::cout << "\tPlace: " << (*it)->place() << " Date: " << (*it)->date()
                << "\n";
      std::cout << "\tPrice: " << (*it)->price()
                << "$ Available Ticket: " << (*it)->availableTicket() << "\n";
    }
  }
}

template <typename T>
Event *HandleEvent<T>::getPreferredById(int id, int &position) {
  int i = 0;
  for (auto it = preferredEvents.begin(); it != preferredEvents.end(); it++) {
    if ((*it)->id() == id) {
      position = i;
      return *it;
    }
    i++;
  }
  return nullptr;
}

template <typename T> void HandleEvent<T>::removeFromPreferred(int id) {
  int position = -1;
  if (getPreferredById(id, position) != nullptr) {
    preferredEvents.erase(preferredEvents.begin() + position);
  } else {
    std::cout << "PREFERRED: Event not found with this id. \n";
  }
}

// Function to manage extraInfo

template <typename T> void HandleEvent<T>::addExtra(int id) {
  int position = -1;
  if (getEventById(id, position) != nullptr) {
    std::cout << "event found. \n";
    if (dynamic_cast<Show *>(events[position])) {
      std::cout << "SHOW. \n";
      std::vector<std::string> att = events[position]->allowedAttributes();
      formExtra(att, position, "add");
    } else if (dynamic_cast<Ballet *>(events[position])) {
      std::cout << "BALLET. \n";
      std::vector<std::string> att = events[position]->allowedAttributes();
      formExtra(att, position, "add");
    } else if (dynamic_cast<Concert *>(events[position])) {
      std::cout << "CONCERT. \n";
      std::vector<std::string> att = events[position]->allowedAttributes();
      formExtra(att, position, "add");
    }
  } else {
    std::cout << "event not found. \n";
  }
}

template <typename T>
void HandleEvent<T>::formExtra(std::vector<std::string> &att, int position,
                               std::string type) {
  std::string results;
  for (auto it = att.begin(); it != att.end(); it++) {
    std::cout << *it << ": ";
    std::cin.ignore();
    std::getline(std::cin, results);
    if (type == "add") {
      events[position]->setAttributes(*it, results);
    } else if (type == "up") {
      events[position]->updateAttributes(*it, results);
    }
  }
}

template <typename T> void HandleEvent<T>::printExtra(int id) {
  int position = -1;
  if (getEventById(id, position) != nullptr) {
    std::map<std::string, std::string>::iterator it;
    for (it = events[position]->attributes().begin();
         it != events[position]->attributes().end(); it++) {
      std::cout << it->first << ": " << it->second << "\n";
    }
  } else {
    std::cout << "There are not any extra information. \n";
  }
}

template <typename T> void HandleEvent<T>::updateExtra(int id) {
  int position = -1;
  if (getEventById(id, position) != nullptr) {
    std::vector<std::string> att = events[position]->allowedAttributes();
    formExtra(att, position, "up");
  } else {
    std::cout << "No extra. \n";
  }
}

template <typename T> void HandleEvent<T>::deleteExtra(int id) {
  int pos = -1;
  if (getEventById(id, pos) != nullptr) {
    events[pos]->removeAttributes();

    std::cout << "Extra deleted. \n";
  } else {
    std::cout << "No extra information in this element. \n";
  }
}

template <typename T> void HandleEvent<T>::buyTicket(int id) {
  
  int pos = -1;
  Event *found = getEventById(id, pos);

  if (found != nullptr) {
    vendor->buyTicket(found);
  } else {
    std::cout << "No event found with this id. \n";
  }

}