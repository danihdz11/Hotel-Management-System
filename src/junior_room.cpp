#include "../include/junior_room.h"
#include <iostream>
using namespace std;

JuniorRoom::JuniorRoom() : Room() {}
JuniorRoom::JuniorRoom(int number) : Room(number) {}

bool JuniorRoom::checkin(string guestName, int adults, int children, double credit) {
    if ((adults + children) <= 4) {
        return Room::checkin(guestName, adults, children, credit);
    } else {
        return false;
    }
}

double JuniorRoom::getBaseRate() const {
    return Room::getBaseRate() * 1.2;
}

string JuniorRoom::toString() {
    return to_string(this->number) + ",Guest:" + this->guestName + ",Base Rate:" + to_string(getBaseRate()) +
           ",Credit:" + to_string(this->credit) + ",Charges:" + to_string(this->charge) + ", Junior Room";
}