#include "MovieSeries.h"
#include<iostream>
#include "GlobalFunctionsExtra.h"
using namespace std;

void MovieSeries :: Init() {
	count = 0;
}

void MovieSeries :: addMovie(Movie* movie) {
	if (count == 16) {
		printf("Sorry can't add any new movie !\n");
		return;
	}
	this->movies[count] = movie;
	count++;
}

void MovieSeries :: prinInfoMovies() {
	printf("Number of movies : %d\n", count);
	for (int i = 0; i < 16; i++) {
		cout << this->movies[i]->getName() << ", " << this->movies[i]->getReleaseYear() << ", "
			<< this->movies[i]->getIMBDscore() << " on IMBD, " << this->movies[i]->getLength() << " minutes\n";
	}
}

void MovieSeries :: sortMovies() {
	bool isSorted = false;
	while (!isSorted) {
		isSorted = true;
		for (int i = 0; i < count - 1; i++) {
			if (comapreByYearsPassed(*movies[i], *movies[i + 1]) == -1) {
				Movie* aux = movies[i];
				movies[i] = movies[i + 1];
				movies[i + 1] = aux;
				isSorted = false;
			}
		}
	}
	//prinInfoMovies();
}