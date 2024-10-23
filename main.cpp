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
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++])
        ;
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++])
        ;
    fin1.close();

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
    cout << "Choice -->";
    cin >> userChoice;

    while (userChoice < 1 || userChoice > 4)
    {
        cout << "Error, Enter a number between 1 and 4: ";
        cin >> userChoice;
    }

    return userChoice;
}
int select_goat(list<Goat> trip)
{
    if (trip.empty())
    {
        cout << "No goats in the trip. \n";
        return -1;
    }
    int i = 1;
    cout << setw(3) << "No. " << setw(15) << "Name" << setw(5) << "Age" << setw(10) << "Color" << endl;
    for (const Goat& goat : trip)
    {
        cout << setw(3) << i++ << setw(15) << goat.get_name() << setw(5) << goat.get_age() << setw(10) << goat.get_color() << endl;
    }
}
void add_goat()
{
}
void delete_goat()
{
}
void display_trip(list<Goat> trip)
{
    int i = 1;
    cout << setw(3) << "No." << setw(15) << "Name" << setw(5) << "Age" << setw(10) << "Color" << endl;
    for (const Goat& goat : trip)
    {
        cout << setw(3) << i++ << setw(15) << goat.get_name() << setw(5) << goat.get_age() << setw(10) << goat.get_color() << endl;
    }
}