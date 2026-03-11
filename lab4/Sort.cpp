#include "Sort.h"
#include<string>
#include<Random>
#include<cstdarg>

Sort::Sort(int n, int v[]) {
	this->n = n;
	this->v = new int[n + 2];

	for (int i = 0; i < n; i++) {
		this->v[i] = v[i];
	}
}

Sort::Sort(char s[]) {
	int len;
	int count;
	int aux[1002];

	count = 0;
	len = strlen(s);
	for (int i = 0; i < len; ) {
		if (s[i] >= '0' && s[i] <= '9') {
			int number = 0;
			while (i < len && s[i] >= '0' && s[i] <= '9') {
				number = number * 10 + (int)(s[i] - '0');
				i++;
			}
			aux[count] = number;
			count++;
		}
		else {
			i++;
		}
	}
	this->n = count;
	this->v = new int[count + 2];
	for (int i = 0; i < n; i++) {
		this->v[i] = aux[i];
	}
}

Sort::Sort(initializer_list<int> list) {
	this->n = list.size();
	this->v = new int[n + 2];
	int index = 0;
	for (int element : list) {
		v[index] = element;
		index++;
	}
}

Sort::Sort(int len, int minValue, int maxValue) {
	int element;

	this->n = len;
	this->v = new int[len + 2];

	srand(time(0));
	if (maxValue < minValue) {
		swap(minValue, maxValue);
	}
	for (int i = 0; i < n; i++) {
		element = minValue + rand() % (maxValue - minValue + 1);
		v[i] = element;
	}

}

Sort::Sort(int count, ...) {
	va_list arguments;

	this->n = count;
	v = new int[count + 2];
	va_start(arguments, count);
	for (int i = 0; i < count; i++) {
		v[i] = va_arg(arguments, int);
	}
	va_end(arguments);
}

Sort::~Sort() {
	delete[] v;
}

int Sort::GetElementsCount() {
	return this->n;
}

void Sort::Print() {
	printf("Elements count : %d\nVector: ", this->GetElementsCount());
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

int Sort::GetElementFromIndex(int index) {
	if (index >= n || index < 0) {
		printf("Index %d invalid!!", index);
		return -1;
	}
	return v[index];
}

void Sort::BubbleSort(bool ascendent) {
	bool isSorted;

	isSorted = false;
	while (!isSorted) {
		isSorted = true;
		for (int i = 0; i < n - 1; i++) {
			if (ascendent ? v[i] > v[i + 1] : v[i] < v[i + 1]) {
				isSorted = false;
				swap(v[i], v[i + 1]);
			}
		}
	}
}

void Sort::InsertSort(bool ascendent) {
	int element, j;

	for (int i = 1; i < n; i++) {
		element = v[i];
		j = i - 1;

		while (j >= 0 && (ascendent ?  element < v[j] : element > v[j])) {
			v[j + 1] = v[j];
			j--;
		}

		v[j + 1] = element;
	}
}
//        j  i
//74 5 8 65 873 274
int Sort::Pivot(int st, int dr, bool ascendent) {
	int pivot, i, j;
	pivot = st;
	i = st + 1;
	j = dr;
	if (ascendent) {
		//crescator
		while (i <= j) {
			if (v[i] <= v[pivot]) {
				i++;
			} else if (v[j] >= v[pivot]) {
				j--;
			} else {
				swap(v[i], v[j]);
				i++;
				j--;
			}
		}
		swap(v[pivot], v[i - 1]);
		/*for (int i = 0; i < n; i++) {
			printf("%d ", v[i]);
		}
		printf("\n");*/
		return i - 1;
	} else {
		//descrescator
		while (i <= j) {
			if (v[i] >= v[pivot]) {
				i++;
			}
			else if (v[j] <= v[pivot]) {
				j--;
			}
			else {
				swap(v[i], v[j]);
				i++;
				j--;
			}
		}
		swap(v[pivot], v[i - 1]);
		/*for (int i = 0; i < n; i++) {
			printf("%d ", v[i]);
		}
		printf("\n");*/

		return i - 1;
	}
}

void Sort::QuickSortRec(int st, int dr, bool ascendent) {
	if (st >= dr) {
		return;
	}
	int pivot = Pivot(st, dr, ascendent);
	QuickSortRec(st, pivot - 1, ascendent);
	QuickSortRec(pivot + 1, dr, ascendent);
}

void Sort::QuickSort(bool ascendent) {
	QuickSortRec(0, n - 1, ascendent);
}