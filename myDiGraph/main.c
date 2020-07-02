#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>

#define MAX_NUM_NODES 10

void initAdjMat(int adjMat[MAX_NUM_NODES][MAX_NUM_NODES]) {
    for (int i = 0; i < MAX_NUM_NODES; i++) {
        for (int j = 0; j < MAX_NUM_NODES; j++) {
            adjMat[i][j] = -1;
        }
    }
}

void readCSV() {
    // Based on : https://codingboost.com/parsing-csv-files-in-c
   
    FILE *fp = fopen("myGraph.csv", "r");

    if (!fp) {
        printf("Can't open file\n");
        return 0;
    }

    char buf[1024];
    int row_count = 0;
    int field_count = 0;

    while (fgets(buf, 1024, fp)) {
        char *pVal = NULL;
        field_count = 0;
        pVal = strtok(buf, ",");

        while (pVal != NULL) {
            printf("[Row_cnt/Field_cnt] [%d/%d] %s\n", row_count, field_count, pVal);
            // Move to next value
            pVal = strtok(NULL, ",");
            field_count++;
        } // while(words in line are not empty)
        row_count++;
    } // while(lines in file are not empty)

    fclose(fp);
}


int main() {
    printf("My DiGraph tool\n");

    // adjacency matrix object
    int adjMat[MAX_NUM_NODES][MAX_NUM_NODES];

    initAdjMat(adjMat);

    readCSV();

    return 0;
}