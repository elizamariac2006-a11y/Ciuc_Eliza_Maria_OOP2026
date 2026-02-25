#include "Student.h"

void Student :: setName(string name) {
	this->name = name;
}
string Student :: getName() {
	return this->name;
}

void Student :: setMathGrade(float grade) {
	this->mathGrade = grade;
}
float Student :: getMathGrade() {
	return this->mathGrade;
}

void Student :: setEnglishGrade(float grade) {
	this->englishGrade = grade;
}
float Student :: getEnglishGrade() {
	return this->englishGrade;
}

void Student :: setHistoryGrade(float grade) {
	this->historyGrade = grade;
}
float Student :: getHistoryGrade() {
	return this->historyGrade;
}

float Student :: avarageGrade() {
	float avarage = (this->mathGrade + this->englishGrade + this->historyGrade);
	avarage = avarage / 3.0f;
	return avarage;
}

