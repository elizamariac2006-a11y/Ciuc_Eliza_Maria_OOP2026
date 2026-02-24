#include<iostream>
#include "NumberList.h"

using namespace std;

void testNumberListClass() {
	NumberList number1;
	number1.Init();
	number1.Print();
	number1.Add(26); number1.Add(21); number1.Add(27); number1.Add(2);
	number1.Print();
	number1.Sort();
	number1.Print();

	if (number1.Add(5)) {
		printf("Number 5 added succesfully!\n");
	}
	else {
		printf("Couldn't add number 5.. vector already full!\n");
	}

	number1.Add(26); number1.Add(4); number1.Add(9); number1.Add(11);
	number1.Print();

	if (number1.Add(3)) {
		printf("Number 3 added succesfully!\n");
	}
	else {
		printf("Couldn't add number 3.. vector already full!\n");
	}

	if (number1.Add(19)) {
		printf("Number 19 added succesfully!\n");
	}
	else {
		printf("Couldn't add number 19.. vector already full!\n");
	}

	number1.Print();
	number1.Sort();
	number1.Print();
}

int main() {
	testNumberListClass();
	return 0;
}