#include "../include/deluxe_room.h"
#include <iostream>
using namespace std;

DeluxeRoom::DeluxeRoom() : Room() {}
DeluxeRoom::DeluxeRoom(int number) : Room(number) {}

bool DeluxeRoom::checkin(string guestName, int adults, int children, double credit) {
    if ((adults + children) <= 8) {
        return Room::checkin(guestName, adults, children, credit);
    } else {
        return false;
    }
}

double DeluxeRoom::getBaseRate() const {
    return Room::getBaseRate() * 1.5;
}

string DeluxeRoom::toString() {
    return to_string(this->number) + ",Guest:" + this->guestName + ",Base Rate:" + to_string(getBaseRate()) +
           ",Credit:" + to_string(this->credit) + ",Charges:" + to_string(this->charge) + ", Deluxe Room";
}
