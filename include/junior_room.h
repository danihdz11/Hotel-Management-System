#ifndef JUNIOR_ROOM_H
#define JUNIOR_ROOM_H
#include "room.h"

class JuniorRoom : public Room {
    public:
        JuniorRoom();
        JuniorRoom(int number);

        bool checkin(string guestName, int adults, int children, double credit);
        double getBaseRate() const;
        string toString();
};



#endif