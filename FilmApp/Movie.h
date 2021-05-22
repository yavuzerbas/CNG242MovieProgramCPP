#pragma once

#include <string>
using std::string;

class Movie
{
private:
	string name;
	double rate;
	int year;
	Movie* nextByName;
	Movie* nextByRate;
	Movie* nextByYear;

public:
	//constructors
	Movie();
	Movie(string, double, int);
	
	//getters
	string getName();
	double getRate();
	int getYear();
	Movie* getNextByName();
	Movie* getNextByRate();
	Movie* getNextByYear();

	//setters
	void setName(string);
	void setRate(double);
	void setYear(int);
	void setNextByName(Movie*);
	void setNextByRate(Movie*);
	void setNextByYear(Movie*);

	//required functionalities

	static void add(Movie*, string, double , int); //header,name,rate,year
	static bool remove(Movie*, string);
	static void update(Movie*, string , double);
	static void printByYear(Movie*);
	static void printByName(Movie*);
	static void printByRate(Movie*);
	static void loadFile(string);
	static void saveToFileByYear(string);
	static void saveToFileByName(string);
	static void saveToFileByRate(string);

	//following 3 methods will be used in add method

	static void addByName(Movie*, Movie*); //header,new movie
	static void addByRate(Movie*, Movie*); //header,new movie
	static void addByYear(Movie*, Movie*); //header,new movie

	//following method used in print methods
	static void printMovie(Movie*); 

	//following methods will be used in remove method
	static bool removeByName(Movie*, string);
	static void removeByRate(Movie*, string);
	static void removeByYear(Movie*, string);

};

