/*
 * Heuristic.c
 *
 *  Created on: Aug 17, 2017
 *      Author: baekhg
 */

#include "Heuristic.h"
#include <malloc.h>
#include <stdio.h>

Heuristic *MakeNextHeu(Heuristic *now, int ball)
{
    Heuristic *heu = 0;
    Iterator seek = 0, end = 0;

    heu = (Heuristic *)malloc(sizeof(Heuristic));
    heu->ori_bucket = New_Array();
    heu->out_bucket = New_Array();

    seek = Array_Begin(now->out_bucket);
    end = Array_End(now->out_bucket);
    for( ; seek != end; ++seek)
    {
        Array_PushBack(heu->out_bucket, *seek);
    }

    seek = Array_Begin(now->ori_bucket);
    end = Array_End(now->ori_bucket);
    for( ; seek != end; ++seek)
    {
        if((int)(*seek) == ball)
        {
            Array_PushBack(heu->out_bucket, *seek);
        }
        else
        {
            Array_PushBack(heu->ori_bucket, *seek);
        }
    }

    return heu;
}

Heuristic *MakeInitHeuristic(Array *bucket)
{
    Heuristic *heu = 0;
    Iterator seek = 0, end = 0;
    heu = (Heuristic *)malloc(sizeof(Heuristic));
    heu->ori_bucket = New_Array();
    heu->out_bucket = New_Array();

    seek = Array_Begin(bucket);
    end = Array_End(bucket);

    for( ; seek != end; ++seek)
    {
        Array_PushBack(heu->ori_bucket, *seek);
    }

    return heu;
}

void DeleteHeuristic(Heuristic *now)
{
    Delete_Array(now->ori_bucket);
    Delete_Array(now->out_bucket);
    free(now);
}

void FindNextHeuristics(Heuristic *now, Array *next_heus)
{
    Iterator seek = 0, end = 0;
    Heuristic *next = 0;

    seek = Array_Begin(now->ori_bucket);
    end = Array_End(now->ori_bucket);
    for( ; seek != end; ++seek)
    {
        next = MakeNextHeu(now, (int)*seek);
        Array_PushBack(next_heus, next);
    }
}

int GetOutCount(Heuristic *now)
{
    return now->out_bucket->usage;
}

void ViewHeuristic(Heuristic *now)
{
    Iterator seek = 0, end = 0;
    seek = Array_Begin(now->out_bucket);
    end = Array_End(now->out_bucket);
    for( ; seek != end; ++seek)
    {
        printf("%d ",(int)*seek);
    }
    printf("\n");
}


