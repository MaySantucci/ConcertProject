#ifndef __CONCERT_H__
#define __CONCERT_H__

#include <string>
#include <iostream>
class Concert {
    public:
    Concert();
    Concert(int id, std::string groupName, std::string place, std::string date, std::string price, std::string availableTicket);
    int id();
    std::string groupName();
    std::string place();
    std::string date();
    std::string price();
    std::string availableTicket();

    void setGroupName(std::string groupName);
    void setPlace(std::string place);
    void setDate(std::string date);
    void setPrice(std::string price);
    void setAvailableTicket(std::string availableTicket);
   
    private:
    int m_id;
    std::string m_groupName;
    std::string m_place;
    std::string m_date;
    std::string m_price;
    std::string m_availableTicket;
};

#endif