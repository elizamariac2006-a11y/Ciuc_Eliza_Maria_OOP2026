#pragma once
#include<string>
using namespace std;

class Movie {
private :
	string name;
	int releaseYear;
	float IMBDscore;
	int length;

public:
	void setName(string name);
	string getName();

	void setReleaseYear(int year);
	int getReleaseYear();

	void setIMBDscore(float IMBDscore);
	float getIMBDscore();

	void setLength(int length);
	int getLength();
	
	int passedYears();
};
