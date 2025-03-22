#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

int* create_and_file_array(int n)
{
    int *arr;
    int i = 0;
    arr = (int *)malloc(n * sizeof(int));
    if(!arr)
    {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    while(i < n)
    {
        arr[i] = 1 + i;
        ++i;
    }
    return (arr);
}