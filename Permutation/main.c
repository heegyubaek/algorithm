/*
 * main.c
 *
 *  Created on: Aug 17, 2017
 *      Author: baekhg
 */


#include "EnhancedStack.h"
#include "Heuristic.h"

Array *InitSimulation()
{
    int ball = 0;
    Array *bucket = 0;

    bucket = New_Array();
    for(ball = 0; ball <= 9; ++ball)
    {
        Array_PushBack(bucket, (Element)ball);
    }

    return bucket;
}

int main()
{
    EHStack *ehs = 0;
    Heuristic *heu = 0;
    Array *bucket = 0;
    Array *next_heus = 0;
    Iterator seek = 0, end = 0;

    bucket = InitSimulation();
    ehs = New_EHStack();
    heu = MakeInitHeuristic(bucket);

    EHStack_Push(ehs, heu);

    while(!EHStack_IsEmpty(ehs))
    {
        heu = (Heuristic *)EHStack_Pop(ehs);
        next_heus = New_Array();
        FindNextHeuristics(heu, next_heus);

        seek = Array_Begin(next_heus);
        end = Array_End(next_heus);

        for( ; seek != end; ++seek)
        {
            heu = (Heuristic *)(*seek);
            if(GetOutCount(heu) == 3)
            {
                ViewHeuristic(heu);
                DeleteHeuristic(heu);
            }
            else
            {
                EHStack_Push(ehs, heu);
            }
        }
        Delete_Array(next_heus);
    }

    Delete_Array(bucket);
    Delete_EHStack(ehs);

    return 0;
}



