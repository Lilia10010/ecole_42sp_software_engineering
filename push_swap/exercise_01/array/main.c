#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

int main(void)
{
    int n = 5;
    int i = 0;
    int *arr = create_and_file_array(n);
    printf("Array criadenho: ");
    while (i < n)
    {
        printf("%d", arr[i]);
        ++i;
    }
    printf("\n\n");
    free(arr);
    return (0);
}