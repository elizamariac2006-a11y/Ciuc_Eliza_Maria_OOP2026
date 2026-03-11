#pragma once
#include <initializer_list>
using namespace std;
class Sort
{
private:
    int n;
    int* v;

    int Pivot(int st, int dr, bool ascendent = false);
    void QuickSortRec(int st, int dr, bool ascendent = false);

public:
    Sort(int len, int minValue, int maxValue);
    Sort(initializer_list<int> list);
    Sort(int n, int v[]);
    Sort(int count, ...);
    Sort(char s[]);
    ~Sort();
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};