/*
* *****************************************************
*              csvMng module.
* *****************************************************
*
* CSV file management 
* -----------------------
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
    int arrSize,                    /* Number of elemenets in inputArray                        */
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
        printf("Can't open file\n");
        return 0;
    }

    char buf[MAX_BUF_SIZE];
    //int row_count = 0;
    //int field_count = 0; // represented by *actualArrSize 

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
                rVal = -1;
                printf(">>> readCSV : Error. actualArrSize  %d exceeds array size of %d \n", *actualArrSize, arrSize);
                break;
            }
            else
            {
                printf("[%d] %s\n", *actualArrSize, pVal);
                inputArray[*actualArrSize] = strtol(pVal, NULL, 10);       // String to long conversion
                // Move to next value
                pVal = strtok(NULL, ",");
                (*actualArrSize)++;
            }
        } // while(words in line are not empty)
        //row_count++;
    } // while(lines in file are not empty)

    fclose(fp);
}
