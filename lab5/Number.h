#pragma once
class Number {
private: 
	char* value;
	int len;
	int base;
	// add data members
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(const Number& number);
	Number(Number&& number);
	Number(int value);
	Number(const char* value);
	~Number();

	// add operators and copy/move constructor
	Number& operator=(Number&& otherNumber);
	Number& operator=(const Number& otherNumber);
	Number& operator=(const int value);
	Number& operator=(const char* value);
	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);
	friend Number operator+(const Number& number, const int val);
	friend Number operator+(const int val, const Number& number);
	Number& operator+=(const Number& otherNumber);
	Number operator--(int); //n--
	Number& operator--(); //--n

	bool operator>(const Number& otherNumber);
	bool operator<(const Number& otherNumber);
	bool operator>=(const Number& otherNumber);
	bool operator<=(const Number& otherNumber);
	bool operator==(const Number& otherNumber);
	bool operator!=(const Number& otherNumber);
	char operator[](const int position);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	int ToBase10() const;
	char* getValue();
	static const char* FromBase10ToNewBase(int number, int newBase);
};
