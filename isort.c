#include <stdio.h>
#include "isort.h"

    void shift_element1(int* arr, int i)
{
    int index = i;
    for(int j = 0; j < i; j++)
    {
        int * p_length = (arr + index--);
        int * p_lengthMin1 = (p_length - 1);
        int tmp = *p_length;
        *p_length = *p_lengthMin1;
        *(p_lengthMin1) = tmp;
        
    }
}
    void insertion_sort(int*arr,int len)
    {
        for(int i = 0; i < len; i++)
        {     
            int flag = 0;       
            int * p_firstp = arr;
            int * p_secondp = (arr+i);
            int diff = i;
            while(p_firstp != p_secondp && flag == 0)
            {
                if(*p_firstp > *p_secondp)
                {
                 shift_element1(p_firstp, diff);
                 flag = 1;
                }
                p_firstp++;
                diff--;
            }
        }
    }


