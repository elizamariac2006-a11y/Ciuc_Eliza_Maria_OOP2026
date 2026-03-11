#include<iostream>
#include "Sort.h"
#include<initializer_list>

using namespace std;

void testConstructorString() {
	char s[100];
	strcpy_s(s, "1, 3, 7, 26, 21, 5");
	Sort sort(s);
	sort.Print();

	sort.BubbleSort();
	sort.Print();
}

void testConstructorVector() {
	int a[]{ 21, 26, 5, 8, 1 };
	Sort sort(5, a);
	sort.Print();

	sort.BubbleSort(true);
	sort.Print();
}

void testConstructorRandom() {
	Sort sort(10, 5, 26);
	sort.Print();

	sort.QuickSort(true);
	sort.Print();

	sort.QuickSort();
	sort.Print();

	printf("At position 6 we have %d\n", sort.GetElementFromIndex(6));
}

void testConstructorInitList() {
	Sort sort = { 21, 26, 5, 17, 9, 13, 27, 2 };
	sort.Print();
	sort.InsertSort(true);
	sort.Print();
}

void testConstructorVarPar() {
	Sort sort(10, 21, 26, 7, 1, 100, 4, 5, 16, 87, 5);
	sort.Print();
	sort.InsertSort();
	sort.Print();
}

int main() {
	testConstructorString();
	printf("--------------------\n");
	testConstructorVector();
	printf("--------------------\n");
	testConstructorRandom();
	printf("--------------------\n");
	testConstructorInitList();
	printf("--------------------\n");
	testConstructorVarPar();

	return 0;
}