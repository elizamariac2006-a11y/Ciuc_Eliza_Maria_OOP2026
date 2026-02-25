#pragma once
#include<string>
using namespace std;

class Student {
private:
	string name;
	float mathGrade;
	float historyGrade;
	float englishGrade;

public:
	void setName(string name);
	string getName();
	
	void setMathGrade(float grade);
	float getMathGrade();

	void setEnglishGrade(float grade);
	float getEnglishGrade();

	void setHistoryGrade(float grade);
	float getHistoryGrade();

	float avarageGrade();
};