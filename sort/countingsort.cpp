/*
 * radix.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: baekhg
 */


#include <stdio.h>

#define INDEX 10001

int main()
{
    int n, i, j, k;
    int arr[INDEX] = {0,};

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &k);
        arr[k] = arr[k] + 1;
    }

    for(i = 0; i < INDEX; i++)
    {
        if(arr[i] != 0)
        {
            for(j = 0; j < arr[i] ; j++)
            {
                printf("%d\n",i);
            }
        }
    }
}

