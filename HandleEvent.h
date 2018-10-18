#ifndef __HANDLECONCERT_H__
#define __HANDLECONCERT_H__

#include "Ballet.h"
#include "Concert.h"
#include "Event.h"
#include "Show.h"
#include "Vendor.h"
#include <vector>

template <typename T, typename E> class HandleEvent {
public:
  T *vendor;

  std::vector<E *> events;
  std::vector<E *> preferredEvents;

  int code = 0;

  HandleEvent() { vendor = new T; };
  ~HandleEvent() {
    for (int i = 0; i < events.size(); i++) {
      delete events.at(i);
    }
  };

  // Functions to manage Events
  std::vector<E *> listEvents() { return events; };

  void addEventToEvents(std::string name, std::string place, std::string date,
                        std::string price, std::string availableTicket) {
    events.push_back(new E(code, name, place, date, price, availableTicket));
    code++;

    std::cout << "Size: " << events.size() << "\n";
  };

  bool checkIfEventsEmpty() { return events.empty(); };

  E* getEventById(int id, int &position) {
      int i = 0;
      for(auto event : events) {
          if(event->id() == id) {
              position = i;
              return event;
          }
      }
      return nullptr;
  };


  //
  // void updateEvent(int id);
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