/*
 * scale.cpp
 *
 * Q. 다장조는 c d e f g a b C, 총 8개 음으로 이루어져있다. 
 이 문제에서 8개 음은 다음과 같이 숫자로 바꾸어 표현한다. c는 1로, d는 2로, ..., C를 8로 바꾼다.
 1부터 8까지 차례대로 연주한다면 ascending, 8부터 1까지 차례대로 연주한다면 descending, 둘 다 아니라면 mixed 이다.
 연주한 순서가 주어졌을 때, 이것이 ascending인지, descending인지, 아니면 mixed인지 판별하는 프로그램을 작성하시오.
 
 Input: 첫째 줄에 8개 숫자가 주어진다. 이 숫자는 문제 설명에서 설명한 음이며, 1부터 8까지 숫자가 한 번씩 등장한다.
 ex)1 2 3 4 5 6 7 8
 Output: 첫째 줄에 ascending, descending, mixed 중 하나를 출력한다.
 ex)ascending
 
 *  Created on: Jul 26, 2017
 *      Author: baekhg
 */


#include <stdio.h>
#include <string.h>

#define MAX_SCALE 8


int main()
{
    char scale[MAX_SCALE] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    char inputString[MAX_SCALE*2] = {0,};
    char inputScale[MAX_SCALE] = {0,};

    scanf("%[^\n]s", inputString);
    fflush(stdin);

//    printf("%s\n",inputString);

    int i = 0;
    char* pch = strtok(inputString, " ");
    while(pch != NULL)
    {
        inputScale[i] = *pch;
//        printf("%s\n",pch);
        pch = strtok(NULL, " ");
        i++;
    }

//    printf("%s\n",inputScale);

    int flag = 0;
    for(i = 0; i < MAX_SCALE; i++)
    {
        if(scale[i] == inputScale[i])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }

    if(flag != 1)
    {
        for(i = 0; i < MAX_SCALE; i++)
        {
            if(scale[MAX_SCALE-1-i] == inputScale[i])
            {
                flag = 2;
            }
            else
            {
                flag = 0;
                break;
            }
        }
    }

    if(flag == 1)
    {
        printf("ascending");
    }
    else if(flag == 2)
    {
        printf("descending");
    }
    else
    {
        printf("mixed");
    }


    return 0;
}

