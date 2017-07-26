/*
 * selectionsort.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: baekhg
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertSort(int* arr, int size);

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

    InsertSort(numbers, inputNum);

    for(i = 0; i < inputNum; i++)
    {
        printf("%d",numbers[i]);
    }


    return 0;
}

void InsertSort(int* arr, int size)
{
    int i = 0;
    for(i = 0; i < size; i++)
    {
        int tmp = arr[i];
        int aux = i - 1;

        while((aux >= 0) && (arr[aux] > tmp))
        {
            arr[aux + 1] = arr[aux];
            aux--;
        }

        arr[aux + 1] = tmp;
    }
}
