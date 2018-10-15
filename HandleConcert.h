#ifndef __HANDLECONCERT_H__
#define __HANDLECONCERT_H__

#include "Event.h"
#include "Concert.h"
#include "Show.h"
#include "Ballet.h"
#include <vector>

class HandleConcert {
    public:
    ~HandleConcert();

    //Functions to manage Event    
    void listEvents();

    void addShowToEvents(std::string name, std::string place, std::string date, std::string price, std::string availableTicket);
    void addBalletToEvents(std::string name, std::string place, std::string date, std::string price, std::string availableTicket);
    void addConcertToEvents(std::string groupName, std::string place, std::string date, std::string price, std::string availableTicket);

    //Functions to manage Concert
    void listConcerts();
    void getConcertDetails(int id);
    void addConcertToConcerts(std::string groupName, std::string place, std::string date, std::string price, std::string availableTicket);
    void updateConcert(int id);
    void deleteConcert(int id);
    
    //Functions to manage Preferred
    void addConcertToPreferred(int id);
    void deleteConcertToPreferred(int id);
    void listPreferredConcerts();
    
    bool checkIfConcertsEmpty();
    bool checkIfPreferredEmpty();

    private:
    Concert* getConcertById(int id, int& position);
    Concert* getPreferredById(int id, int& position);

    //variables
    int code = 0;
    
    std::vector<Concert*> concerts;
    std::vector<Concert*> preferredConcerts;

    std::vector<Event*> events;

};

#endif