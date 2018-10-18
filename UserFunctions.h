#include "HandleEvent.h"
#include "Event.h"
#include "Show.h"
#include "Ballet.h"
#include "Concert.h"

class UserFunctions {
    public: 
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

    //Function to add MetaData
    void addExtraInfo(int id);
    void listExtraInfo(int id);
    void updateExtraInfo(int id);
    void deleteExtraInfo(int id);

    void buyTicket(int id);


    HandleEvent<Vendor,Event>* handler = new HandleEvent<Vendor,Event>();
    HandleEvent<Vendor, Show>* handlerShow = new HandleEvent <Vendor, Show>();
    HandleEvent<Vendor, Ballet>* handlerBallet = new HandleEvent <Vendor, Ballet>();
    HandleEvent<Vendor, Concert>* handlerConcert = new HandleEvent <Vendor, Concert>();

    private:
    std::string name, place, date, price, availableTicket;
 };
 