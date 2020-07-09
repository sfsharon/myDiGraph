#ifndef CSVMNG_H
#define CSVMNG_H

int readCSV(const char* fileName,   /* Input        : CSV File name to parse                    */
    int inputArray[],               /* Input/Output : Buffer to fill in values from CSV file    */
    int arrSize,                    /* Number of elemenets in inputArray                        */
    int* actualArrSize);             /* Actual number of elements read into inputArray           */

#endif
