
#include <iostream>
#include "Movie.h"


using std::string;

int main()
{
    Movie* movie = new Movie("The Thirteenth Floor",7.3,1998);
    //Movie::add("The Thirteenth Floor2", 7.3, 1998);

    std::cout << movie->getName() <<"\n";
    //std::cout << Movie::movieList->name << "\n";

    return 0;
}
