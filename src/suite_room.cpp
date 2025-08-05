#include "../include/suite_room.h"
#include <iostream>
using namespace std;

SuiteRoom::SuiteRoom() : Room() {}
SuiteRoom::SuiteRoom(int number) : Room(number) {}

bool SuiteRoom::checkin(string guestName, int adults, int children, double credit) {
    if ((adults + children) <= 6) {
        return Room::checkin(guestName, adults, children, credit);
    } else {
        return false;
    }
}

double SuiteRoom::getBaseRate() const {
    return Room::getBaseRate() * 1.3;
}

string SuiteRoom::toString() {
    return to_string(this->number) + ",Guest:" + this->guestName + ",Base Rate:" + to_string(getBaseRate()) +
           ",Credit:" + to_string(this->credit) + ",Charges:" + to_string(this->charge) + ", Suite Room";
}