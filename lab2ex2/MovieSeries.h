#pragma once
#include "Movie.h"
class MovieSeries {
private:
	int count;
	Movie* movies[16];

public:
	void Init();
	void addMovie(Movie* movie);
	void prinInfoMovies();
	void sortMovies();
};