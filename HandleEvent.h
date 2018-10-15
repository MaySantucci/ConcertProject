#ifndef __HANDLECONCERT_H__
#define __HANDLECONCERT_H__

#include "Event.h"
#include "Concert.h"
#include "Show.h"
#include "Ballet.h"
#include <vector>

class HandleEvent {
    public:
    ~HandleEvent();

    //Functions to manage Events    
    void listEvents();

    void addShowToEvents(std::string name, std::string place, std::string date, std::string price, std::string availableTicket);
    void addBalletToEvents(std::string name, std::string place, std::string date, std::string price, std::string availableTicket);
    void addConcertToEvents(std::string groupName, std::string place, std::string date, std::string price, std::string availableTicket);

    bool checkIfEventsEmpty();
    Event* getEventById(int id, int& position);
    void getEventDetails(int id);

    void updateEvent(int id);
    void removeEvent(int id);

    //Functions to manage Preferred Events
    void listPreferredEvents();
    bool checkIfPreferredEventsEmpty();
    void addToPreferred(int id);
    Event* getPreferredById(int id, int& position);
    void removeFromPreferred(int id);

    //variables
    int code = 0;

    std::vector<Event*> events;
    std::vector<Event*> preferredEvents;

};

#endif