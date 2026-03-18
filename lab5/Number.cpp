#include "Number.h"
#include<iostream>
using namespace std;

Number::Number(const char* value, int base) {
	int len = strlen(value);
	this->value = new char[len + 2];

	for (int i = 0; i < len; i++) {
		this->value[i] = value[i];
	}
	this->value[len] = '\0';

	this->base = base;
	this->len = len;
}

Number::Number(const Number& number) {
	this->len = number.len;
	this->base = number.base;

	this->value = new char[len + 2];
	for (int i = 0; i < len; i++) {
		this->value[i] = number.value[i];
	}
	this->value[len] = '\0';
}

Number::Number(Number&& number) {
	this->value = number.value;
	this->len = number.len;
	this->base = number.base;

	number.value = nullptr;
	number.len = number.base = 0;
}

Number::Number(int value) {
	this->base = 10;
	const char* s = Number::FromBase10ToNewBase(value, 10);
	this->len = strlen(s);
	this->value = new char[len + 2];
	for (int i = 0; i < len; i++) {
		this->value[i] = s[i];
	}
	this->value[len] = '\0';
	delete[] s;
}

Number::Number(const char* value) {
	this->base = 10;
	this->len = strlen(value);
	this->value = new char[len + 2];
	for (int i = 0; i < len; i++) {
		this->value[i] = value[i];
	}
	this->value[len] = '\0';
}

Number::~Number() {
	delete[] value;
}

void Number::SwitchBase(int newBase) {
	//din baza actuala in baza 10
	int p, number, cif;

	p = 1;
	number = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (value[i] >= '0' && value[i] <= '9') {
			cif = (int)(value[i] - '0');
		} else {
			if (value[i] >= 'A' && value[i] <= 'F') {
				cif = (int)(value[i] - 'A') + 10;
			} else {
				cif = (int)(value[i] - 'a') + 10;
			}
			
		}
		number = number + p * cif;
		p = p * base;
	}

	if (number == 0) {
		delete[] value;
		value = new char[3];
		value[0] = '0';
		value[1] = '\0';
		this->len = 1;
		this->base = newBase;
		return;
	}

	//printf("%d", number);

	//din baza 10 in baza newBase
	char a[100000];
	int index, newLen;

	newLen = 0;
	while (number > 0) {
		int modulo = number % newBase;
		if (modulo <= 9) {
			a[newLen] = (char)(modulo + '0');
		}
		else {
			switch (modulo) {
			case 10: {
				a[newLen] = 'A';
				break;
			} case 11: {
				a[newLen] = 'B';
				break;
			} case 12: {
				a[newLen] = 'C';
				break;
			}  case 13: {
				a[newLen] = 'D';
				break;
			} case 14: {
				a[newLen] = 'E';
				break;
			} case 15: {
				a[newLen] = 'F';
				break;
			}
			}
		}
		//printf("%c, %d\n", a[newLen], modulo);

		number = number / newBase;
		newLen++;
	}

	delete[] value;
	value = new char[newLen + 2];
	index = 0;
	for (int i = newLen - 1; i >= 0; i--) {
		value[index] = a[i];
		index++;
	}
	value[index] = '\0';
	this->len = newLen;
	this->base = newBase;
}

int Number::GetBase() {
	return this->base;
}

int Number::GetDigitsCount() {
	return this->len;
}

char* Number::getValue() {
	return this->value;
}

void Number::Print() {
	printf("The number is : ");
	printf("%s", value);
	printf(", written in base %d.\n", base);
	
}

int Number::ToBase10() const {
	int number, p, cif;
	p = 1;
	number = 0;
	for (int i = len - 1; i >= 0; i--) {
		cif = 0;
		if (value[i] >= '0' && value[i] <= '9') {
			cif = (int)(value[i] - '0');
		} else if (value[i] >= 'A' && value[i] <= 'F') {
			cif = (int)(value[i] - 'A') + 10;
		} else {
			cif = (int)(value[i] - 'a') + 10;
		}
		//printf("%d", cif);
		number = number + p * cif;
		p = p * base;
	}

	return number;
}

const char* Number::FromBase10ToNewBase(int number, int newBase) {
	char* a = new char[10000];
	int index = 0;

	if (number == 0) {
		a[0] = '0';
		a[1] = '\0';
		return a;
	}

	while (number > 0) {
		int modulo = number % newBase;
		if (modulo <= 9) {
			a[index] = (char)(modulo + '0');
		} else {
			switch (modulo) {
			case 10: {
				a[index] = 'A';
				break;
			} case 11: {
				a[index] = 'B';
				break;
			} case 12: {
				a[index] = 'C';
				break;
			}  case 13: {
				a[index] = 'D';
				break;
			} case 14: {
				a[index] = 'E';
				break;
			} case 15: {
				a[index] = 'F';
				break;
			}
			}
		}
		index++;
		number = number / newBase;
	}
	a[index] = '\0';

	int i, j;
	i = 0; j = index - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}

	return a;
}

Number& Number::operator=(Number&& otherNumber) {
	if (this == &otherNumber) {
		return *this;
	}

	delete[] value;
	this->len = otherNumber.len;
	this->base = otherNumber.base;
	this->value = otherNumber.value;
	
	otherNumber.len = 0;
	otherNumber.base = 0;
	otherNumber.value = nullptr;

	return *this;
}

Number& Number::operator=(const Number& otherNumber) {
	if (this == &otherNumber) {
		return *this;
	}
	delete[] value;
	this->base = otherNumber.base;
	this->len = otherNumber.len;
	this->value = new char[len + 2];
	for (int i = 0; i < len; i++) {
		this->value[i] = otherNumber.value[i];
	}
	this->value[len] = '\0';
	
	return *this;
}

Number& Number::operator=(const int value) {
	const char* s = FromBase10ToNewBase(value, this->base);
	this->len = strlen(s);
	delete[] this->value;
	this->value = new char[this->len + 2];
	for (int i = 0; i < len; i++) {
		this->value[i] = s[i];
	}
	this->value[this->len] = '\0';
	delete[] s;
	return *this;
}

Number& Number::operator=(const char* value) {
	Number newNumber(value);
	int n = newNumber.ToBase10();
	const char* s = FromBase10ToNewBase(n, this->base);

	this->len = strlen(s);
	delete[] this->value;
	this->value = new char[this->len + 2];
	for (int i = 0; i < len; i++) {
		this->value[i] = s[i];
	}
	this->value[this->len] = '\0';
	delete[] s;
	return *this;
}

Number Number::operator--(int) {
	Number oldNumber(*this);

	if (len > 0) {
		this->len = this->len - 1;
		this->value[len] = '\0';
	}
	return oldNumber;
}

Number& Number::operator--() {
	if (len > 0) {
		for (int i = 0; i < len; i++) {
			this->value[i] = this->value[i + 1];
		}
		this->len = this->len - 1;
	}
	return *this;
}

Number operator+(const Number& n1, const Number& n2) {
	int baseResult = max(n1.base, n2.base);
	int numberResut = n1.ToBase10() + n2.ToBase10();
	
	const char* valueResult = Number::FromBase10ToNewBase(numberResut, baseResult);
	Number result(valueResult, baseResult);
	delete[] valueResult;

	return result;
}

Number operator+(const Number& number, const int val) {
	int numberResult = number.ToBase10() + val;
	const char* s = Number::FromBase10ToNewBase(numberResult, number.base);
	Number result(s, number.base);
	delete[] s;
	return result;
}

Number operator+(const int val, const Number& number) {
	return number + val;
}

Number& Number::operator+=(const Number& otherNumber) {
	*this = *this + otherNumber;
	return *this;
}

Number operator-(const Number& n1, const Number& n2) {
	int baseResult = max(n1.base, n2.base);
	int numberResut = n1.ToBase10() - n2.ToBase10();
	if (numberResut < 0) {
		numberResut = 0;
	}

	const char* valueResult = Number::FromBase10ToNewBase(numberResut, baseResult);
	Number result(valueResult, baseResult);
	delete[] valueResult;

	return result;
}

bool Number::operator>(const Number& otherNumber) {
	if (ToBase10() > otherNumber.ToBase10()) {
		return true;
	}
	return false;
}

bool Number::operator<(const Number& otherNumber) {
	if (ToBase10() < otherNumber.ToBase10()) {
		return true;
	}
	return false;
}

bool Number::operator>=(const Number& otherNumber) {
	if (ToBase10() >= otherNumber.ToBase10()) {
		return true;
	}
	return false;
}

bool Number::operator<=(const Number& otherNumber) {
	if (ToBase10() <= otherNumber.ToBase10()) {
		return true;
	}
	return false;
}

bool Number::operator==(const Number& otherNumber) {
	if (ToBase10() == otherNumber.ToBase10()) {
		return true;
	}
	return false;
}

bool Number::operator!=(const Number& otherNumber) {
	if (ToBase10() != otherNumber.ToBase10()) {
		return true;
	}
	return false;
}

char Number::operator[](const int position) {
	if (position >= len || position < 0) {
		return '!';
	}
	return this->value[position];
}

