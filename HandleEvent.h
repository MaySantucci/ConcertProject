#ifndef __HANDLECONCERT_H__
#define __HANDLECONCERT_H__

#include <iostream>
#include <string>
#include <vector>


template <typename Vendor, typename Event> class HandleEvent {
public:
  Vendor *vendor;

  std::vector<Event *> events;
  std::vector<Event *> preferredEvents;

  HandleEvent() { vendor = new Vendor; };
  ~HandleEvent() {
    delete vendor;
    for (int i = 0; i < events.size(); i++) {
      delete events.at(i);
    }
  };

  // Functions to manage Events
  std::vector<Event *> listEvents() { return events; };

  void addEventToEvents(Event *event) { events.push_back(event); };

  bool checkIfEventsEmpty() { return events.empty(); };

  Event *getEventById(int id, int &position) {
    int i = 0;
    for (auto event : events) {
      if (event->id() == id) {
        position = i;
        return event;
      }
      i++;
    }
    return nullptr;
  };

  void updateEvent(int position, std::string name, std::string place, std::string date , std::string price, std::string availableTicket) {
    events[position]->setName(name);
    events[position]->setPlace(place);
    events[position]->setDate(date);
    events[position]->setPrice(price);
    events[position]->setAvailableTicket(availableTicket);
  };
  // void removeEvent(int id);
  //
  // // Functions to manage Preferred Events
  // void listPreferredEvents();
  // bool checkIfPreferredEventsEmpty();
  // void addToPreferred(int id);
  // Event *getPreferredById(int id, int &position);
  // void removeFromPreferred(int id);
  //
  // // Function to manage ExtraInfo
  // void addExtra(int id);
  // void printExtra(int id);
  // void updateExtra(int id);
  // void deleteExtra(int id);
  //
  // void formExtra(std::vector<std::string> &att, int position, std::string
  // type);
  //
  // // Function to Buy a ticket
  // void buyTicket(int id);
};

#endif