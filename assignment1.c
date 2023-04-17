#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<fcntl.h>

struct movies {
    char* title;
    char* year;
    char* languages;
    char* rate;
    struct movies* next;
};

struct student* parse_file(char* filename) {
    FILE *fptr = fopen(filename, O_RDONLY);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Provide the name of the file!\n");
    }

    return 0;
}