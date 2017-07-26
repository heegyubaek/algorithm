/*
 * radixsort.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: baekhg
 */



#include <stdio.h>
#include <stdlib.h>

#define INDEX 10001

void RadixSort(int *arr, int size);

int main()
{
    int n, i, k;
    int arr[INDEX] = {0,};

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    RadixSort(arr, n);

    for(i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }

}


void RadixSort(int *arr, int size)
{
    int i, j, k;
    int *queue[10];
    int top[10];

    for( i = 0; i < 10; i++)
    {
        queue[i] = (int*)malloc(sizeof(int) * size);
        top[i] = -1;
    }

    // Find of the biggest number.
    j = arr[0];
    for(i = 1; i < size; i++)
    {
        if(arr[i] > j)
        {
            j = arr[i];
        }
    }

    // Decide of digit.
    int digit = 1;
    do
    {
        digit *= 10;
    }while(digit <= j);

    int data = 0;
    for(i = 1; i <= digit ; i *= 10)
    {
        for(j = 0; j < size; j++)
        {
            data = (arr[j] / i) % (i * 10); /* Calculate number of each digit */
            queue[data][++top[data]] = arr[j];
        }
        k = 0;
        for(j = 0; j < 10; j++)
        {
            for(data = 0; data <= top[j]; data++)
            {
                arr[k++] = queue[j][data];
            }
            top[j] = -1;
        }
    }

    for(i = 0; i < 10 ; i++)
    {
        free(queue[i]);
    }


}

