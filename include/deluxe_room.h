#ifndef DELUXE_ROOM_H
#define DELUXE_ROOM_H
#include "room.h"

class DeluxeRoom : public Room {
    public:
        DeluxeRoom();
        DeluxeRoom(int number);

        bool checkin(string guestName, int adults, int children, double credit);
        double getBaseRate() const;
        string toString();

};

#endif