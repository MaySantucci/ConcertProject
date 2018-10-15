#include "HandleEvent.h"

class UserFunctions {
    public: 
    HandleEvent* handler = new HandleEvent();

    //Function to manage Events 
    void listEvents();
    void detailsEvent(int id);

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

    private:
    std::string name, place, date, price, availableTicket;
 };
 