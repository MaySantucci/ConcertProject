#include "HandleConcert.h"

class UserFunctions {
    public: 
    HandleConcert* handler = new HandleConcert();

    //Function to manage Events 
    void listEvents();
    void detalisEvents();

    void insertEvent(std::string type_event);    
    void showForm(std::string& n, std::string& pl, std::string& d, std::string& pr, std::string& ticket);

    bool checkEventsInit();
    void updateEvent(int id);
    void deleteEvent(int id);

    //Function to manage Preffered Events
    void listPreferredEvents();
    bool checkPreferredEventsInit();
    void insertPreferredEvent(int id);
    void deletePreferredEvent(int id);

    //Functions to manage Concerts
    void listConcerts();
    void detailsConcert(int id);
    void insertConcert();
    bool checkConcertsInit();
    void updateConcert(int id);
    void deleteConcert(int id);

    //Functions to manage Preferred
    void listPreferredConcerts();
    bool checkPreferredInit();
    void insertPreferred(int id);
    void deletePreferred(int id);

    private:
    std::string name;
    std::string groupName, place, date, price, availableTicket;
 };
 