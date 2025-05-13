#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int calcDD1(int **A, int n)
{
    int lrD = 0, rlD = 0;

    for (int i = 0; i < n; i++)
    {
        lrD += A[i][i];
        rlD += A[i][n-i-1];
    }
    
    return (int)abs(lrD - rlD);
}


int calcLeftSide(int ** A,int n){
    int lrD = 0;
    if (n == 0){
        return A[n][n];
    }
    lrD = calcLeftSide(A , n - 1);
    return A[n][n] + lrD;
}


int calcRightSide(int **A,int n,int m){
    int rlD = 0;
    if (n == 0){
        return A[n][m];
    }
    rlD = calcRightSide(A,n-1,m+1);
    return A[n][m] + rlD;
}


int calcDD2(int **A, int n)
{
    int lrD = 0, rlD = 0;
    rlD = calcRightSide(A,n-1,0);
    lrD = calcLeftSide(A,n-1);
    return (int)abs(lrD - rlD);
}




int main()
{
    int size = 3;

    // Allocate memory for rows
    int **array = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        array[i] = malloc(size * sizeof(int));
    }

    // Fill the array with some data
    int count = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[i][j] = count++;
        }
    }


    int ans = calcDD2(array, size);


    printf("%d\n", ans);



    // Free memory
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);


    return 0;
}