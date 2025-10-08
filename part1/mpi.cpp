#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 4  // size of the matrix

int main(int argc, char* argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int A[N][N], B[N][N], C[N][N];
    int i, j, k;

    // Master initializes matrices
    if (rank == 0) {
        printf("Matrix A:\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                A[i][j] = rand() % 10;
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }

        printf("Matrix B:\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                B[i][j] = rand() % 10;
                printf("%d ", B[i][j]);
            }
            printf("\n");
        }
    }

    // Broadcast matrix B to all nodes
    MPI_Bcast(B, N*N, MPI_INT, 0, MPI_COMM_WORLD);

    // Scatter rows of A
    int rows_per_process = N / size;
    int subA[rows_per_process][N];
    MPI_Scatter(A, rows_per_process*N, MPI_INT, subA, rows_per_process*N, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process computes its part of C
    int subC[rows_per_process][N];
    for (i = 0; i < rows_per_process; i++) {
        for (j = 0; j < N; j++) {
            subC[i][j] = 0;
            for (k = 0; k < N; k++) {
                subC[i][j] += subA[i][k] * B[k][j];
            }
        }
    }

    // Gather results
    MPI_Gather(subC, rows_per_process*N, MPI_INT, C, rows_per_process*N, MPI_INT, 0, MPI_COMM_WORLD);

    // Master prints result
    if (rank == 0) {
        printf("\nFinal Result (C = A * B):\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    }

    MPI_Finalize();
    return 0;
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
           
