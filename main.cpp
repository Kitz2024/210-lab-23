// Kit Pollinger
//  210 - Lab -23 | Fork
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string[], string[]);
void display_trip(list<Goat> trip);
int main_menu();

int main()
{
    int userChoice = main_menu();

    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("C:/210-Coding/projects/210-lab-23-starter/names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++])
        ;
    fin.close();
    ifstream fin1("C:/210-Coding/projects/210-lab-23-starter/colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++])
        ;
    fin1.close();

    list<Goat> trip;
    while (userChoice != 4)
    {
        switch (userChoice)
        {
        case 1:
            add_goat(trip, names, colors);
            break;
        case 2:
            delete_goat(trip);
            break;
        case 3:
            display_trip(trip);
            break;
        }
        cin.ignore();
        userChoice = main_menu();
    }

    return 0;
}

int main_menu()
{
    int userChoice;
    cout << "*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    cout << "[4] Quit\n";
    cout << "Choice --> ";
    cin >> userChoice;

    while (userChoice < 1 || userChoice > 4)
    {
        cout << "Error, Enter a number between 1 and 4: ";
        cin >> userChoice;
    }

    return userChoice;
}
void add_goat(list<Goat> &trip, string names[], string colors[])
{
    string name = names[rand() % SZ_NAMES];
    string color = colors[rand() % SZ_COLORS];
    int age = rand() % (MAX_AGE + 1);
    Goat newGoat(name, age, color);
    trip.push_back(newGoat);
    cout << name << " (" << age << ", " << color << ") has been added to the trip!\n";
}
void delete_goat(list<Goat> &trip)
{
     int index = select_goat(trip);
    if (index != -1) {
        list<Goat>::iterator it = trip.begin();
        advance(it, index - 1);
        trip.erase(it);
        cout << "Goat deleted successfully!\n";
    } else {
        cout << "No goat selected or trip is empty.\n";
    }
}

int select_goat(list<Goat> trip)
{
    if (trip.empty())
    {
        cout << "No goats in the trip. \n";
        return -1;
    }
    cout << "\nSelect a goat to delete (enter the corresponding number):\n";
    int i = 1;
    for (const Goat& goat : trip)
    {
        cout << "[" << i++ << "] " << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ")\n";
    }
    int choice;
    cin >> choice;

    while (choice < 1 || choice > trip.size())
    {
        cout << "Error, Enter a number between 1 and 4: ";
    }
}

void display_trip(list<Goat> trip)
{
    if (trip.empty())
    {
        cout << "No goats in the trip. \n";
        return;
    }
    int i = 1;
    for (const Goat& goat : trip)
    {

        cout << setw(3) <<"[" << i++ <<"]" << setw(0) << goat.get_name() << setw(5) << "(" << goat.get_age() << "," << setw(8) << goat.get_color() << ")" << endl;
    }
}
