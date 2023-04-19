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

struct movies *createMovies(char* currline) {
    struct movies* currMovie = malloc(sizeof(struct movies));
    // For use with strtok_r
    char *saveptr;

    // The first token is the title
    char *token = strtok_r(currline, ", ", &saveptr);
    currMovie->title = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->title, token);

    // The next token is the year
    token = strtok_r(NULL, ", ", &saveptr);
    currMovie->year = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->year, token);

    // The next token is the languages
    token = strtok_r(NULL, ", ", &saveptr);
    currMovie->languages = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->languages, token);

    // The last token is the rate
    token = strtok_r(NULL, "\n", &saveptr);
    currMovie->rate = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->rate, token);

    // Set the next node to NULL in the newly created movie entry
    currMovie->next = NULL;

    return currMovie;
}

struct movies* processFile(char* filename) {
    FILE *fptr = fopen(filename, "r");
    
    char *currline = NULL;
    size_t len = 0;
    ssize_t nread;
    char *token;

    struct movies *head = NULL;
    struct movies *tail = NULL;

    getline(&currline, &len, fptr);
    while ((nread = getline(&currline, &len, fptr)) != -1)
    {
        printf("%s", currline);
        // Get a new movie node corresponding to the current line
        struct movies *newNode = createMovies(currline);
        if (head == NULL)
        {
            // This is the first node in the linked link
            // Set the head and the tail to this node
            head = newNode;
            tail = newNode;
        }
        else
        {
            // This is not the first node.
            // Add this node to the list and advance the tail
            tail->next = newNode;
            tail = newNode;
        }
    }
    free(currline);
    fclose(fptr);
    return head;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Provide the name of the file!\n");
    }
    struct movies *list = processFile(argv[1]);
    
    return 0;
}


// int main (void) {
//     FILE *fptr = fopen("movies_sample_1.csv", "r");
//     if (fptr == NULL) {
//         perror("unable to open file!");
//         exit(1);
//     }

//     char* line = NULL;
//     ssize_t* len = 0;

//     getline(&line, &len, fptr);
//     while (getline(&line, &len, fptr) != -1) {
//         fputs(line, stdout);
//         fputs("|*\n", stdout);
//     }
//     return 0;
// }