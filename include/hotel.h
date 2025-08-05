#ifndef HOTEL_H
#define HOTEL_H
#include "room.h"
#include <iostream>
#include <vector>
using namespace std;

class Hotel {
    private: 
        int numRooms;
        string name;
        vector<Room*> rooms;
    
    public:
        Hotel(string name);

        int checkin(string guestName, int adults, int children, double credit, int roomType);
        bool checkout(int roomNumber);
        bool makeRoomCharges(int roomNumber, double charge);
        double getTotalByBaseRate() const;
        void printOccupancy();
        void addRooms(Room* room);

        // operator[] overload
        Room* operator[](int roomNumber);

        // operator<< overload
        friend ostream& operator<<(ostream& os, const Hotel& hotel);
        
};

#endif