#include <arm_neon.h>
#include <stdio.h>
#include "neon.h"
#include <time.h>

#define MATRIX_WIDTH 4

void MatProdC(
    float A[MATRIX_WIDTH][MATRIX_WIDTH],
    float B[MATRIX_WIDTH][MATRIX_WIDTH],
    float C[MATRIX_WIDTH][MATRIX_WIDTH]
)
{

    for(int i = 0; i < MATRIX_WIDTH; i++)
    {
        for(int j = 0; j < MATRIX_WIDTH; j++)
        {
            for(int k = 0; k < MATRIX_WIDTH; k++)
            {
                C[i][j] += A[i][k] * B[k][j]; 
            }

        }
    }
}

void MatProdVecC(
    float* aVec,
    float* bVec,
    float* cVec
)
{
    for(int i = 0; i < MATRIX_WIDTH * MATRIX_WIDTH; i++)
    {
        for(int j = 0; j < MATRIX_WIDTH; j++)
        {
            cVec[i] += aVec[j + (i/MATRIX_WIDTH) * MATRIX_WIDTH] * bVec[j * MATRIX_WIDTH + i % MATRIX_WIDTH];
        }

    }
}


int main()
{
    //normal c implementation
    clock_t begin = clock();
    float A[MATRIX_WIDTH][MATRIX_WIDTH];
    float B[MATRIX_WIDTH][MATRIX_WIDTH];
    float C[MATRIX_WIDTH][MATRIX_WIDTH];
    for(int i = 0; i < MATRIX_WIDTH; i++)
    {
        for(int j = 0; j < MATRIX_WIDTH; j++)
        {
            A[i][j] = i * MATRIX_WIDTH + j;
            B[i][j] = i * MATRIX_WIDTH + j;
            C[i][j] = 0;
        }
    }
    MatProdC(&A[0], &B[0], &C[0]);
    clock_t end = clock();
    float time_spent = (float)(end - begin) / CLOCKS_PER_SEC * 10000.0;
    printf("It took %f ms to caculate matrix C: \n", time_spent);
    for(int i = 0; i < MATRIX_WIDTH; i++)
    {
        for(int j = 0; j < MATRIX_WIDTH; j++)
        {
            (void)printf("%f ", C[i][j]);
        }
        (void)printf("\n");
    }
    (void)printf("\n");
    begin = clock();
    float aVec[MATRIX_WIDTH * MATRIX_WIDTH];
    float bVec[MATRIX_WIDTH * MATRIX_WIDTH];
    float cVec[MATRIX_WIDTH * MATRIX_WIDTH];
    for(int i = 0; i < MATRIX_WIDTH * MATRIX_WIDTH; i++)
    {
        bVec[i] = i;
        aVec[i] = i;
        cVec[i] = 0;
    }
    MatProdVecC(aVec, bVec, cVec);
    end = clock();
    time_spent = (float)(end - begin) / CLOCKS_PER_SEC * 1000.0;
    printf("It took %f s to caculate matrix C: \n", time_spent);
    for(int i = 1; i <= MATRIX_WIDTH * MATRIX_WIDTH; i++)
    {
        (void)printf("%f ", cVec[i - 1]);
        if(i % MATRIX_WIDTH == 0)
        {
            (void)printf("\n");
        }

    }

    (void)printf("\n");
    begin = clock();
    for(int i = 0; i < MATRIX_WIDTH * MATRIX_WIDTH; i++)
    {
        bVec[i] = i;
        aVec[i] = i;
        cVec[i] = 0;
    }
    MultiplyMatVecNi(aVec, bVec, cVec, MATRIX_WIDTH * MATRIX_WIDTH);
    end = clock();
    time_spent = (float)(end - begin) / CLOCKS_PER_SEC * 1000.0;
    printf("It took %f s to caculate matrix C: \n", time_spent);
    for(int i = 1; i <= MATRIX_WIDTH * MATRIX_WIDTH; i++)
    {
        (void)printf("%f ", cVec[i - 1]);
        if(i % MATRIX_WIDTH == 0)
        {
            (void)printf("\n");
        }

    }
    return 0;
}