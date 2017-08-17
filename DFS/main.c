/*
 * main.c
 *
 *  Created on: Aug 17, 2017
 *      Author: baekhg
 */

#include "Graph.h"
#include "EnhancedStack.h"
#include "Heuristic.h"

Graph *InitSimulation()
{
    Graph *graph = New_Graph();

    Graph_AddVertex(graph, "A");
    Graph_AddVertex(graph, "B");
    Graph_AddVertex(graph, "C");
    Graph_AddVertex(graph, "D");
    Graph_AddVertex(graph, "E");
    Graph_AddVertex(graph, "F");
    Graph_AddVertex(graph, "G");
    Graph_AddVertex(graph, "H");

    Graph_AddEdge(graph, "A", "B", 5);
    Graph_AddEdge(graph, "A", "D", 4);
    Graph_AddEdge(graph, "A", "E", 4);
    Graph_AddEdge(graph, "B", "D", 4);
    Graph_AddEdge(graph, "B", "H", 2);
    Graph_AddEdge(graph, "C", "D", 2);
    Graph_AddEdge(graph, "C", "G", 3);
    Graph_AddEdge(graph, "D", "H", 5);
    Graph_AddEdge(graph, "D", "E", 5);
    Graph_AddEdge(graph, "D", "F", 3);
    Graph_AddEdge(graph, "E", "F", 3);
    Graph_AddEdge(graph, "F", "G", 6);
    Graph_AddEdge(graph, "G", "H", 3);

    Graph_View(graph);
    return graph;
}

int main()
{
    EHStack *ehs = 0;
    Heuristic *heu = 0;
    Graph *graph = 0;
    Array *next_heus = 0;
    Iterator seek=0, end=0;

    graph = InitSimulation();
    ehs = New_EHStack();
    heu = MakeInitHeuristic(graph, "A", "H");
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
            if(IsGoal(heu))
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

    Delete_Graph(graph);
    Delete_EHStack(ehs);

    return 0;
}

