/*
 * selectionsort.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: baekhg
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* a, int* b);
void SelectionSort(int* arr, int size);

int main()
{
    int inputNum;
    scanf("%d", &inputNum);

    int *numbers = (int*)malloc(sizeof(int) * inputNum);

    int i = 0;
    for(i = 0; i < inputNum; i++)
    {
        scanf("%d",&numbers[i]);
    }

    SelectionSort(numbers, inputNum);

    for(i = 0; i < inputNum; i++)
    {
        printf("%d",numbers[i]);
    }


    return 0;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


void SelectionSort(int* arr, int size)
{
    int min = 0;
    int i = 0;
    for(i = 0; i < size - 1; i++)
    {
        min = i;

        int j = 0;
        for(j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}
