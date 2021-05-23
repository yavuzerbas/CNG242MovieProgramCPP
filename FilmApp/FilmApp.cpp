
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
   
    Movie::loadFile(head,"sampleInput.txt");
    Movie::printByName(head);
    cout << "\n";
    Movie::printByRate(head);
    cout << "\n";
    Movie::printByYear(head);

    Movie::saveToFileByRate(head, "sampleOutput.txt");
    return 0;
}
