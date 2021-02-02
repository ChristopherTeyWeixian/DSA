#include <iostream>
#include<string>
#include "BusStop.h"
using namespace std;
void displayMenu();

int main()
{
    //dummy data
    List busstop;
    string s1 = "King Albert";
    string s2 = "Sengkang Interchange";
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
    int option = 1;
   
    while (option != 0) 
    {
        displayMenu();
        cin >> option;
        cout << "\n" << endl;
        if (option == 1) 
        {
            busstop.print();
            cout << "\n" << endl;
        }
        if (option == 2) 
        {
            string n;
            cout << "what is the new busStop?";
            cin >> n;
            if (busstop.search(n) == false) 
            {
                cout << "sada" << endl;
                busstop.add(n);
            }
            else
            {
                cout << "There is already an existing BusStop with this name" << endl;
            }
        }
    }
    
        

}
void displayMenu() 
{
    cout << "-------Menu-------" << endl;
    cout << "[1] Display all BusStop"<<endl;
    cout << "[2] Add new BusStop" << endl;
    cout << "[3] Find Bus number based on location" << endl;
    cout << "[0] Exit program\n" << endl;
    cout << "Enter in your option: ";
}
