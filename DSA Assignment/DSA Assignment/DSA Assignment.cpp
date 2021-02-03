#include <iostream>
#include<string>
#include "BusStop.h"
using namespace std;
void displayMenu();

int main()
{
    //dummy data
    List busstop;
    string s1 = "King";
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
    //BList bus;
    //bus.add("160m");
    //bus.add("180");
    //bus.add("944");

    
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
            //search for any existing Bus Stop name
            if (busstop.search(n) == false)
            {
                cout << "asd" << endl;
                busstop.add(n);
                displayMenu();
            }
            else
            {
                cout << "There is already an existing BusStop with this name" << endl;
            }
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
    cout << "[3] Find Bus number based on location" << endl;
    cout << "[0] Exit program\n" << endl;
    cout << "Enter in your option: ";
}
