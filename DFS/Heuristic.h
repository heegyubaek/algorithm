/*
 * Heuristic.h
 *
 *  Created on: Aug 17, 2017
 *      Author: baekhg
 */

#ifndef HEURISTIC_H_
#define HEURISTIC_H_

#include "Array.h"
#include "Graph.h"

typedef struct _Heuristic Heuristic;
struct _Heuristic
{
    Array *exprs;
    Graph *graph;
    Vertex start;
    Vertex goal;
    int total_weight;
};

Heuristic *MakeInitHeuristic(Graph *graph, Vertex start, Vertex goal);
void DeleteHeuristic(Heuristic *now);
void FindNextHerustics(Heuristic *now, Array *next_heus);
Vertex GetLastVertex(Heuristic *now);
int IsGoal(Heuristic *now);
void ViewHeuristic(Heuristic *now);



#endif /* HEURISTIC_H_ */
