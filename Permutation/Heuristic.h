/*
 * Heuristic.h
 *
 *  Created on: Aug 17, 2017
 *      Author: baekhg
 */

#ifndef HEURISTIC_H_
#define HEURISTIC_H_

#include "Array.h"

typedef struct _Heuristic Heuristic;
struct _Heuristic
{
    Array *ori_bucket;
    Array *out_bucket;
};

Heuristic *MakeInitHeuristic(Array *bucket);
void DeleteHeuristic(Heuristic *now);
void FindNextHerustics(Heuristic *now, Array *next_heus);
int GetOutCount(Heuristic *now);
void ViewHeuristic(Heuristic *now);



#endif /* HEURISTIC_H_ */
