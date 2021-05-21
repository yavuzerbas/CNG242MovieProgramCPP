#include "MovieList.h"

MovieList::MovieList()
{
	this->movieHead = new Movie();
	movieHead->setName("Head");
	movieHead->setNextByName(NULL);
	movieHead->setNextByRate(NULL);
	movieHead->setNextByYear(NULL);

}
