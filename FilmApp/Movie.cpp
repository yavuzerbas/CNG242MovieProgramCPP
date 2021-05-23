#include "Movie.h"
#include <iostream>
using std::cout;
Movie::Movie()
{
	this->name = "default name";
	this->rate = 0.0;
	this->year = 0;

	this->nextByName = NULL;
	this->nextByRate = NULL;
	this->nextByYear = NULL;
}

Movie::Movie(string name, double rate, int year)
{
	this->name = name;
	this->rate = rate;
	this->year = year;

	this->nextByName = NULL;
	this->nextByRate = NULL;
	this->nextByYear = NULL;
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

void Movie::add(Movie* movieList,string name, double rate, int year)
{	
	Movie* movie = new Movie(name,rate,year);
	addByName(movieList, movie);
	addByYear(movieList, movie);
	addByRate(movieList, movie);

}

bool Movie::remove(Movie* movieList, string name)
{
	if (removeByName(movieList, name) == false) {
		return false;
	}
	else {
		removeByRate(movieList, name);
		removeByYear(movieList, name);
		return true;
	}
}

void Movie::update(Movie* movieList, string name, double newRate)
{

	if (movieList == NULL || movieList->nextByRate == NULL) {
		cout << "List is empty.\n";
		return;
	}

	Movie* traversal = movieList;
	while (traversal->nextByRate != NULL) {
		if (name.compare(traversal->nextByRate->name) == 0) {
			Movie* temp = traversal->nextByRate;
			traversal->nextByRate = traversal->nextByRate->nextByRate;
			temp->rate = newRate;
			temp->nextByRate = NULL;
			addByRate(movieList, temp);
			//cout << "Movie rate is updated.\n";
			return;
		}
		traversal = traversal->nextByRate;
	}
	cout << "The movie\"" << name << "\" doesn't exist in the system.";
	return;
}


void Movie::printByYear(Movie* head)
{
	if ((head == NULL) || (head->nextByYear == NULL)) { //checking if list is empty
		cout << "Empty list!\n";
		return;
	}
	cout << "\n";

	Movie* traversal = head;
	while (traversal->nextByYear != NULL) {
		traversal = traversal->nextByYear;
		printMovie(traversal);
	}
}

void Movie::printByName(Movie* head)
{
	if ((head == NULL) || (head->nextByName == NULL)) { //checking if list is empty
		cout << "Empty list!\n";
		return;
	}
	cout << "\n";

	Movie* traversal = head;
	while (traversal->nextByName != NULL) {
		traversal = traversal->nextByName;
		printMovie(traversal);
	}
}

void Movie::printByRate(Movie* head)
{
	if ((head == NULL) || (head->nextByRate == NULL)) { //checking if list is empty
		cout << "Empty list!\n";
		return;
	}
	cout << "\n";

	Movie* traversal = head;
	while (traversal->nextByRate != NULL) {
		traversal = traversal->nextByRate;
		printMovie(traversal);
	}
}

void Movie::loadFile(Movie* movieList,string fileName)
{
	Movie* inCaseError = movieList;
	ifstream myifstream(fileName);
	string word,line,name;
	double rate = 0.0;
	int year = 0,counter = 0;
	if (myifstream.fail()) {
		cout << "File couldn't be opened\n";
		myifstream.close();
		return;
	}
	else {
		while (!myifstream.eof()) {
			counter++;
			line = "";//clearing line
			myifstream >> word;
			if (word[0] == '"' && word[word.length()-1] != '"') {//reading a movie name having multiple words
				line = word;
				while (!myifstream.eof()) {
					myifstream >> word;
					line += " " + word;
					if (word[word.length() - 1] == '"') {
						name = line.substr(1, (line.length() - 2));
						break;
					}
				}
			}
			else if (word[0] == '"' && word[word.length() - 1] == '"') {// reading a movie name having single word
				name = word.substr(1,word.length() - 2);
			}
			else {
				if (counter % 3 == 1) {
					movieList = inCaseError;
					movieList->nextByName = NULL;
					movieList->nextByRate = NULL;
					movieList->nextByYear = NULL;
					cout << "corrupted file\n";
					myifstream.close();
					return;
				}
				else if (counter % 3 == 2) {
					rate = stod(word);
				}
				else {
					year = stoi(word);

					add(movieList, name, rate, year);
				}
			}
		}
	}
	myifstream.close();
}

void Movie::saveToFileByName(Movie* movieList,string fileName)
{
	if ((movieList == NULL) || (movieList->nextByName == NULL)) { //checking if list is empty
		cout << "Empty list!\n";
		return;
	}
	ofstream myofstream(fileName);
	if (myofstream.fail()) {
		cout << "File couldn't be opened\n";
		myofstream.close();
		return;
	}
	Movie* traversal = movieList;
	while (traversal->nextByName != NULL) {
		traversal = traversal->nextByName;
		myofstream << "\"" << traversal->getName() << "\" " << traversal->getRate() << " " << traversal->getYear() << "\n";
	}
	myofstream.close();
}

void Movie::saveToFileByYear(Movie* movieList, string fileName)
{
	if ((movieList == NULL) || (movieList->nextByYear == NULL)) { //checking if list is empty
		cout << "Empty list!\n";
		return;
	}
	ofstream myofstream(fileName);
	if (myofstream.fail()) {
		cout << "File couldn't be opened\n";
		myofstream.close();
		return;
	}
	Movie* traversal = movieList;
	while (traversal->nextByYear != NULL) {
		traversal = traversal->nextByYear;
		myofstream << "\"" << traversal->getName() << "\" " << traversal->getRate() << " " << traversal->getYear() << "\n";
	}
	myofstream.close();
}

void Movie::saveToFileByRate(Movie* movieList, string fileName)
{
	if ((movieList == NULL) || (movieList->nextByRate == NULL)) { //checking if list is empty
		cout << "Empty list!\n";
		return;
	}
	ofstream myofstream(fileName);
	if (myofstream.fail()) {
		cout << "File couldn't be opened\n";
		myofstream.close();
		return;
	}
	Movie* traversal = movieList;
	while (traversal->nextByRate != NULL) {
		traversal = traversal->nextByRate;
		myofstream << "\"" << traversal->getName() << "\" " << traversal->getRate() << " " << traversal->getYear() << "\n";
	}
	myofstream.close();
}

void Movie::addByName(Movie* movieList, Movie* newMovie) {

	Movie* traversal = movieList;
	while (traversal->nextByName != NULL) {
		if (newMovie->name.compare(traversal->getNextByName()->getName()) == 1) {
			traversal = traversal->nextByName;
		}
		else {
			Movie* temp = traversal->getNextByName();
			traversal->nextByName = newMovie;
			newMovie->nextByName = temp;
			return;
		}
	}
	traversal->setNextByName(newMovie);
}

void Movie::addByRate(Movie* movieList, Movie* newMovie)
{
	Movie* traversal = movieList;
	while (traversal->nextByRate != NULL) {
		if (newMovie->rate > traversal->getNextByRate()->getRate()) {
			traversal = traversal->nextByRate;
		}
		else {
			Movie* temp = traversal->getNextByRate();
			traversal->nextByRate = newMovie;
			newMovie->nextByRate = temp;
			return;
		}
	}
	traversal->setNextByRate(newMovie);
}

void Movie::addByYear(Movie* movieList, Movie* newMovie)
{
	Movie* traversal = movieList;
	while (traversal->nextByYear != NULL) {
		if (newMovie->year > traversal->getNextByYear()->getYear() ) {
			traversal = traversal->nextByYear;
		}
		else {
			Movie* temp = traversal->getNextByYear();
			traversal->nextByYear = newMovie;
			newMovie->nextByYear = temp;
			return;
		}
	}
	traversal->setNextByYear(newMovie);
}

void Movie::printMovie(Movie* movie)
{
	if (movie == NULL) {
		cout << "Movie tried to be printed is NULL!\n";
		return;
	}
	cout << movie->name << " " << movie->rate << " " << movie->year << "\n";
}

bool Movie::removeByName(Movie* movieList, string name)
{
	if (movieList == NULL || movieList->nextByName == NULL) {
		return false;
	}

	Movie* traversal = movieList;
	while (traversal->nextByName != NULL) {
		if (name.compare(traversal->nextByName->name) == 0) {
			traversal->nextByName = traversal->nextByName->nextByName;
			return true;
		}
		traversal = traversal->nextByName;
	}
	return false;
}

void Movie::removeByRate(Movie* movieList, string name)
{
	Movie* traversal = movieList;
	
	while (traversal->nextByRate != NULL) {
		if (name.compare(traversal->nextByRate->name) == 0) {
			traversal->nextByRate = traversal->nextByRate->nextByRate;
			return;
		}
		traversal = traversal->nextByRate;
	}
}

void Movie::removeByYear(Movie* movieList, string name)
{
	Movie* traversal = movieList;

	while (traversal->nextByYear != NULL) {
		if (name.compare(traversal->nextByYear->name) == 0) {
			traversal->nextByYear = traversal->nextByYear->nextByYear;
			return;
		}
		traversal = traversal->nextByYear;
	}
}
