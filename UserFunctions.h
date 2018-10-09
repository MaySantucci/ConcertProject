#include "HandleConcert.h"

class UserFunctions {
    public: 
    HandleConcert* handler = new HandleConcert();
    //Functions to manage Concerts
    void listConcerts();
    void detailsConcert(int id);
    void insertConcert();
    void showForm();
    bool checkConcertsInit();
    void updateConcert(int id);
    void deleteConcert(int id);

    //Functions to manage Prefered
    void listPreferedConcerts();
    void insertPrefered(int id);
    void deletePrefered(int id);

    private:
    std::string group_name, place, date, price, available_ticket;
 };
 