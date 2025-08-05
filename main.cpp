#include "hotel.h"
#include "../include/junior_room.h"
#include "../include/suite_room.h"
#include "../include/deluxe_room.h"
#include <iostream>
using namespace std;

int main() {

    string hotel_name;
    int num_junior,
        num_suite,
        num_deluxe;
    int option,
        room_number = 100;

    cout << "What is the name of the Hotel?: " << endl;
    getline(cin, hotel_name);
    Hotel userHotel(hotel_name);

    cout << "How many junior rooms do you want to create?: ";
    cin >> num_junior;
    cout << "How many suite rooms do you want to create?: ";
    cin >> num_suite;
    cout << "How many deluxe rooms do you want to create?: ";
    cin >> num_deluxe;

    for (int i = 0; i < num_junior; i++) {
        userHotel.addRooms(new JuniorRoom(room_number++));
    }

    for (int i = 0; i < num_suite; i++) {
        userHotel.addRooms(new SuiteRoom(room_number++));
    }

    for (int i = 0; i < num_deluxe; i++) {
        userHotel.addRooms(new DeluxeRoom(room_number++));
    }

    do {
        cout << "Hotel Menu: " << hotel_name << endl;
        cout << "1. Check-in\n";
        cout << "2. Check-out\n";
        cout << "3. Make charges to room\n";
        cout << "4. Income by rate\n";
        cout << "5. Generate occupancy report\n";
        cout << "6. Exit\n";
        cin >> option;

        switch (option)
        {
        case 1: {
            string guest_name;
            int adults, 
                children,
                room_type;
            double credit;
            cout << "What is the guest's name?: ";
            cin.ignore();
            getline(cin, guest_name);
            cout << "How many adults?: ";
            cin >> adults;
            cout << "How many children?: ";
            cin >> children;
            cout << "What is the available credit?: ";
            cin >> credit;
            cout << "What is the room type?\n";
            cout << "1. Junior\n";
            cout << "2. Suite\n";
            cout << "3. Deluxe\n";
            cin >> room_type;

            int assigned_room = userHotel.checkin(guest_name, adults, children, credit, room_type);
            
            if (assigned_room != -1) {
                cout << "The guest has been registered in room: " << assigned_room << endl;
            } else {
                int total_people = adults + children;
                if (room_type == 3 && total_people > 8) {
                    cout << "Exceeded the number of people for the Deluxe room, please make separate reservations" << endl;
                } else if ((room_type == 1 && total_people > 4) || (room_type == 2 && total_people > 6)) {
                    cout << "Exceeded the number of people for this room" << endl;
                } else {
                    cout << "The hotel is already full" << endl;
                }
            }
            break;
        }
        case 2: {
                int room_num;
                cout << "What is the room number for checkout?: " << endl;
                cin >> room_num;

                Room* room = userHotel[room_num]; // using operator[]
                if (room != nullptr) {
                    if (room->checkout()) {
                        cout << "Checkout successful :)" << endl;
                    } else {
                        cout << "Cannot checkout because the room is available" << endl;
                    }
                }
                break;
        }
        case 3: {
            int room_num;
            double charge;
            cout << "What is the room number?: " << endl;
            cin >> room_num;
            cout << "What is the charge?: " << endl;
            cin >> charge;

            if (userHotel.makeRoomCharges(room_num, charge)) {
                cout << "The charge was made successfully :)" << endl; 
            } else {
                cout << "The charge was not made" << endl;
            }
            break;
        }
        case 4:
            cout << userHotel << endl;
            cout << "The total money collected today is: $" << userHotel.getTotalByBaseRate() << endl;
            break;
        case 5:
            userHotel.printOccupancy();
            break;
        case 6:
            cout << "Thank you. Sincerely: Hotel " << hotel_name << endl;
            break;
        default:
            cout << "Option not available in the menu, please try again" << endl;
        }
    } while (option != 6);
    return 0;
}

