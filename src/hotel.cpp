#include "../include/hotel.h"
#include "../include/junior_room.h"
#include "../include/suite_room.h"
#include "../include/deluxe_room.h"
#include <iostream>
using namespace std;

Hotel::Hotel(string name) {
    this->name = name;
}

int Hotel::checkin(string guestName, int adults, int children, double credit, int roomType) {
    for (int i = 0; i < this->rooms.size(); i++) {
        // Use dynamic_cast for different room types.
        if ((roomType == 1 && dynamic_cast<JuniorRoom*>(this->rooms[i])) ||
            (roomType == 2 && dynamic_cast<SuiteRoom*>(this->rooms[i])) ||
            (roomType == 3 && dynamic_cast<DeluxeRoom*>(this->rooms[i]))) {
            if (this->rooms[i]->isAvailable()) {
                bool registered = this->rooms[i]->checkin(guestName, adults, children, credit);
                if (registered) {
                    return this->rooms[i]->getNumber();
                }
            }
        }        
    }
    return -1;
}

bool Hotel::checkout(int roomNumber) {
    for (int i = 0; i < this->rooms.size(); i++) {
        if (this->rooms[i]->getNumber() == roomNumber) {
            return this->rooms[i]->checkout();
        }
    }
    return false;
}

bool Hotel::makeRoomCharges(int roomNumber, double charge) {
    Room* room = operator[](roomNumber);
    if (room != nullptr && room->isAvailable() == false) {
        return room->makeCharge(charge);
    }
    return false;
}

double Hotel::getTotalByBaseRate() const {
    double total = 0.0;
    for (int i = 0; i < this->rooms.size(); i++) {
        if (this->rooms[i]->isAvailable() == false) {
            total = total + *rooms[i]; // uses the overloaded + operator from room.cpp
        }
    }
    return total;
}

void Hotel::printOccupancy() {
    cout << "Occupancy in Hotel " << this->name << endl;
    for (int i = 0; i < this->rooms.size(); i++) {
        if (this->rooms[i]->isAvailable() == false) {
            cout << this->rooms[i]->toString() << endl;
        }
    }
}

void Hotel::addRooms(Room* room) {
    this->rooms.push_back(room);
}

Room* Hotel::operator[](int roomNumber) {
    for (int i = 0; i < this->rooms.size(); i++) {
        if (this->rooms[i]->getNumber() == roomNumber) {
            return this->rooms[i];
        }
    }
    return nullptr;
}

// Operator[] overload: iterates through the rooms vector and compares the room number with the parameter.
// Returns the pointer if found, nullptr otherwise.

ostream& operator<<(ostream& os, const Hotel& hotel) {
    os << "Hotel " << hotel.name << endl;
    for (int i = 0; i < hotel.rooms.size(); i++) {
        if (hotel.rooms[i]->isAvailable() == false)
            os << hotel.rooms[i]->toString() << endl;
    }
    os << "Total accumulated by base rate: $" << hotel.getTotalByBaseRate();
    return os;
}
