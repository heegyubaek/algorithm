/*
Q. "OOXXOXXOOO"와 같은 OX퀴즈의 결과가 있다. O는 문제를 맞은 것이고, X는 문제를 틀린 것이다. 
문제를 맞은 경우 그 문제의 점수는 그 문제까지 연속된 O의 개수가 된다. 
예를 들어, 10번 문제의 점수는 3이 된다.
"OOXXOXXOOO"의 점수는 1+2+0+0+1+0+0+1+2+3 = 10점이다.
OX퀴즈의 결과가 주어졌을 때, 점수를 구하는 프로그램을 작성하시오.

Input: 첫째 줄에 테스트 케이스의 개수가 주어진다. 
각 테스트 케이스는 한 줄로 이루어져 있고, 길이가 0보다 크고 80보다 작은 문자열이 주어진다. 
문자열은 O와 X만으로 이루어져 있다.
ex)
5
OOXXOXXOOO
OOXXOOXXOO
OXOXOXOXOXOXOX
OOOOOOOOOO
OOOOXOOOOXOOOOX

Output: 각 테스트 케이스마다 점수를 출력한다.
ex)
10
9
7
55
30
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 81

int main()
{
    int line_num = 0;
    scanf("%d", &line_num);
    fflush(stdin);

    char **input_string = (char**)malloc(sizeof(char*) * line_num);
    int i = 0, j = 0;
    for(; i < line_num; i++)
    {
        input_string[i] = (char*)malloc(sizeof(char) * MAX_STRING);
        scanf("%s", input_string[i]);
        fflush(stdin);
    }

    int score = 0;
    int total_score = 0;
    int *score_array = (int*)malloc(sizeof(int) * line_num);

    for(i = 0; i < line_num; i++)
    {
        score = 0;
        total_score = 0;
        for(j = 0; j <= strlen(input_string[i]); j++)
        {
            if(input_string[i][j] == 'O')
            {
                score++;
                total_score += score;
            }
            else
            {
                score = 0;
            }
        }
        score_array[i] = total_score;
        printf("%d\n",score_array[i]);
    }

    return 0;
}
