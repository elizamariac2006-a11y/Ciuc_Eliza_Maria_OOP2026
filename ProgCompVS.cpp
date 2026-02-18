#include <iostream>
#include<cstring>
#include <vector>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <map>

using namespace std;

ifstream fin("input.in");

char input[200];
char vect[200][200];
int sizeVector;

void readData() {
    cin.getline(input, 200);
}

void sortVector() {
    bool esteSortat = false;

    while (!esteSortat) {
        esteSortat = true;
        for (int i = 0; i < sizeVector - 1; i++) {
            int len1 = strlen(vect[i]);
            int len2 = strlen(vect[i + 1]);
            if (len2 < len1) {
                continue;
            }
            else if (len2 > len1) {
                esteSortat = false;
                char aux[200];
                strcpy_s(aux, vect[i]);
                strcpy_s(vect[i], vect[i + 1]);
                strcpy_s(vect[i + 1], aux);
            } else {
                if (strcmp(vect[i], vect[i + 1]) > 0) {
                    esteSortat = false;
                    char aux[200];
                    strcpy_s(aux, vect[i]);
                    strcpy_s(vect[i], vect[i + 1]);
                    strcpy_s(vect[i + 1], aux);
                }
            }
        }
    }

    for (int i = 0; i < sizeVector; i++) {
        cout << vect[i] << "\n";
    }
}

void formVector() {
    sizeVector = 0;
    char* token;
    char* nextToken;
    token = strtok_s(input, " ", &nextToken);
    while (token != NULL) {
        strcpy_s(vect[sizeVector], token);
        sizeVector++;
        token = strtok_s(NULL, " ", &nextToken);
    }
    //cout << sizeVector;
}

int main() {
    readData();
    formVector();
    sortVector();
    return 0;
}
