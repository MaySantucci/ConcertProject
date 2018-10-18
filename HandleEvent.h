#ifndef __HANDLECONCERT_H__
#define __HANDLECONCERT_H__

#include "Event.h"
#include "Concert.h"
#include "Show.h"
#include "Ballet.h"
#include "Vendor.h"
#include <vector>

template <typename T>
class HandleEvent {
    public:
    HandleEvent();
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

    //Function to manage ExtraInfo
    void addExtra(int id);
    void printExtra(int id);
    void updateExtra(int id);
    void deleteExtra (int id);

    void formExtra(std::vector<std::string>& att, int position, std::string type);

    //Function to Buy a ticket
    void buyTicket(int id);

    //variables
    int code = 0;

    std::vector<Event*> events;
    std::vector<Event*> preferredEvents;

    T* vendor;


};

#endif