#ifndef __VENDOR_H__
#define __VENDOR_H__

#include "Event.h"
#include <memory>

class Vendor {
public:
  void buyTicket(Event* e);
};

#endif