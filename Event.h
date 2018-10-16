#ifndef __EVENT_H__
#define __EVENT_H__
#include <iostream>
#include <map>
#include <vector>

class Event
{
  public:
    Event(int id, std::string name, std::string place, std::string date,
          std::string price, std::string availableTicket);

    // getter methods
    int id() const;
    std::string name() const;
    std::string date() const;
    std::string place() const;
    std::string price() const;
    std::string availableTicket() const;

    // setter methods
    virtual void setName(const std::string& name);
    virtual void setDate(const std::string& date);
    virtual void setPlace(const std::string& place);
    virtual void setPrice(const std::string& price);
    virtual void setAvailableTicket(const std::string& availableTicket);

    // metadata
    virtual std::vector<std::string> allowedAttributes() = 0;
    // metadata getter
    std::map<std::string, std::string> attributes() const;    
    // metadata setter
    void setAttributes(std::string key, std::string value);

  private:
    int m_id;
    std::string m_name;
    std::string m_date;
    std::string m_place;
    std::string m_price;
    std::string m_availableTicket;
    std::map<std::string, std::string> m_attributes;
};
#endif