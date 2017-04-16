#ifndef _FTC_H_
#define _FTC_H_

#include "HistList.h"

#ifndef MIN 
#define MIN(a,b) ((a)<(b)?(a):(b)) 
#endif
#ifndef MAX 
#define MAX(a,b) ((a)>(b)?(a):(b))
#endif

// calculate the entrop of "x" and "y"
double entrop(double x, double y);

// pav algorithm
// "c" = 1 for the increasing hypothesis, 0 for the decreasing one
// "in" is the input list
// "out" is the output list which has been manipulated by pav algorithm.
void pooling_adjacent_violators(bool bInc, CHistList& in, CHistList& out);

// find the max entrop at interval [a,b] of input list "in".
// "eps" is the parameter of precision.
// "c" = 1 for the increasing hypothesis, 0 for the decreasing one
double max_entropy(bool bInc, CHistList& in, int a, int b, double eps);

// the merge process
// "in" is the input list.
// "eps" is the parameter of precision.
// "list" is the list with extrema.
// "jseg" is the length of step in merging process.
void merge(CHistList& in, float eps, CHistList& list, int jseg);

// Get the list "out",which containing maxima and minma(begin from minima) of list "in"
void GetLocalMinMax(CHistList& in, CHistList& out);

// ftc algorithm
// "eps" is the parameter of precision.
// "in" is the input list
// "out" is the output list which has been manipulated by ftc algorithm.
void FTCSegment(float eps, CHistList& in, CHistList& out);
#endif