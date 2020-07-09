/*
* *****************************************************
*              csvMng module.
* CSV file management
*
* ReadCSV function is based on https://codingboost.com/parsing-csv-files-in-c
*
*
* "An advanced beginner, C is what I see now"
* Soumik Ranjan Dasgupta

* *****************************************************
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for strtol


#include "csvMng.h"

/* Module private constant */
// Buffer size for reading lines from input file
#define MAX_BUF_SIZE (4096)

int readCSV(const char* fileName,   /* Input        : CSV File name to parse                    */
    int inputArray[],               /* Input/Output : Buffer to fill in values from CSV file    */
    int arrSize,                    /* Maximum number of elemenets                              */
    int* actualArrSize)             /* Actual number of elements read into inputArray           */
{
    /*
    *  Assumption :
    *  All the strings are in one liner. No support currently for multi lines
    *  Return value : 0 on success
    *                 Non zero error code if an issue encountered
    */
    int rVal = 0;                       // Initialize return value to success
    *actualArrSize = 0;

    FILE *fp = fopen(fileName, "r");

    if (!fp) {
        printf(">>> readCSV : Error. Can't open file %s\n", fileName);
        return -1;
    }

    char buf[MAX_BUF_SIZE];

    printf("\n");
    printf(">>> readCSV : Reading file %s\n", fileName);

    // Iterate over lines
    while (fgets(buf, MAX_BUF_SIZE, fp)) {
        // Initialization before processing line
        char *pVal = NULL;
        //field_count = 0;

        // Get the first token, if exists
        pVal = strtok(buf, ",");

        // Iterate over comma separated tokens
        while (pVal != NULL) {
            if ((*actualArrSize) >= arrSize)
            {                
                printf(">>> readCSV : Error. Input vector exceeds array size of %d \n", arrSize);
                return -2;
            }
            else
            {
                // DEBUG
                //printf("[%d] %s\n", *actualArrSize, pVal);

                inputArray[*actualArrSize] = strtol(pVal, NULL, 10);       // String to long conversion
                // Move to next value
                pVal = strtok(NULL, ",");
                (*actualArrSize)++;
            }
        } // while(words in line are not empty)
        //row_count++;
    } // while(lines in file are not empty)

    fclose(fp);

    return 0;
}
