#ifndef __HANDLECONCERT_H__
#define __HANDLECONCERT_H__

#include <iostream>
#include <string>
#include <vector>
#include <memory>

template <typename Vendor, typename Event>
class HandleEvent
{

public:
  std::vector<std::unique_ptr<Event>> events;
  std::vector<Event *> preferredEvents;

  std::unique_ptr<Vendor> vendor;

  HandleEvent() { vendor = std::make_unique<Vendor>(); };

  // Functions to manage Events
  const std::vector<std::unique_ptr<Event>> &listEvents()
  {
    return events;
  };

  void addEventToEvents(std::unique_ptr<Event> event)
  {
    events.push_back(std::move(event));
  };

  bool checkIfEventsEmpty() { return events.empty(); };

  Event *getEventById(int id, int &position)
  {
    int i = 0;
    for (auto &event : events)
    {
      if (event->id() == id)
      {
        position = i;
        return event.get();
      }
      i++;
    }
    return nullptr;
  };

  void updateEvent(int position, std::string name, std::string place,
                   std::string date, std::string price,
                   std::string availableTicket)
  {
    events[position]->setName(name);
    events[position]->setPlace(place);
    events[position]->setDate(date);
    events[position]->setPrice(price);
    events[position]->setAvailableTicket(availableTicket);
  };

  void removeEvent(int position)
  {
    events.erase(events.begin() + position);
  };

  // Function to manage Favourite Events
  std::vector<Event *> listPreferredEvents() { return preferredEvents; };

  void addToPreferred(Event *e) { preferredEvents.push_back(e); };

  bool checkIfPreferredEventsEmpty() { return preferredEvents.empty(); };

  Event *getPreferredById(int id, int &position)
  {
    int i = 0;
    for (auto &favourite : preferredEvents)
    {
      if (favourite->id() == id)
      {
        position = i;
        return favourite;
      }
      i++;
    }
    return nullptr;
  };

  void removeFromPreferred(int position)
  {
    preferredEvents.erase(preferredEvents.begin() + position);
  };

  // Function to manage ExtraInfo

  void addExtra(Event *event, std::vector<std::string> att, std::vector<std::string> values)
  {
    auto value = values.begin();
    for (auto it = att.begin(); it != att.end(); it++)
    {
      event->setAttributes(*it, *value);
      value++;
    }
  };

  void updateExtraInfo(Event *e, std::vector<std::string> keys, std::vector<std::string> values)
  {
    auto value = values.begin();
    for (auto it = keys.begin(); it != keys.end(); it++)
    {
      e->updateAttributes(*it, *value);
      value++;
    }
  };

  void removeExtra(Event *e)
  {
    e->removeAttributes();
  };

  // Function to Buy a ticket
  void buyTicket(Event *e)
  {
    vendor->buyTicket(e);
  };
};

#endif