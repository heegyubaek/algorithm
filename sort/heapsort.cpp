/*
 * heapsort.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: baekhg
 */

#include <stdio.h>
#include <stdlib.h>

#define LEFT_CHILD(x)   (2*x+1)
#define RIGHT_CHILD(x)  (2*x+2)
#define PARENT(x)       ((x-1)/2)
#define SWAP(a, b, type) do{\
    type t; \
    t=a; \
    a=b; \
    b=t; \
}while(0)

void HeapSort(int *base, int n);
void ViewArr(int *arr, int n);
void InitHeap(int *base, int n);
void MakeHeap(int *base, int n);
int FindMaxIndex(int *base, int n, int now);

int main()
{
    int inputNum = 0;
    scanf("%d", &inputNum);
    fflush(stdin);

    int* inputArr = (int*)malloc(sizeof(int) * inputNum);
    int i = 0;
    for(i = 0; i < inputNum; i++)
    {
        scanf("%d", &inputArr[i]);
        fflush(stdin);
    }

    ViewArr(inputArr, inputNum);

    HeapSort(inputArr, inputNum);

    ViewArr(inputArr, inputNum);

    return 0;
}

void HeapSort(int *base, int n)
{
    InitHeap(base, n);
    n--;

    SWAP(base[0], base[n], int);
    while(n > 1)
    {
        MakeHeap(base, n);
        n--;
        SWAP(base[0], base[n], int);
    }
}

void InitHeap(int *base, int n)
{
    int pa = 0;
    int now;
    int i;
    for(i = 1; i < n; i++)
    {
        now = i;
        while(now > 0)
        {
            pa = PARENT(now);
            if(base[now] > base[pa])
            {
                SWAP(base[now], base[pa], int);
                now = pa;
            }
            else
            {
                break;
            }
        }
    }
}

void MakeHeap(int *base, int n)
{
    int now = 0;
    int mp = 0;

    while(LEFT_CHILD(now) < n)
    {
        int mp = FindMaxIndex(base, n, now);
        if(mp == now)
        {
            break;
        }
        SWAP(base[mp], base[now], int);
        now = mp;
    }

}

int FindMaxIndex(int *base, int n, int now)
{
    int lc = LEFT_CHILD(now);
    int rc = RIGHT_CHILD(now);

    if(rc >= n)
    {
        if(base[now] < base[lc])
        {
            return lc;
        }
        return now;
    }
    if(base[lc] < base[rc])
    {
        return rc;
    }
    return lc;
}

void ViewArr(int *arr, int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        printf("% d", arr[i]);
    }
    printf("\n");
}

