/*
 * sortofnumber.cpp
 *
 * Q. N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
 Input: 첫째 줄에 수의 개수 N(1<=N<=1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 
 이 수는 절대값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.
 ex)
5
5
2
3
4
1
 Output: 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
ex)
1
2
3
4
5
 
 *  Created on: Jul 26, 2017
 *      Author: baekhg
 */


#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int* numbers, int size);

int main()
{
    int inputNum = 0;
    scanf("%d", &inputNum);
    fflush(stdin);

    if(inputNum < 1 || inputNum > 1000)
    {
        return 0;
    }

    int* numbers = (int*)malloc(sizeof(int) * inputNum);
    int i = 0;
    for(i = 0; i < inputNum ; i++)
    {
        scanf("%d",&numbers[i]);
    }

    bubble_sort(numbers, inputNum);

    for(i = 0; i < inputNum ; i++)
    {
        printf("%d\n",numbers[i]);
    }

    free(numbers);

    return 0;
}

void bubble_sort(int* numbers, int size)
{
    int i = 0, j = 0;
    int max_size = size - 1;
    for(i = 0; i < size; ++i)
    {
        for(j = 0; j < max_size - i; ++j)
        {
            if(numbers[j] <= numbers[j+1])
            {
                continue;
            }

            int temp = numbers[j];
            numbers[j] = numbers[j+1];
            numbers[j+1] = temp;
        }
    }
}
