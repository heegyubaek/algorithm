/*
 * Heuristic.c
 *
 *  Created on: Aug 17, 2017
 *      Author: baekhg
 */

#include "Heuristic.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>

int IsExistVertex(Heuristic *now, Vertex vt)
{
    Iterator seek=0, end=0;
    Vertex expr_vt;

    seek = Array_Begin(now->exprs);
    end = Array_End(now->exprs);

    for( ; seek != end; ++seek)
    {
        expr_vt = (Vertex)(*seek);
        if(strcmp(expr_vt, vt) == 0)
        {
            return 1;
        }
    }

    return 0;
}

Heuristic *MakeNextHeu(Heuristic *now, Vertex vt)
{
    Heuristic *heu = 0;
    Iterator seek = 0, end = 0;
    Vertex expr_vt;

    heu = MakeInitHeuristic(now->graph, now->start, now->goal);
    seek = Array_Begin(now->exprs);
    end = Array_End(now->exprs);
    expr_vt = (Vertex)(*seek);

    for( ; seek != end; ++seek)
    {
        expr_vt = (Vertex)(*seek);
        Array_PushBack(heu->exprs, (Element)expr_vt);
    }

    heu->total_weight = now->total_weight;
    heu->total_weight += Graph_GetWeight(heu->graph, expr_vt, vt);

    Array_PushBack(heu->exprs, (Element)vt);

    return heu;
}

Heuristic *MakeInitHeuristic(Graph *graph, Vertex start, Vertex goal)
{
    Heuristic *heu = 0;
    heu = (Heuristic *)malloc(sizeof(Heuristic));
    heu->exprs = New_Array();
    heu->graph = graph;
    heu->start = start;
    heu->goal = goal;
    Array_PushBack(heu->exprs, (Element)start);
    heu->total_weight = 0;

    return heu;
}

void DeleteHeuristic(Heuristic *now)
{
    Delete_Array(now->exprs);
    free(now);
}

void FindNextHeuristics(Heuristic *now, Array *next_heus)
{
    Array *next_vts = 0;
    Iterator seek = 0, end = 0;
    Vertex next_vt;
    Heuristic *next = 0;

    next_vts = New_Array();
    Graph_FindNeighbor(now->graph, GetLastVertex(now), next_vts);

    seek = Array_Begin(next_vts);
    end = Array_End(next_vts);
    for( ; seek != end; ++seek)
    {
        next_vt = (Vertex)(*seek);
        if(!IsExistVertex(now, next_vt))
        {
            next = MakeNextHeu(now, next_vt);
            Array_PushBack(next_heus, next);
        }
    }
}

Vertex GetLastVertex(Heuristic *now)
{
    Iterator end = Array_End(now->exprs);
    --end;

    return (Vertex)(*end);
}

int IsGoal(Heuristic *now)
{
    return strcmp(now->goal, GetLastVertex(now))==0;
}


void ViewHeuristic(Heuristic *now)
{
    Iterator seek = 0, end = 0;

    printf("Total distance:%d ",now->total_weight);
    seek = Array_Begin(now->exprs);
    end = Array_End(now->exprs);
    for( ; seek != end; ++seek)
    {
        printf("%s ",(Vertex)*seek);
    }
    printf("\n");
}


