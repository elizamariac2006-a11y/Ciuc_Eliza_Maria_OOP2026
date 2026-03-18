#include<iostream>
#include "Number.h"
using namespace std;

void testLab5() {
	Number n1("D", 16); //13 baza 10
	n1.Print();
	n1.SwitchBase(5);
	n1.Print();

	printf("------------------------------\n");

	printf("Testare functii: \n");
	printf("%d\n", n1.ToBase10());
	const char* s = Number::FromBase10ToNewBase(31, 16);
	printf("%s\n", s);

	printf("------------------------------\n");

	Number n2("12", 3); //5 baza 10
	Number n3("0", 2);

	n3 = n1 + n2;
	n3.Print();

	n3 = n1 - n2;
	n3.Print();

	n3 = n1;
	n3.Print();

	Number n4 = n3;
	n4.Print();

	Number n5 = n3 + n4; //13 + 13
	n5.Print();

	printf("%c\n", n3[0]);
	printf("%c\n", n3[7]);

	n1 = n1 + 2;
	n1.Print(); //din 13 baza 5 in 15 baza 5
	n1 = n1 + 2;
	n1.Print(); //din 15 baza 5 in 17 baza 5

	n2 = n1;
	n1--;
	n1.Print();
	n2.Print();
	--n2;
	n2.Print();

	Number n6 = 1234;
	n6.Print();
	n6.SwitchBase(2);
	n6.Print();
	n6 = 26;
	n6.Print();

	printf("------------------------------\n");

	Number n7 = "21";
	n7.Print();
	n7.SwitchBase(4);
	n7.Print();
	n7 = "26";
	n7.Print();

	n7 += n6;
	n7.Print();
}

void mainLab5DePeSite() {
	Number n1("10110010", 2);
	Number n2("734", 8);
	Number n3("FF", 16);

	printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());
	for (int tr = 0;tr < n1.GetDigitsCount();tr++)
	{
		printf("n1[%d]=%c\n", tr, n1[tr]);
	}
	n1.Print();
	n2.Print();
	n1 = (n2 + n3 - n1) + n1; // after this n1 will be in base 16
	n1.SwitchBase(2);
	n1.Print();

	if (n1 > n2) printf("n1 is bigger than n2\n"); else printf("n2 is bigger than n1\n");

	Number n4 = 12345; // n4 will be in base 10
	n1 = 255; // n1 will be 11111111 (value 255 from base 10 in base 2)
	n4 += n1;
	n4.Print();

	n4 = "13579"; // n4 mentains its base (10) and will be 13579
	n4.Print();
	--n4; // the first digit from n4 will be remove ==> n4 becomes 3579
	n4.Print();
	n4--; // the last digit from n4 will be remove ==> n4 becomes 357
	n4.Print();
}

int main() {
	//testLab5();
	mainLab5DePeSite();
	return 0;
}