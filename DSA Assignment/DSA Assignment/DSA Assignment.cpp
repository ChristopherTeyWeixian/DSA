#include <iostream>
#include<string>
#include "BusStop.h"
using namespace std;
void displayMenu();

int main()
{
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
    
    List bus74;
    int option = 1;
    while (option != 0) 
    {
        displayMenu();
        cin >> option;
        if (option == 1) 
        {
            busstop.print();
        }
    }
    
        

}
void displayMenu() 
{
    cout << "[1] Display all BusStop"<<endl;
    cout << "[0] Exit program" << endl;;
    cout << "Enter in your option";
}
