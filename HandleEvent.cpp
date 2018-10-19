#include "HandleEvent.h"
#include <iostream>
/*
// Function to manage extraInfo

template <typename T, typename E> void HandleEvent<T, E>::addExtra(int id) {
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

template <typename T, typename E>
void HandleEvent<T, E>::formExtra(std::vector<std::string> &att, int position,
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

template <typename T, typename E> void HandleEvent<T, E>::printExtra(int id) {
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

template <typename T, typename E> void HandleEvent<T, E>::updateExtra(int id) {
  int position = -1;
  if (getEventById(id, position) != nullptr) {
    std::vector<std::string> att = events[position]->allowedAttributes();
    formExtra(att, position, "up");
  } else {
    std::cout << "No extra. \n";
  }
}

template <typename T, typename E> void HandleEvent<T, E>::deleteExtra(int id) {
  int pos = -1;
  if (getEventById(id, pos) != nullptr) {
    events[pos]->removeAttributes();

    std::cout << "Extra deleted. \n";
  } else {
    std::cout << "No extra information in this element. \n";
  }
}

template <typename T, typename E> void HandleEvent<T, E>::buyTicket(int id) {

  int pos = -1;
  Event *found = getEventById(id, pos);

  if (found != nullptr) {
    vendor->buyTicket(found);
  } else {
    std::cout << "No event found with this id. \n";
  }
}
*/