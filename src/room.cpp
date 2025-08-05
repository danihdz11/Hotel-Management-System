#include "../include/room.h"
#include <iostream>
using namespace std;

Room::Room() {
    this->guestName = "";
    this->adults = 0;
    this->children = 0;
    this->number = 0;
    this->credit = 0.0;
    this->charge = 0.0;
    this->available = true;
}

Room::Room(int number) {
    this->number = number;
    this->available = true;
}

int Room::getNumber() {
    return this->number;
}

bool Room::isAvailable() {
    return this->available;
}

void Room::setNumber(int newNumber) {
    this->number = newNumber;
}

bool Room::checkin(string guestName, int adults, int children, double credit) {
    if (this->available) {
        this->guestName = guestName;
        this->adults = adults;
        this->children = children;
        this->credit = credit;
        this->charge = 0.0;
        this->available = false;
        return true;
    } else {
        return false;
    }
}

bool Room::checkout() {
    if (this->available == false) {
        this->guestName = "";
        this->adults = 0;
        this->children = 0;
        this->charge = 0.0;
        this->credit = 0.0;
        this->available = true;
        return true;
    } else {
        return false;
    }
}

bool Room::makeCharge(double charge) {
    if (charge > 0 && (this->charge + charge) <= this->credit) {
        this->charge += charge;
        return true;
    } else {
        return false;
    }
}

double Room::getBaseRate() const {
    return this->adults * 650.0 + this->children * 250.0;
}

double operator+(double accumulated, const Room& room) {
    return accumulated + room.getBaseRate();
}