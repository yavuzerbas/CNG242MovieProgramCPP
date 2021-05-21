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
	static Movie* movieList;
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

	static void add(string name, double rate, int year);
	static bool remove(string name);
	static void update(string name, double rate);
	static void printByYear();
	static void printByName();
	static void printByRate();
	static void loadFile(string filename);
	static void saveToFileByYear(string filename);
	static void saveToFileByName(string filename);
	static void saveToFileByRate(string filename);



};

