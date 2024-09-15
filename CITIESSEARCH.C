#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct city {
    int stdcode;
    char cityname[50];
} city; 

int linear(city cit[], char *tarcity, int i) {
    for (int j = 0; j < i; j++) {
        if (strcmp(cit[j].cityname, tarcity) == 0) {
            return j;  // Return the index if city is found
        }
    }
    return -1;  // Return -1 if the city is not found
}

int main() {
    int i = 0;
    city cit[30];
    char fname[50];  // Increased the buffer size for file name
    printf("Enter your file name: ");
    scanf("%s", fname);

    // Open the file
    FILE *fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("Unable to read your file.\n");
        exit(1);
    }

    // Read the city data from the file
    while (fscanf(fp, "%d %s", &cit[i].stdcode, cit[i].cityname) != EOF) {
        i++;
    }
    fclose(fp);

    // Accept city name to search from user
    char tarcity[40];
    printf("Enter the city that you want to search for: ");
    scanf("%s", tarcity);

    // Perform linear search
    int pos = linear(cit, tarcity, i);

    if (pos == -1) {
        printf("The city that you want to search for is not found.\n");
    } else {
        // Output the result
        printf("STD Code = %d\tCity Name = %s\n", cit[pos].stdcode, cit[pos].cityname);
    }

    return 0;
}
