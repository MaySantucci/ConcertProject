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
  std::vector<Event*> listEvents() { return events; };

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

  void removeEvent(int position) {
    delete events[position];
    events.erase(events.begin() + position);
  };

  
  std::vector<Event*> listPreferredEvents() {
    return preferredEvents;
  };
  
  void addToPreferred(Event* e) {
    preferredEvents.push_back(e);
  };

  bool checkIfPreferredEventsEmpty() {
    return preferredEvents.empty();
  };

  Event* getPreferredById(int id, int &position) {
    int i = 0;
    for (auto favourite : preferredEvents) {
      if(favourite->id() == id) {
        position = i;
        return favourite;
      }
      i++;
    }
    return nullptr;
  };
  
  void removeFromPreferred(int position) {
    preferredEvents.erase(preferredEvents.begin() + position);
  };
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