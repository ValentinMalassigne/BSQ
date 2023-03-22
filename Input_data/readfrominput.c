#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int rows, cols, i, j;
    int **matrix;

    // check if the user provided the correct number of arguments
    if (argc != 3) {
        write(STDERR_FILENO, "Usage: ./program <rows> <cols>\n", 32);
        exit(EXIT_FAILURE);
    }

    // convert the argument strings to integers
    rows = atoi(argv[1]);
    cols = atoi(argv[2]);

    // allocate memory for the matrix array
    matrix = (int **) malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        exit(EXIT_FAILURE);
    }

    // allocate memory for each row of the matrix
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            exit(EXIT_FAILURE);
        }
    }

    // read the matrix values from standard input
    i = 0;
    while (i < rows) {
        j = 0;
        while (j < cols) {
            read(STDIN_FILENO, &matrix[i][j], sizeof(int));
            j++;
        }
        i++;
    }

    // print the matrix values
    i = 0;
    while (i < rows) {
        j = 0;
        while (j < cols) {
            write(STDOUT_FILENO, &matrix[i][j], sizeof(int));
            write(STDOUT_FILENO, " ", 1);
            j++;
        }
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }

    // free the memory used by the matrix
    i = 0;
    while (i < rows) {
        free(matrix[i]);
        i++;
    }
    free(matrix);

    return 0;
}