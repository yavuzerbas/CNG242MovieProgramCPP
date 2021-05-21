#include "Movie.h"

Movie* movieList = new Movie();
movieList

Movie::Movie()
{
	this->name = "Turkiye Simulasyonu";
	this->rate = 0.0;
	this->year = 2002;
}

Movie::Movie(string name, double rate, int year)
{
	this->name = name;
	this->rate = rate;
	this->year = year;
}

string Movie::getName()
{
	return this->name;
}

double Movie::getRate()
{
	return this->rate;
}

int Movie::getYear()
{
	return this->year;
}

Movie* Movie::getNextByName()
{
	return this->nextByName;
}

Movie* Movie::getNextByRate()
{
	return this->nextByRate;
}

Movie* Movie::getNextByYear()
{
	return this->nextByYear;
}

void Movie::setName(string name)
{
	this->name = name;
}

void Movie::setRate(double rate)
{
	this->rate = rate;
}

void Movie::setYear(int year)
{
	this->year = year;
}

void Movie::setNextByName(Movie* nextByName)
{
	this->nextByName = nextByName;
}

void Movie::setNextByRate(Movie* nextByRate)
{
	this->nextByRate = nextByRate;
}

void Movie::setNextByYear(Movie* nextByYear)
{
	this->nextByYear = nextByYear;
}

void Movie::add(string name, double rate, int year)
{
	Movie* tempMovie = new Movie(name, rate, year);

	/*
	if (movieList == NULL) {
	
		movieList = tempMovie;
		
		movieList->nextByName = NULL;
		movieList->nextByName = tempMovie;
	
	}
	else {
		
		movieList->nextByName = tempMovie;
		movieList = movieList->nextByName;
		movieList->nextByName = NULL;
	}
	*/
	
}


