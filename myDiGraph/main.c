#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

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
        field_count = 0;
        row_count++;

        if (row_count == 1) {
            continue;
        }

        char *field = strtok(buf, ",");
        while (field) {
            if (field_count == 0) {
                printf("First Name:\t");
            }
            if (field_count == 1) {
                printf("Last Name:\t");
            }
            if (field_count == 2) {
                printf("Phone Number:\t");
            }
            if (field_count == 3) {
                printf("Job Title:\t");
            }

            printf("%s\n", field);
            field = strtok(NULL, ",");

            field_count++;
        }
        printf("\n");
    }

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