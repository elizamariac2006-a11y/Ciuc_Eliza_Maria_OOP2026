#include "Movie.h"

void Movie :: setName(string name) {
	this->name = name;
}
string Movie :: getName() {
	return this->name;
}

void Movie :: setReleaseYear(int releaseYear) {
	this->releaseYear = releaseYear;
}
int Movie :: getReleaseYear() {
	return this->releaseYear;
}

void Movie :: setIMBDscore(float IMBDscore) {
	this->IMBDscore = IMBDscore;
}
float Movie :: getIMBDscore() {
	return this->IMBDscore;
}

void Movie :: setLength(int length) {
	this->length = length;
}
int Movie :: getLength() {
	return this->length;
}

int Movie :: passedYears() {
	return 2026 - this->releaseYear;
}