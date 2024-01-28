#include <stdio.h>
#include <stdlib.h> 
// Use more libraries as necessary

#define DEBUG 0

/* ---------- Project 1 - Problem 2 - Mat-Vec Mult ----------
    This file will multiply a matrix and vector.
    Complete the TODOs left in this file.
*/ // ------------------------------------------------------ //


int main (int argc, char *argv[])
{
    // Catch console errors
    if( argc != 7)
    {
        printf("USE LIKE THIS: serial_mult_mat_vec in_mat.csv n_row_1 n_col_1 in_vec.csv n_row_2 output_file.csv \n");
        return EXIT_FAILURE;
    }

    // Get the input files
    FILE *matFile = fopen(argv[1], "r");
    FILE *vecFile = fopen(argv[4], "r");

    // Get dim of the matrix
    char* p1;
    char* p2;
    int n_row1 = strtol(argv[2], &p1, 10 );
    int n_col1 = strtol(argv[3], &p2, 10 );

    // Get dim of the vector
    char* p3;
    int n_row2 = strtol(argv[5], &p3, 10 );

    // Get the output file
    FILE *outputFile = fopen(argv[6], "w");


    // TODO: Use malloc to allocate memory for the matrices
    int* matrix = (int*)malloc((n_row1 * n_col1) * sizeof(int));
    int* vector = (int*)malloc(n_row2 * sizeof(int));
    int* result = (int*)malloc(n_row1 * sizeof(int));

    // TODO: Parse the input CSV files
    //parses matFILE CSV to insert matrix elements
    for (int i = 0; i < n_row1; i++)
    {
        for (int j = 0; j < n_col1; j++)
        {
            fscanf(matFile, "%d", &matrix[i * n_col1 + j]);
        }
    }

    //parses vecFILE CSV to insert vector elements
    for (int i = 0; i < n_row2; i++)
    {
        fscanf(vecFile, "%d", &vector[i]);
    }

    // TODO: Perform the matrix-vector multiplication
    for (int i = 0; i < n_row1; i++)
    {
        val = 0;
        for (int j = 0; j < n_col1; j++)
        {
            val += matrix[i * n_col1 + j] * vector[j];
        }
        result[i] = val;
    }

    // TODO: Write the output CSV file
    for (int i = 0; i < n_row1; i++)
    {
        fprintf(outputFile, "%d", result[i]);
    }

    // TODO: Free memory
    free(matrix)
    free(vector)
    free(result)
    // Cleanup
    fclose(matFile);
    fclose(vecFile);
    fclose(outputFile);
    // Free buffers here as well!
    



    return 0;
}
