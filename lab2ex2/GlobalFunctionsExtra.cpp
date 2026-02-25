#include "GlobalFunctionsExtra.h"

int compareByNames(Movie A, Movie B) {
	if (A.getName() == B.getName()) {
		return 0;
	}
	if (A.getName() > B.getName()) {
		return 1;
	}
	return -1;
}

int compareByReleaseYear(Movie A, Movie B) {
	if (A.getReleaseYear() == B.getReleaseYear()) {
		return 0;
	}
	if (A.getReleaseYear() > B.getReleaseYear()) {
		return 1;
	}
	return -1;
}

int compareByIMBDscore(Movie A, Movie B) {
	if (A.getIMBDscore() == B.getIMBDscore()) {
		return 0;
	}
	if (A.getIMBDscore() > B.getIMBDscore()) {
		return 1;
	}
	return -1;
}

int compareByLength(Movie A, Movie B) {
	if (A.getLength() == B.getLength()) {
		return 0;
	}
	if (A.getLength() > B.getLength()) {
		return 1;
	}
	return -1;
}

int comapreByYearsPassed(Movie A, Movie B) {
	if (A.passedYears() == B.passedYears()) {
		return 0;
	}
	if (A.passedYears() > B.passedYears()) {
		return 1;
	}
	return -1;
}