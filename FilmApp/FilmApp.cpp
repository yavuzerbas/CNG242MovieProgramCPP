
#include <iostream>
#include "Movie.h"
#include <string>

using std::string;
using std::cout;
using std::cin;

int main()
{
    //creating linked list
    Movie* head = new Movie();
    head->setName("head");
    //

    string fileName,subMenuChoice,temp,name;
    double rate;
    int year;

    while (char menuChoice = menu() != 'x') {
        switch (menuChoice) {
        case '1':
            cout << "Enter the file name with the extension:";
            cin >> fileName;
            Movie::loadFile(head,fileName);
            break;
        case '2':
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
        case '3':
            cout << "Enter the name of the movie:";
            cin >> name;
            cout << "Enter the rate of the movie:";
            cin >> temp;
            rate = stod(temp);
            cout << "Enter the year of the movie:";
            cin >> temp;
            year = stoi(temp);
            Movie::add(head, name, rate, year);
            break;
        case '4':
            cout << "Enter the name of the movie you want the delete: ";
            cin >> temp;
            Movie::remove(head, temp);
            break;
        case '5':
            cout << "Enter the name of the movie you want to update: ";
            cin >> name;
            cout << "Enter the new rating of the movie: ";
            cin >> temp;
            rate = stod(temp);
            Movie::update(head, name, rate);
            break;
        case '6':
            Movie::printByName(head);
        case '7':
            Movie::printByRate(head);
        case '8':
            Movie::printByYear(head);
            break;
        default:
            cout << "Invalid input!\n";
        }
    }
    /*
    Movie::loadFile(head,"sampleInput.txt");
    Movie::printByName(head);
    cout << "\n";
    Movie::printByRate(head);
    cout << "\n";
    Movie::printByYear(head);


    Movie::saveToFileByRate(head, "sampleOutput.txt");
    */
    return 0;
}

char menu() {
    cout << "1.Load a file\n"
        << "2.Save to a file\n"
        << "3.Add a movie\n"
        << "4.Remove a movie\n"
        << "5.Update a movie\n"
        << "6.Print by name\n"
        << "7.Print by rate\n"
        << "8.Print by year\n"
        << "x. exit: ";
    string line;
    cin >> line;
    char menuChoice = line[0];
    return menuChoice;
}
