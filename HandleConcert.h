#ifndef __HANDLECONCERT_H__
#define __HANDLECONCERT_H__

#include "Concert.h"

class HandleConcert {
    public:
    HandleConcert();

    //Functions to manage Concert
    void listConcerts();
    bool checkAddConcertToConcerts();
    bool checkIfConcertsEmpty();
    void addConcertToConcerts(std::string groupName, std::string place, std::string date, std::string price, std::string availableTicket);

    void updateConcert(int id);
    void deleteConcert(int id);
    
    void getConcertDetails(int id);

    void resizeConcerts();

    //Functions to manage Prefered
    void listPreferedConcerts();
    bool checkAddConcertToPrefered();
    void addConcertToPrefered(int id);
    void deleteConcertToPrefered(int id);

    void resizePrefered();

    //Concert's variables
    int num_registered_concerts = 0;
    int size_concerts;
    int code = 0;
    
    Concert** concerts;

    //Prefered's variables
    int num_prefered_concerts = 0;
    int size_prefered;

    Concert** preferedConcerts;

};

#endif