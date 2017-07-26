/*
 * quicksort.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: baekhg
 */




#include <stdio.h>
#include <stdlib.h>

#define ALG_SPPED_TEST 0

#if ALG_SPPED_TEST
#include <ctime>
#endif

void swap(int* a, int* b);
void quick_sort(int* numbers, int s, int e);

int main()
{
#if ALG_SPPED_TEST
    srand(time(NULL));
#endif
    int inputNum = 0;
    scanf("%d", &inputNum);
    fflush(stdin);

    if(inputNum < 1 || inputNum > 10000000)
    {
        return 0;
    }

    int* numbers = (int*)malloc(sizeof(int) * inputNum);
    int i = 0;
    for(i = 0; i < inputNum ; i++)
    {
#if ALG_SPPED_TEST
        numbers[i] = rand();
#else
        scanf("%d",&numbers[i]);
        if(numbers[i] > 10000 || numbers[i] < 0)
        {
            return 0;
        }
#endif

    }
#if ALG_SPPED_TEST
    int start = clock();
#endif

    quick_sort(numbers, 0, inputNum-1);

    for(i = 0; i < inputNum ; i++)
    {
        printf("%d\n",numbers[i]);
    }
#if ALG_SPPED_TEST
    printf("result=%.3lf(sec)\n", (double)(clock()-start)/CLOCKS_PER_SEC);
#endif
    free(numbers);

    return 0;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void quick_sort(int* numbers, int s, int e)
{
    if( s < e)
    {
        int p = s, l = s+1, r = e;
        while(l <= r )
        {
            while(l <= e && numbers[l] <= numbers[p]) l++;
            while(r >= s+1 && numbers[r] >= numbers[p]) r--;
            if(l < r) swap(&numbers[l], &numbers[r]);
        }
        swap(&numbers[p], &numbers[r]);
        quick_sort(numbers, s, r-1);
        quick_sort(numbers, r+1, e);
    }
}
