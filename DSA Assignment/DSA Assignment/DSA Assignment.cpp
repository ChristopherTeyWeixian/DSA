#include <iostream>
#include<string>
#include "BusStop.h"
#include "Bus.h"
#include "BusDriver.h"
#include "Schedule.h"
using namespace std;
void displayMenu();

int main()
{
    ScheduleList Schedule;
    BST BusDriver;
    //dummy data
    List busstop;
    string s1 = "King albert";
    string s2 = "Sengkang";
    string s3 = "WaterWay Park";
    string s4 = "Clementi";
    string s5 = "Bukit Batok";
    string s6 = "Ngee Ann Poly";
    busstop.add(s1);
    busstop.add(s2);
    busstop.add(s3);
    busstop.add(s4);
    busstop.add(s5);
    busstop.add(s6);



    //dummy data for bus
    BList bus;
    //bus.add("120");
    //bus.add("bukit batok");

    
    string option = "1";
    bool on = true;

    while (on==true)
    {
        displayMenu();
        cin >> option;
        cout << "\n" << endl;
        //Benjamin- display sorted list of BusStop
        if (option == "1")
        {
            busstop.print();
            cout << "\n" << endl;
        }
        //Benjamin- adding new busstop name
        if (option == "2")
        {
            string n;
            cin.ignore();
            cout << "Enter new busStop Name: ";
            getline(cin, n);
            transform(n.begin(), n.end(), n.begin(), ::toupper);
            //search for any existing Bus Stop name
            if (busstop.search(n) == false)
            {
                busstop.add(n);
                busstop.print();
            }
            else
            {
                cout << "There is already an existing BusStop with this name" << endl;
            }
        }
        //Benjamin - Remove BusStop
        if (option == "3") 
        {
            busstop.print();
            int i;
            cout << "Key BusStop index to remove: ";
            cin >> i;
            busstop.remove(i);
            cout << "\n" << endl;
            busstop.print();
            cin.clear();
        }
        //Benjamin - add a BusStop to a busroute
        if (option == "4") 
        {
            string bn;
            cout << "Key in the Bus number: ";
            cin >> bn;
            busstop.print();
            int bs;
            cout << "Key in the index of the BusStop: ";
            cin >> bs;
            if (bs == 0)
            {
                cin.clear();
            }
            else
            {
                cout << busstop.get(bs) << endl;
                string location = busstop.get(bs);
                if (location == "Invalid Index")
                {

                }
                else
                {
                    bus.append(bn, location);
                }
            
            }
                
         }

           
            
            
        
        //Benjamin-View bus route of specific bus 
        if (option == "5")
        {
            string busnum;
            cout << "which bus route to view?";
            cin >> busnum;
            cout << "Bus route for " << busnum << endl;
            bus.printroute(busnum);
        }
        //Chris-View All Bus Drivers
        if (option == "6")
        {
            cout << "\n View All Bus Drivers" << endl;
            cout << "=====================" << endl;
            BusDriver.inorder();
            cout << "\n" << endl;
        }
        //Chris-Add Bus Driver
        if (option == "7")
        {
            string name;
            int age, ID;
            cout << "\n View All Bus Drivers" << endl;
            cout << "=====================" << endl;
            BusDriver.inorder();
            cout << "Enter Unique ID number for the Bus Driver:";
            cin >> ID;


            cout << "Enter Bus Driver's Full Name: ";
            cin >> ws;
            getline(cin, name);
            BinaryNode* p = BusDriver.search(ID, name);
            if (p != NULL) {
                cout << "ID number or Name already exist\n" << endl;
            }
            else {
                cout << "Enter Bus Driver's Age: ";
                cin >> age;
                if (age < 18) //check if it meets the legal age to work
                {
                    cout << "Too Young to be a Bus Driver\n" << endl;
                }
                else 
                {
                    BusDriver.insert(ID, name, age, "Available");
                    cout << name << " has been added\n" << endl;
                }
            }
        }
        //Chris-Remove Bus Driver
        if (option == "8")
        {
            string name;
            int ID;
            cout << "\n View All Bus Drivers" << endl;
            cout << "=====================" << endl;
            BusDriver.inorder();

            cout << "Enter Bus Driver's ID: ";
            cin >> ID;

            BinaryNode* p = BusDriver.search(ID, name);
            if (p != NULL) {
                BusDriver.remove(ID);
                cout << ID << " has been removed\n" << endl;
            }
            else {
                cout << ID << " Not Found\n" << endl;
            }
        }

        //Chris-To Update Bus Driver's Status to Available,Unavailable
        if (option == "9")
        {
            int ID;
            string status;
            cout << "\n View All Bus Drivers" << endl;
            cout << "=====================" << endl;
            BusDriver.inorder();

            cout << "Enter Bus Driver's ID To Update Status: ";
            cin >> ID;
            BinaryNode* p = BusDriver.search(ID, "");
            if (p != NULL) {
                cout << "Enter The Working Status of this Bus Driver(Available / Unavailable):";
                cin >> status;
                if (status == "Available" || status == "Unavailable")
                {
                    BusDriver.Update(ID, status);
                    cout << "Working status Of Bus Driver ID "<<ID << " has been Changed\n" << endl;

                }
                else {
                    cout << "Invaild Status" << endl;
                }
            }
            else {
                cout << ID << " Not Found\n" << endl;
            }
            
        }
        //Chris-Add Schedule to Bus Driver
        if (option == "10")
        {
            string date, name;
            int ID;
            int bus, starttime, endtime;
            cout << "\nAll Bus Drivers" << endl;
            cout << "=====================" << endl;
            BusDriver.inorder();
            cout << "Enter Bus Driver's ID: ";
            cin >> ID;

            BinaryNode* p = BusDriver.search(ID, "");
            if (p != NULL) {
                cout << "Enter the shift date: ";
                cin >> date;

                cout << "Enter the Bus Number for the shift: ";
                cin >> bus;

                cout << "Enter the Starting Time for the shift(24-hr format): ";
                cin >> starttime;

                cout << "Enter the Ending Time for the shift(24-hr format): ";
                cin >> endtime;

                Schedule.add(ID, date, bus, starttime, endtime);
                cout << "Schedule Added to Bus Driver ID " << ID << "\n" << endl;
            }
            else
            {
                cout << "ID number or name does not exist in the database\n" << endl;
            }
        }
        //Chris-To Print The Schedules
        if (option == "11")
        {
            Schedule.print();
        }
        
        //End the Program
        if (option == "0") 
        {
            on = false;
        }
    }
}

//The Menu
void displayMenu()
{
    cout << "-------Menu-------" << endl;
    cout << "[1] Display all BusStop" << endl;
    cout << "[2] Add new BusStop" << endl;
    cout << "[3] Remove BusStop" << endl;
    cout << "[4] Assign bus stop to bus" << endl;
    cout << "[5] View bus route for bus" << endl;
    cout << "[6] View All Bus Drivers" << endl;
    cout << "[7] Add Bus Driver" << endl;
    cout << "[8] Remove Bus Driver" << endl;
    cout << "[9] Update Bus Driver's Status" << endl;
    cout << "[10] Add Schedule to Bus Driver" << endl;
    cout << "[11] View All Schedule" << endl;
    cout << "[0] Exit program\n" << endl;
    cout << "Enter in your option: ";
}
