#ifndef __HANDLECONCERT_H__
#define __HANDLECONCERT_H__

#include "Concert.h"

class HandleConcert {
    public:
    HandleConcert();

    Concert* getConcertById(int id);
    Concert* getConcertById(int id, int& position);

    //Functions to manage Concert
    void listConcerts();
    bool checkAddConcertToConcerts();
    bool checkIfConcertsEmpty();
    void addConcertToConcerts(std::string groupName, std::string place, std::string date, std::string price, std::string availableTicket);

    void updateConcert(int id);
    void shiftConcertToLeft(int startingPosition);
    void deleteConcert(int id);
    
    void getConcertDetails(int id);

    void resizeConcerts();

    //Functions to manage Preferred
    
    Concert* getPreferredById(int id, int& position);

    void listPreferredConcerts();
    bool checkIfPreferredEmpty();
    bool checkAddConcertToPreferred();
    void addConcertToPreferred(int id);

    void shiftPreferredToLeft(int startingPosition);
    void deleteConcertToPreferred(int id);

    void resizePreferred();

    //Concert's variables
    int num_registered_concerts = 0;
    int size_concerts;
    int code = 0;
    
    Concert** concerts;

    //Preferred's variables
    int num_preferred_concerts = 0;
    int size_preferred;

    Concert** preferredConcerts;

};

#endif