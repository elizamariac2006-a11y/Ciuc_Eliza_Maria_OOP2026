#include<iostream>
#include "NumberList.h"


 void NumberList :: Init() {
     this->count = 0;
     for (int i = 0; i < 10; i++) {
         this->numbers[i] = 0;
     }
 }

bool NumberList :: Add(int x) {
    if ( count == 10 ) {
        return false;
    }
    numbers[count] = x;
    count++;
    return true;
}
    
void NumberList :: Sort() {
    for (int i = 1; i < count; i++) {
        int numToInsert = numbers[i];
        int j = i - 1;
        while ( j >= 0 && numbers[j] > numToInsert ) {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = numToInsert;
    }
}

void NumberList :: Print() {
    if ( count == 0 ) {
        printf( "Empty vector !\n" );
        return;
    }
    printf( "Current vector is : " );
    for (int i = 0; i < count; i++) {
        printf( "%d ", numbers[i] );
    }
    printf( "\n" );
}