#include<iostream>
#include "Student.h"
#include "GlobalFunctions.h"
#include<stdlib.h>
#include "MovieSeries.h"
#include "GlobalFunctionsExtra.h"

using namespace std;

void printDataAboutStudent(Student A) {
	cout << "Stuent's name is " << A.getName() << "\n";
	printf("Stuent's math garde is %f\n", A.getMathGrade());
	printf("Stuent's english grade is %f\n", A.getEnglishGrade());
	printf("Stuent's history grade is %f\n", A.getHistoryGrade());
	printf("Stuent's avarage grade is %f\n", A.avarageGrade());

	printf("\n");
}

void sortByMathGrade(Student students[5]) {
	bool isSorted = false;
	while (!isSorted) {
		isSorted = true;
		for (int i = 0; i < 4; i++) {
			if (compareGradeMath(students[i], students[i + 1]) == 1) {
				Student aux = students[i];
				students[i] = students[i + 1];
				students[i + 1] = aux;
				isSorted = false;
			}
		}
	}

	printf("Students oredered by math grade : \n");
	for (int i = 0; i < 5; i++) {
		cout << students[i].getName() << " " << students[i].getMathGrade() << "\n";
	}
}

void sortByEnglishGrade(Student students[5]) {
	bool isSorted = false;
	while (!isSorted) {
		isSorted = true;
		for (int i = 0; i < 4; i++) {
			if (compareGradeEnglish(students[i], students[i + 1]) == 1) {
				Student aux = students[i];
				students[i] = students[i + 1];
				students[i + 1] = aux;
				isSorted = false;
			}
		}
	}

	printf("Students oredered by english grade : \n");
	for (int i = 0; i < 5; i++) {
		cout << students[i].getName() << " " << students[i].getEnglishGrade() << "\n";
	}
}

void sortByHistoryGrade(Student students[5]) {
	bool isSorted = false;
	while (!isSorted) {
		isSorted = true;
		for (int i = 0; i < 4; i++) {
			if (compareGradeHistory(students[i], students[i + 1]) == 1) {
				Student aux = students[i];
				students[i] = students[i + 1];
				students[i + 1] = aux;
				isSorted = false;
			}
		}
	}

	printf("Students oredered by history grade : \n");
	for (int i = 0; i < 5; i++) {
		cout << students[i].getName() << " " << students[i].getHistoryGrade() << "\n";
	}
}

void sortByAvarageScore(Student students[5]) {
	bool isSorted = false;
	while (!isSorted) {
		isSorted = true;
		for (int i = 0; i < 4; i++) {
			if (compareAvarageGrade(students[i], students[i + 1]) == 1) {
				Student aux = students[i];
				students[i] = students[i + 1];
				students[i + 1] = aux;
				isSorted = false;
			}
		}
	}

	printf("Students oredered by the avarage score : \n");
	for (int i = 0; i < 5; i++) {
		cout << students[i].getName() << " " << students[i].avarageGrade() << "\n";
	}
}

void testStudentClass() {
	Student A;
	A.setName("Ciuc Eliza-Maria");
	A.setMathGrade(8);
	A.setHistoryGrade(7);
	A.setEnglishGrade(8.5f);

	printDataAboutStudent(A);

	Student students[5];
	students[0].setName("Eliza"); students[1].setName("Tiberiu"); students[2].setName("Irina"); 
	students[3].setName("Denis"); students[4].setName("Gigi");
	
	students[0].setMathGrade(7); students[1].setMathGrade(4.5f); students[2].setMathGrade(6);
	students[3].setMathGrade(6.2f); students[4].setMathGrade(7.9f);

	students[0].setEnglishGrade(5.6f); students[1].setEnglishGrade(9.5f); students[2].setEnglishGrade(6.3f);
	students[3].setEnglishGrade(8.7f); students[4].setEnglishGrade(7);

	students[0].setHistoryGrade(8.9f); students[1].setHistoryGrade(7.3f); students[2].setHistoryGrade(9.2f);
	students[3].setHistoryGrade(7.5f); students[4].setHistoryGrade(8.1f);

	printDataAboutStudent(students[0]);
	printDataAboutStudent(students[1]);
	printDataAboutStudent(students[2]);
	printDataAboutStudent(students[3]);
	printDataAboutStudent(students[4]);

	sortByMathGrade(students);
	sortByEnglishGrade(students);
	sortByHistoryGrade(students);
	sortByAvarageScore(students);
}

void testMovieSeriesClass() {
	Movie ep5;
	ep5.setName("Star Wars: Episode V - The Empire Strikes Back");
	ep5.setIMBDscore(8.7);
	ep5.setReleaseYear(1980);
	ep5.setLength(124);

	Movie ep4;
	ep4.setName("Star Wars: Episode IV - A New Hope");
	ep4.setIMBDscore(8.6);
	ep4.setReleaseYear(1977);
	ep4.setLength(121);

	Movie ep6;
	ep6.setName("Star Wars: Episode VI - Return of the Jedi");
	ep6.setIMBDscore(8.3);
	ep6.setReleaseYear(1983);
	ep6.setLength(131);

	printf(
R"(
ep4, ep5 comparisons:
name        : %d
year        : %d
score       : %d
length      : %d
passed years: %d
)",
compareByNames(ep4, ep5),
compareByReleaseYear(ep4, ep5),
compareByIMBDscore(ep4, ep5),
compareByLength(ep4, ep5),
comapreByYearsPassed(ep4, ep5));

	MovieSeries series;
	series.Init();
	series.addMovie(&ep5);
	series.addMovie(&ep4);
	series.addMovie(&ep6);

	series.sortMovies();
	series.prinInfoMovies();
}

int main() {
	//testStudentClass();
	testMovieSeriesClass();
	return 0;
}