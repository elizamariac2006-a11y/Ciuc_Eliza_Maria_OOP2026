#include "GlobalFunctions.h"

int compareGradeMath(Student A, Student B) {
	if (A.getMathGrade() == B.getMathGrade()) {
		return 0;
	} 
	if (A.getMathGrade() > B.getMathGrade()) {
		return 1;
	}
	return -1;
}

int compareGradeEnglish(Student A, Student B) {
	if (A.getEnglishGrade() == B.getEnglishGrade()) {
		return 0;
	}
	if (A.getEnglishGrade() > B.getEnglishGrade()) {
		return 1;
	}
	return -1;
}

int compareGradeHistory(Student A, Student B) {
	if (A.getHistoryGrade() == B.getHistoryGrade()) {
		return 0;
	}
	if (A.getHistoryGrade() > B.getHistoryGrade()) {
		return 1;
	}
	return -1;
}

int compareNames(Student A, Student B) {
	if (A.getName() == B.getName()) {
		return 0;
	}
	if (A.getName() > B.getName()) {
		return 1;
	}
	return -1;
}

int compareAvarageGrade(Student A, Student B) {
	if (A.avarageGrade() == B.avarageGrade()) {
		return 0;
	}
	if (A.avarageGrade() > B.avarageGrade()) {
		return 1;
	}
	return -1;
}