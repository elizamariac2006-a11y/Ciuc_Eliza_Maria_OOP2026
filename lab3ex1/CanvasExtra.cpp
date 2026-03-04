#include "CanvasExtra.h"
#include<iostream>
#include<cstdarg>
using namespace std;

CanvasExtra::CanvasExtra(int lines, int columns)  : lines(lines) , columns(columns) {
	canva = new char*[lines + 2];
	for (int i = 0; i < lines; i++) {
		canva[i] = new char[columns + 2];
	}

	clear();
}

CanvasExtra::~CanvasExtra() {
	for (int i = 0; i < lines; i++) {
		delete[] canva[i];
	}
	delete[] canva;
}

void CanvasExtra::set_pixel(int x, int y, char ch) {
	if (!isInTheCanva(x, y)) {
		printf("Point (%d %d) invalid!\n", x, y);
		return;
	}
	canva[x][y] = ch;
}

void CanvasExtra::set_pixels(int count, ...) {
	int x, y;
	char ch;
	va_list arguments;
	va_start(arguments, count);
	for (int i = 1; i <= count; i++) {
		x = va_arg(arguments, int);
		y = va_arg(arguments, int);
		ch = va_arg(arguments, char);
		set_pixel(x, y, ch);
	}
}

void CanvasExtra::clear() {
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			canva[i][j] = ' ';
		}
	}
}

void CanvasExtra::print() const {
	for (int i = 0; i < lines; i++) {
		//printf("**");
		for (int j = 0; j < columns; j++) {
			//printf("**");
			cout << canva[i][j];
		}
		printf("\n");
	}
}

bool CanvasExtra::isInTheCanva(int x, int y) {
	if (x < 0 || y < 0 || x >= lines || y >= columns) {
		return false;
	}
	return true;
}