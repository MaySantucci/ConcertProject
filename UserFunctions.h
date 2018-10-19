#include "HandleEvent.h"
#include "Event.h"
#include "Vendor.h"

class UserFunctions {
    public: 
    int idEvent = 0;
    //Function to manage Events 
    void listEvents();
    void detailsEvent(int id);

    void insertEvent(std::string type_event);    
    void showForm(std::string& n, std::string& pl, std::string& d, std::string& pr, std::string& ticket);
    bool checkEventsInit();

    void printDetails(Event* e);

    void updateEvent(int id);
    void deleteEvent(int id);

    //Function to manage Preffered Events
    void listPreferredEvents();
    bool checkPreferredEventsInit();
    void insertPreferredEvent(int id);
    void deletePreferredEvent(int id);

    //Function to add MetaData
    void addExtraInfo(int id);
    void listExtraInfo(int id);
    void updateExtraInfo(int id);
    void deleteExtraInfo(int id);

    void buyTicket(int id);

    HandleEvent<Vendor,Event>* handler = new HandleEvent<Vendor,Event>();

    private:
    std::string name, place, date, price, availableTicket;
 };
 