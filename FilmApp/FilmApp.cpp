
#include <iostream>
#include "Movie.h"
#include <string>

using std::string;
using std::cout;
using std::cin;

char menu() {
    cout << "\na.Load a file\n"
        << "b.Save to a file\n"
        << "c.Add a movie\n"
        << "d.Remove a movie\n"
        << "e.Update a movie\n"
        << "f.Print by name\n"
        << "g.Print by rate\n"
        << "h.Print by year\n"
        << "x. exit: ";
    string line;
    cin >> line;
    char menuChoice = line[0];
    return menuChoice;
}

int main()
{
    //creating linked list
    Movie* head = new Movie();
    head->setName("head");
    //

    string fileName,subMenuChoice,temp,name;
    double rate;
    int year;
    char menuChoice;

    while ((menuChoice = menu()) && (menuChoice != 'x')) {
        switch (menuChoice) {
        case 'a':
            cout << "Enter the file name with the extension:";
            cin >> fileName;
            Movie::loadFile(head,fileName);
            break;
        case 'b':
            cout << "Enter the file name with the extension:";
            cin >> fileName;
            cout << "1.Save by name\n2.Save by rate\n3.Save by year:";
            cin >> subMenuChoice;
            if (subMenuChoice[0] == '1') {
                Movie::saveToFileByName(head, fileName);
            }
            else if (subMenuChoice[0] == '2') {
                Movie::saveToFileByRate(head, fileName);
            }
            else if (subMenuChoice[0] == '3') {
                Movie::saveToFileByYear(head, fileName);
            }
            else {
                cout << "Invalid input!\n";
            }
            break;
        case 'c':
            cout << "Enter the name of the movie:";
            cin.ignore();
            getline(cin,name);
            cout << "Enter the rate of the movie:";
            cin >> temp;
            try {
                rate = stod(temp);
            }
            catch (...) {
                cout << "Invalid input!\n";
                break;
            }
            cout << "Enter the year of the movie:";
            cin >> temp;
            try {
                year = stoi(temp);
            }
            catch (...) {
                cout << "Invalid input!\n";
                break;
            }
            Movie::add(head, name, rate, year);
            break;
        case 'd':
            cout << "Enter the name of the movie you want the delete: ";
            cin >> temp;
            Movie::remove(head, temp);
            break;
        case 'e':
            cout << "Enter the name of the movie you want to update: ";
            cin >> name;
            cout << "Enter the new rating of the movie: ";
            cin >> temp;
            rate = stod(temp);
            Movie::update(head, name, rate);
            break;
        case 'f':
            Movie::printByName(head);
            break;
        case 'g':
            Movie::printByRate(head);
            break;
        case 'h':
            Movie::printByYear(head);
            break;
        default:
            cout << "Invalid input!\n";
        }
    }
    return 0;
}