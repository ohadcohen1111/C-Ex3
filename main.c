#include <stdio.h>
#include "isort.h"

int main()
{
    int arr[ARR];
    int *p_arr = arr;
    for(int i = 0; i < ARR; i++)
    {
        int num;
        printf("Enter a number: ");
        scanf("\n%d",&num);
        *p_arr = num;
        p_arr++;
    }
    insertion_sort(arr, 50);
    p_arr = arr;
    for(int i = 0; i < ARR; i++)
    {
        printf("%d,",*p_arr);
        p_arr++;
    }
    return 0;
}
