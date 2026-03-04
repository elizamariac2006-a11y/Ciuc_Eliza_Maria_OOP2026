#include "Canvas.h"
#include<iostream>
#include<queue>
using namespace std;

bool isInTheCanva(int x, int y, int height, int width) {
	if (x <= 0 || y <= 0) {
		return false;
	}
	if (x > height || y > width) {
		return false;
	}
	return true;
}

Canvas::Canvas(int width, int height) : width(width), height(height) {
	this->canva = new char*[height + 2];
	for (int i = 1; i <= height; i++) {
		this->canva[i] = new char[width + 2];

		for (int j = 1; j <= width; j++) {
			this->canva[i][j] = ' ';
		}
	}
}

Canvas::~Canvas() {
	for (int i = 1; i <= this->height; i++) {
		delete[] this->canva[i];
	}
	delete[] this->canva;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	if (!isInTheCanva(left, top, height, width) || !isInTheCanva(right, bottom, height, width)) {
		printf("Invalid points ! Getting outside of the canva !\n");
		return;
	}

	for (int i = top; i <= bottom; i++) {
		canva[left][i] = canva[right][i] = ch;
	}
	for (int i = left; i <= right; i++) {
		canva[i][top] = canva[i][bottom] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	if (!isInTheCanva(left, top, height, width) || !isInTheCanva(right, bottom, height, width)) {
		printf("Invalid points ! Getting outside of the canva !\n");
		return;
	}

	for (int i = left; i <= right; i++) {
		for (int j = top; j <= bottom; j++) {
			canva[i][j] = ch;
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch) {
	if (!isInTheCanva(x, y, height, width)) {
		printf("Invalid point ! Getting outside of the canva !\n");
		return;
	}

	canva[x][y] = ch;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	if (!isInTheCanva(x + ray, y, height, width) || !isInTheCanva(x, y + ray, height, width)
		|| !isInTheCanva(x, y - ray, height, width) || !isInTheCanva(x - ray, y, height, width)) {
		printf("Invalid points ! Getting outside of the canva !\n");
		return;
	}
	if (ray >= 2) {
		canva[x - ray][y] = canva[x - ray][y - 1] = canva[x - ray][y + 1] = ch;
		canva[x + ray][y] = canva[x + ray][y - 1] = canva[x + ray][y + 1] = ch;
		canva[x][y - ray] = canva[x - 1][y - ray] = canva[x + 1][y - ray] = ch;
		canva[x][y + ray] = canva[x - 1][y + ray] = canva[x + 1][y + ray] = ch;
		int point1i, point1j, point2i, point2j;

		point1i = x - ray; point1j = y - 1;
		point2i = x - 1; point2j = y - ray;
		do {
			point1i++; point1j--;
			point2i--; point2j++;
			canva[point1i][point1j] = canva[point2i][point2j] = ch;
		} while (point1i < point2i);

		point1i = x + ray; point1j = y - 1;
		point2i = x + 1; point2j = y - ray;
		do {
			point1i--; point1j--;
			point2i++; point2j++;
			canva[point1i][point1j] = canva[point2i][point2j] = ch;
		} while (point1i > point2i);

		point1i = x + ray; point1j = y + 1;
		point2i = x + 1; point2j = y + ray;
		do {
			point1i--; point1j++;
			point2i++; point2j--;
			canva[point1i][point1j] = canva[point2i][point2j] = ch;
		} while (point1i > point2i);

		point1i = x - ray; point1j = y + 1;
		point2i = x - 1; point2j = y + ray;
		do {
			point1i++; point1j++;
			point2i--; point2j--;
			canva[point1i][point1j] = canva[point2i][point2j] = ch;
		} while (point1i < point2i);
	}
}

void Canvas::Print() {
	for (int i = 0; i <= width + 1; i++) {
		cout << "*";
	}
	cout << "\n";
	for (int i = 1; i <= height; i++) {
		cout << "*";
		for (int j = 1; j < width; j++) {
				cout << canva[i][j];
		}
		cout << "*\n";
	}

	for (int i = 0; i <= width + 1; i++) {
		cout << "*";
	}
	cout << "\n";
}

void Canvas::Clear() {
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= height; j++) {
			canva[i][j] = ' ';
		}
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	if (!isInTheCanva(x1, y1, height, width) || !isInTheCanva(x2, y2, height, width)) {
		printf("Invalid points ! Getting outside of the canva !\n");
		return;
	}

	int** d;
	d = new int* [height + 2];
	for (int i = 1; i <= height; i++) {
		d[i] = new int[width + 2];
		for (int j = 1; j <= width; j++) {
			d[i][j] = 2e9;
		}
	}

	queue< pair<int, int> > q;
	int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
	int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

	q.push({ x1, y1 });
	d[x1][y1] = 0;
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++) {
			int x = i + dx[k];
			int y = j + dy[k];

			if (isInTheCanva(x, y, height, width) && d[x][y] > d[i][j] + 1) {
				d[x][y] = d[i][j] + 1;
				q.push({ x, y });
			}
		}
	}

	/*for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}*/

	int i = x2; int j = x2;
	canva[x1][y1] = canva[x2][y2] = ch;
	while (i != x1 || j != y1) {
		/*canva[i][j] = ch;*/
		int x, y;
		x = i + dx[0]; y = j + dy[0];
		for (int k = 1; k < 8; k++) {
			int x2, y2;
			x2 = i + dx[k];
			y2 = j + dy[k];
			if (d[x2][y2] < d[x][y]) {
				x = x2;
				y = y2;
			}
		}
		canva[x][y] = ch;
		i = x; j = y;
	}

	for (int i = 1; i <= height; i++) {
		delete[] d[i];
	}
	delete[] d;
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	if (!isInTheCanva(x + ray, y, height, width) || !isInTheCanva(x, y + ray, height, width)
		|| !isInTheCanva(x, y - ray, height, width) || !isInTheCanva(x - ray, y, height, width)) {
		printf("Invalid points ! Getting outside of the canva !\n");
		return;
	}
	DrawCircle(x, y, ray, ch);
	int i = x - ray + 1;
	int j1 = y - 1, j2 = y + 1;
	while (i <= x) {
		for (int p = j1; p <= j2; p++) {
			canva[i][p] = ch;
		}
		i++;
		j1--; j2++;
	}
	i = x + 1;
	j1 += 2; j2 -= 2;
	while (i < x + ray) {
		for (int p = j1; p <= j2; p++) {
			canva[i][p] = ch;
		}
		i++;
		j1++; j2--;
	}
}