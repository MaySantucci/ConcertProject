#ifndef __HANDLECONCERT_H__
#define __HANDLECONCERT_H__

#include "Concert.h"
#include <vector>

class HandleConcert {
    public:
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

    //Functions to manage Preferred
    
    Concert* getPreferredById(int id, int& position);

    void listPreferredConcerts();
    bool checkIfPreferredEmpty();
    bool checkAddConcertToPreferred();
    void addConcertToPreferred(int id);

    void shiftPreferredToLeft(int startingPosition);
    void deleteConcertToPreferred(int id);

    //Concert's variables
    int code = 0;
    
    std::vector<Concert*> concerts;
    std::vector<Concert*> preferredConcerts;

};

#endif