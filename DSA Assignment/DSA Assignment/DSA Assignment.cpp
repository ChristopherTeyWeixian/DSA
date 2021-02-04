#include <iostream>
#include<string>
#include "BusStop.h"
#include "Bus.h"
using namespace std;
void displayMenu();

int main()
{
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
        if (option == "1")
        {
            busstop.print();
            cout << "\n" << endl;
        }
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
        if (option == "3") 
        {
            busstop.print();
            int i;
            cout << "Key BusStop index to remove: ";
            cin >> i;
            busstop.remove(i);
            cout << "\n" << endl;
            busstop.print();
        }
        if (option == "4")
        {
            string bn;
            cout << "Key in the new Bus number: ";
            cin >> bn;
            if (bus.search(bn) == false) 
            {
                bus.add(bn);
                cout << "Bus number added in successfully" << endl;
            }
            else
            {
                cout << "There is already a bus with this number" << endl;
            }
        }
        if (option == "5") 
        {
            string bn;
            cout << "Key in the Bus number: ";
            cin >> bn;
            busstop.print();
            int bs;
            cout << "Key in the index of the BusStop: ";
            cin >> bs;
            cout<<busstop.get(bs)<<endl;
            string location = busstop.get(bs);
            bus.append(bn, location);
            
            
            
        }
        if (option == "6")
        {
            string busnum;
            cout << "which bus route to view?";
            cin >> busnum;
            cout << "Bus route for " << busnum << endl;
            bus.printroute(busnum);
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
    cout << "[4] Add new Bus" << endl;
    cout << "[5] Assign bus stop to bus" << endl;
    cout << "[6] View bus route for bus" << endl;
    cout << "[0] Exit program\n" << endl;
    cout << "Enter in your option: ";
}
