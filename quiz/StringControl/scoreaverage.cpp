/*
 * scoreaverage.cpp
 *
 * Q. 상현이가 가르치는 아이폰 앱 개발 수업의 수강생은 원섭, 세희, 상근, 숭, 강수이다.
어제 이 수업의 기말고사가 있었고, 상현이는 지금 학생들의 기말고사 시험지를 채점하고 있다. 
기말고사 점수가 40점 이상인 학생들은 그 점수 그대로 자신의 성적이 된다. 
하지만, 40점 미만인 학생들은 보충학습을 듣는 조건을 수락하면 40점을 받게 된다. 
보충학습은 거부할 수 없기 때문에, 40점 미만인 학생들은 항상 40점을 받게 된다.
학생 5명의 점수가 주어졌을 때, 평균 점수를 구하는 프로그램을 작성하시오.
	
Input: 입력은 총 5줄로 이루어져 있고, 원섭이의 점수, 세희의 점수, 상근이의 점수, 숭이의 점수, 강수의 점수가 순서대로 주어진다.
점수는 모두 0점 이상, 100점 이하인 5의 배수이다. 따라서, 평균 점수는 항상 정수이다. 
ex) 
10
65
100
30
95
Output: 첫째 줄에 학생 5명의 평균 점수를 출력한다.
ex)68

 *  Created on: Jul 26, 2017
 *      Author: baekhg
 */


#include <stdio.h>
#include <string.h>

#define MEMBER 5
#define MIN_SCORE 0
#define MAX_SCORE 100
#define ADJ_SCORE 40

int main()
{
    int inputScore[MEMBER] = {0,};

    int i =0;
    for(i = 0; i < MEMBER; i++)
    {
        scanf("%d",&inputScore[i]);
    }

    for(i = 0; i < MEMBER; i++)
    {
        if(inputScore[i] < MIN_SCORE || inputScore[i] > MAX_SCORE)
        {
            return 0;
        }
    }

    int totalScore = 0;
    int avgScore = 0;

    for(i = 0 ; i < MEMBER; i++)
    {
        if(inputScore[i] < ADJ_SCORE)
        {
            inputScore[i] = ADJ_SCORE;
        }
        totalScore += inputScore[i];
    }

    avgScore = totalScore / MEMBER;

    printf("%d", avgScore);

    return 0;
}

