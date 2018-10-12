#ifndef __HANDLECONCERT_H__
#define __HANDLECONCERT_H__

#include "Concert.h"
#include <vector>

class HandleConcert {
    public:
    ~HandleConcert();


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

    private:
    Concert* getConcertById(int id, int& position);
    Concert* getPreferredById(int id, int& position);

    
    bool checkIfConcertsEmpty();
    bool checkIfPreferredEmpty();
    //Concert's variables
    int code = 0;
    
    std::vector<Concert*> concerts;
    std::vector<Concert*> preferredConcerts;

};

#endif