//
//  sort.cpp
//  ALDA_Exercise5v12021_Solution
//
//  Created by Michael Strommer on 17.05.21.
//

#include "sort.hpp"
using namespace std;

void selection_sort(element* stations, int size){

    int j, i,smallestIndex;
    element tmp;

    for (j = 0; j <= size - 1; j++) {
        smallestIndex = j;

        for (i = j + 1; i < size; i++) {
            if (strcmp(stations[i].icao_code, stations[smallestIndex].icao_code) < 0){
                smallestIndex = i;
            }

        }

    }

}

void merge_sort(element* stations, element* tmpStations, int left, int right){

    int size = right - left;
    int middle = size/2;

    printf("size: %i | middle: %i\n", right - left, (right - left)/2);
    printf("left-middle: %i -%i | middle +1-right: %i -%i\n\n", left, middle, middle +1, right);

    if (left < right) {
        merge_sort(stations, tmpStations, left, middle);

        //merge_sort(stations, tmpStations, middle + 1, right - left);

        printf("---------------------Merge left ----------------\n\n");

        printf("---------------------Merge right ----------------\n\n");
    }
}

// selection sort supporting custom compare function:
void selection_sort_fp(element* stations, int size, int (*comp)(element*, element*)){

    for (int j = 0; j < size - 1; j++) {
        int min = j;


        for (int i = j + 1; i < size; i++) {

            if ((*comp)(&stations[i], &stations[min]) <= 0) {
                min = i;
            }
        }
        if (min != j) {
            element tmp = stations[j];
            stations[j] = stations[min];
            stations[min] = tmp;
        }
    }}


int compareByIcaoCode(element* a, element* b){
    return strcmp(a->icao_code, b->icao_code);
    //return -1;
}