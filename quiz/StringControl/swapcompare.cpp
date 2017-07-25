/*
 * swapcompare.cpp
 *
 * Q. 상근이의 동생 상수는 수학을 정말 못한다. 상수는 숫자를 읽는데 문제가 있다. 
 이렇게 수학을 못하는 상수를 위해서 상근이는 수의 크기를 비교하는 문제를 내주었다. 
 상근이는 세 자리 숫자 두 개를 칠판에 써주었다. 그 다음에 크기가 큰 수를 말해보라고 했다.
상수는 수를 다른사람과 다르게 거꾸로 읽는다. 
예를 들어, 734과 893을 칠판에 적었다면, 상수는 이 수를 437과 398로 읽는다. 
따라서, 상수는 두 수중 큰 수인 437을 큰 수라고 말할 것이다.
두 수가 주어졌을 때, 상수의 대답을 출력하는 프로그램을 작성하시오.
 *
 * Input: 첫째 줄에 상근이가 칠판에 적은 두 수 A와 B가 주어진다. 두 수는 같지 않은 세 자리 수이며, 0이 포함되어 있지 않다.
 * ex)734 893
 * Output: 첫째 줄에 상수의 대답을 출력한다.
 * ex)437
 *
 *  Created on: Jul 25, 2017
 *      Author: baekhg
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap_string(char* str, int str_size)
{
    char* temp_str = (char*)malloc(sizeof(char)*str_size);

    int i = 0;
    for(; i < str_size; i++)
    {
        temp_str[i] = str[i];
    }

    i = 0;
    for(; i < str_size; i++)
    {
        str[i] = temp_str[str_size-i-1];
    }


    free(temp_str);

}


int main()
{
    int num1 = 0;
    int num2 = 0;

    scanf("%d %d", &num1, &num2);

    int digit1 = 0, digit2 =0;
    int temp_num = num1;
    while(temp_num != 0)
    {
        digit1++;
        temp_num /= 10;
    }
    temp_num = num2;
    while(temp_num != 0)
    {
        digit2++;
        temp_num /= 10;
    }

    char *num1_string = (char*)malloc(sizeof(char)*(digit1+1));
    char *num2_string = (char*)malloc(sizeof(char)*(digit2+1));

    //Linux or some compiler not support itoa function.
    sprintf(num1_string, "%d" , num1);
    sprintf(num2_string, "%d" , num2);

//    printf("sizeofnum1 [%d], sizeofnum2[%d]\n",strlen(num1_string),strlen(num2_string));

    swap_string(num1_string, digit1);
    swap_string(num2_string, digit2);

//    printf("num1_string [%s], num2_string[%s]\n",num1_string, num2_string);

    int swap_num1 = atoi(num1_string);
    int swap_num2 = atoi(num2_string);

    if(swap_num1 > swap_num2)
    {
        printf("%d",swap_num1);
    }
    else
    {
        printf("%d",swap_num2);
    }

    free(num1_string);
    free(num2_string);

    return 0;
}

