#ifndef ROOM_H
#define ROOM_H
#include <iostream>
using namespace std;

class Room {
    protected:
        int number,
            adults,
            children;

        string guestName;

        double credit,
               charge;
        bool available;

    public:
        Room();
        Room(int number);

        int getNumber();
        bool isAvailable();
        void setNumber(int newNumber);
        bool checkout();
        bool makeCharge(double charge);

        virtual bool checkin(string guestName, int adults, int children, double credit);
        virtual double getBaseRate() const;
        virtual string toString() = 0;

        // Overload +
        friend double operator+(double accumulated, const Room& room);
};

#endif