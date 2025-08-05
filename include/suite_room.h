#ifndef SUITE_ROOM_H
#define SUITE_ROOM_H
#include "room.h"

class SuiteRoom : public Room {
    public:
        SuiteRoom();
        SuiteRoom(int number);

        bool checkin(string guestName, int adults, int children, double credit);
        double getBaseRate() const;
        string toString();
};

#endif