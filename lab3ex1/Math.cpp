#include "Math.h"
#include <cstdarg>
#include <cstring>

int Math::Add(int x, int y) {
	return (x + y);
}

int Math::Add(int x, int y, int z) {
	return(x + y + z);
}

int Math::Add(double x, double y) {
	return (int)(x + y);
}

int Math::Add(double x, double y, double z) {
	return (int)(x + y + z);
}

int Math::Mul(int x, int y) {
	return x * y;
}

int Math::Mul(int x, int  y, int z) {
	return x * y * z;
}

int Math::Mul(double x, double y) {
	return (int)(x * y);
}

int Math::Mul(double x, double y, double z) {
	return (int)(x * y * z);
}

int Math::Add(int count, ...) {
	va_list arguments;
	va_start(arguments, count);

	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += va_arg(arguments, int);
	}
	va_end(arguments);
	return sum;
}


char* Math::Add(const char* s1, const char* s2) {
	if (s1 == nullptr || s2 == nullptr) {
		return nullptr;
	}

	int newSize = strlen(s1) + strlen(s2) + 1;
	char* newS = new char[newSize];
	int index, size;
	
	index = 0; size = strlen(s1);
	for (int i = 0; i < size; i++) {
		newS[index] = s1[i];
		index++;
	}

	size = strlen(s2);
	for (int i = 0; i < size; i++) {
		newS[index] = s2[i];
		index++;
	}

	newS[index] = '\0';
	return newS;
}