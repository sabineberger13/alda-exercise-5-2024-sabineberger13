//
//  sort.hpp
//  ALDA_Exercise5v12021_Solution
//
//  Created by Michael Strommer on 17.05.21.
//

#ifndef sort_hpp
#define sort_hpp

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
struct _element {
    char icao_code[5];
    char station_name[100];
};

typedef struct _element element;

void selection_sort(element* stations, int size);
void merge_sort(element* stations, element* tmpStations, int left, int right);
// selection sort supporting custom compare function:
void selection_sort_fp(element* stations, int size, int (*comp)(element*, element*));
int compareByIcaoCode(element* a, element* b);

#endif /* sort_hpp */
