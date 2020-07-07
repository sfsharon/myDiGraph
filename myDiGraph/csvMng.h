#ifndef CSVMNG_H
#define CSVMNG_H

#define MAX_BUF_SIZE (4096)

int readCSV(const char* fileName,   /* Input        : CSV File name to parse                    */
    int inputArray[],               /* Input/Output : Buffer to fill in values from CSV file    */
    int arrSize,                    /* Number of elemenets in inputArray                        */
    int* actualArrSize);             /* Actual number of elements read into inputArray           */

#endif
