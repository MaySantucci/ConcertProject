#include "UserFunctions.h"
#include "Ballet.h"
#include "Concert.h"
#include "Show.h"
#include <iostream>
#include <string>
#include <memory>

// Functions to manage Events

void UserFunctions::listEvents()
{

  const std::vector<std::unique_ptr<Event>>& events = handler->listEvents();
  if (!events.empty())
  {
    for (auto &event : events)
    {
      printDetails(event.get());
    }
  }
  else
  {
    std::cout << "No events stored. \n";
  }
}

void UserFunctions::printDetails(Event* e)
{
  std::cout << "Id: " << e->id() << " Name: " << e->name() << "\n";
  std::cout << "Place: " << e->place() << " Date: " << e->date() << "\n";
  std::cout << "Price: " << e->price()
            << " Available Ticket: " << e->availableTicket() << "\n";
}

void UserFunctions::showForm(std::string &n, std::string &pl, std::string &d,
                             std::string &pr, std::string &ticket)
{
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

void UserFunctions::insertEvent(std::string type_event)
{

  showForm(name, place, date, price, availableTicket);
  //Event *event = nullptr;
  if (type_event == "a")
  {
    // add Show to Events
    std::unique_ptr<Event> show = std::make_unique<Show>(idEvent, name, place, date, price, availableTicket);
    handler->addEventToEvents(std::move(show));
    idEvent++;
  }
  else if (type_event == "b")
  {
    // add Ballet to Events
    std::unique_ptr<Event> ballet = std::make_unique<Ballet>(idEvent, name, place, date, price, availableTicket);
    handler->addEventToEvents(std::move(ballet));
    idEvent++;
  }
  else if (type_event == "c")
  {
    std::unique_ptr<Event> concert = std::make_unique<Concert>(idEvent, name, place, date, price, availableTicket);
    handler->addEventToEvents(std::move(concert));
    idEvent++;
  }
}

bool UserFunctions::checkEventsInit()
{
  if (handler->checkIfEventsEmpty())
  {
    return true;
  }
  return false;
}

void UserFunctions::detailsEvent(int id)
{
  int position = -1;
  Event* event = handler->getEventById(id, position);

  if (event == nullptr)
  {
    std::cout << "Event with this id not found. \n";
  }
  else
  {
    printDetails(event);
    if (!event->attributes().empty())
    {
      printExtraInfo(event->attributes());
    }
  }
}

void UserFunctions::updateEvent(int id)
{
  int position = -1;
  Event* found = handler->getEventById(id, position);
  if (found != nullptr)
  {
    showForm(name, place, date, price, availableTicket);
    handler->updateEvent(position, name, place, date, price, availableTicket);
    std::cout << "Event updated. \n";
  }
  else
  {
    std::cout << "Event not found. \n";
  }
}

void UserFunctions::addExtraInfo(int id)
{
  int position = -1;
  Event* found = handler->getEventById(id, position);

  if (found != nullptr)
  {
    // show form for extra.
    std::vector<std::string> att = found->allowedAttributes();
    if (!att.empty())
    {
      std::vector<std::string> valueExtra = formExtra(att);
      if (!valueExtra.empty())
      {
        // add extra info to event
        handler->addExtra(found, att, valueExtra);
        std::cout << "Extra informations added. \n";
      }
    }
    else
    {
      std::cout << "No extra info form available for this event. \n";
    }
    // add info to event
    // handler->addExtra(id);
  }
  else
  {
    std::cout << "Event not found. \n";
  }
}

std::vector<std::string>
UserFunctions::formExtra(std::vector<std::string> &att)
{
  std::vector<std::string> results;
  std::string input;
  for (auto it = att.begin(); it != att.end(); it++)
  {
    std::cout << *it << ": ";
    std::cin.ignore();
    std::getline(std::cin, input);
    results.push_back(input);
  }
  return results;
}

void UserFunctions::listExtraInfo(int id)
{
  int position = -1;
  Event* found = handler->getEventById(id, position);
  if (found != nullptr && !found->attributes().empty())
  {
    printExtraInfo(found->attributes());
  }
  else
  {
    std::cout << "No extra information stored for this event.\n";
  }
}

void UserFunctions::printExtraInfo(
    std::map<std::string, std::string> attributes)
{
  for (auto it = attributes.begin(); it != attributes.end(); it++)
  {
    std::cout << it->first << ": " << it->second << "\n";
  }
}

void UserFunctions::updateExtraInfo(int id)
{
  int position = -1;
  Event* found = handler->getEventById(id, position);
  if (found != nullptr)
  {
    std::vector<std::string> att = found->allowedAttributes();
    if (!found->attributes().empty())
    {
      std::vector<std::string> results = formExtra(att);
      handler->updateExtraInfo(found, att, results);
    }
    else
    {
      std::cout
          << "Impossible to edit extra informations for this event because "
             "there is not extra informations stored for this event. \n";
    }
  }
  else
  {
    std::cout << "No event found. \n";
  }
}

void UserFunctions::deleteExtraInfo(int id)
{
  int position = -1;
  Event* found = handler->getEventById(id, position);

  if (found != nullptr)
  {
    if (!found->attributes().empty())
    {
      handler->removeExtra(found);
    }
    else
    {
      std::cout
          << "Impossible to edit extra informations for this event because "
             "there is not extra informations stored for this event. \n";
    }
  }
}

void UserFunctions::deleteEvent(int id)
{
  int eventPosition = -1;
  int preferredPosition = -1;
  if (handler->getEventById(id, eventPosition) != nullptr)
  {
    // check if the event is present in favourite's event.
    if (handler->getPreferredById(id, preferredPosition) != nullptr)
    {
      handler->removeFromPreferred(preferredPosition);
    }

    handler->removeEvent(eventPosition);
    int size = handler->listEvents().size();
    std::cout << "Event removed. \n";
  }
  else
  {
    std::cout << "Event not found. \n";
  }
}

void UserFunctions::insertPreferredEvent(int id)
{
  int position = -1;
  Event* found = handler->getEventById(id, position);
  if (found != nullptr)
  {
    handler->addToPreferred(found);
  }
  else
  {
    std::cout
        << "Event with this id not found. Impossible to add in Favourite. \n";
  }
}

// Functions to manage Preferred Events
void UserFunctions::listPreferredEvents()
{
  std::vector<Event *> favourites = handler->listPreferredEvents();
  if (!favourites.empty())
  {
    for (auto favourite : favourites)
    {
      printDetails(favourite);
    }
  }
  else
  {
    std::cout << "No events stored in favourites. \n";
  }
}
bool UserFunctions::checkPreferredEventsInit()
{
  return handler->checkIfPreferredEventsEmpty();
}
void UserFunctions::deletePreferredEvent(int id)
{
  int position = -1;
  Event* found = handler->getPreferredById(id, position);
  if (found != nullptr)
  {
    handler->removeFromPreferred(position);
  }
  else
  {
    std::cout << "Event not stored in favourites. \n";
  }
}

void UserFunctions::buyTicket(int id)
{
  int position = -1;
  Event* found = handler->getEventById(id, position);
  if (found != nullptr)
  {
    handler->buyTicket(found);
  } else {
    std::cout << "event not found. \n";
  }
}