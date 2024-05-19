#define CATCH_CONFIG_RUNNER
#define TEST 1 // Always change to 1 before your final submission to Github Classroom.
#include "lib/catch.hpp"
#include <stdlib.h>
#include "sort.hpp"

// DO NOT CHANGE THIS METHOD
int runCatchTests(int argc, char* const argv[])
{
    return Catch::Session().run(argc, argv);
}

void print_stations(element* stations, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s : %s\n", stations[i].icao_code, stations[i].station_name);
    }
}

int readfile(element* stations, int* size) {
    FILE * fp;
    char line[100]; // keeps one line of the file

    // try to open the file; in case of an error exit the program
    *size = 0;
    fp = fopen("stations.csv", "r");
    if (!fp) {
        printf("Cannot open file stations.csv!\n");
        return 1;
    }
    
    // read all weather stations from file and add them to the
    // array
    while (fgets(line, 100, fp)) {
        // read one line and skip empty and comment lines
        if (line[0] == '#') continue;
        if (isspace(line[0])) continue;
        
        line[strcspn(line, "\r\n")] = 0;
        // take the first 4 characters as key value
        strncpy(stations[*size].icao_code, line, 4);
        stations[*size].icao_code[4] = '\0';
        
        // take the rest as value
        strcpy(stations[*size].station_name, strchr(line, ';')+1);
        *size += 1;
    }
    
    // close the file
    fclose(fp);
    
    return 0;
}



/*
 Test your C knowledge in the main function, but leave the very last lines of code unchanged. Also, DON'T add any additional return statements.
 */
int main(int argc, char* const argv[] ){
    // =====================
    // Sorting Algorithms
    // ---------------------
    // Test your implemenation here:
    
    element* stations; // holds the station codes and names
    element* tmpStations; // holds temporary station codes and names for merge sort
    int size; // holds the number of valid entries in the array, will be passed readfile as parameter
        
    stations = (element*)malloc(sizeof(element)*6000);
    tmpStations = (element*)malloc(sizeof(element)*6000);
    
    // now lets try selection sort
    // read the station data from file
    // sort the station names
    // check the result

    // now lets try merge sort
    // read the station data from file
    // sort the station names
    // print the result

    // now lets try selection sort with a function pointer
    // implement a custom compare function in main.cpp
    // compare by icao_code
    // read the station data from file
    // sort the station names
    // print the result
    
    // free up heap memory

    // DO NOT CHANGE CODE AFTER THIS LINE
    // This is where automatic testing starts, when the define macro constant is set to 1.
    // For local development you can set the constant to 0 until you finished your implementation.
    // Don't just program against the test cases. Also "play" with your source code and experiment with C.
    if (TEST){
        return runCatchTests(argc, argv);
    }
    return 0;
}






