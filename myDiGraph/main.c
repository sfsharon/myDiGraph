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
    char buf[1024];

    if (!fp) {
        printf("Can't open file\n");
        return 1;
    }

    while (fgets(buf, 1024, fp)) {
        printf("%s", buf);
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