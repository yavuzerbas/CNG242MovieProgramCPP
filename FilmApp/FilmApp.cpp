
#include <iostream>
#include "Movie.h"
#include <string>

using std::string;
using std::cout;
using std::cin;

int main()
{
    Movie* head = new Movie();
    head->setName("head");
    /*
    Movie::add(head,"LOTR", 8.8, 2001);
    Movie::add(head, "Matrix", 8.7, 1999);
    Movie::add(head, "Interstellar", 8.6, 2014);
    
    Movie::printByName(head);
    cout << "\n";
    Movie::printByYear(head);
    cout << "\n";
    Movie::printByRate(head);
    
    cout << "\nafter update\n";
    Movie::update(head, "LOTR", 8.5);
    Movie::printByRate(head);
    cout << "\n\n";
    */
    Movie::loadFile(head,"yavuz.txt");
    Movie::printByName(head);
    cout << "\n";
    Movie::printByRate(head);
    cout << "\n";
    Movie::printByYear(head);

    return 0;
}
