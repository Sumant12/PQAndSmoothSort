//
//  SmoothSort.h
//  SmoothSort
//
//  Created by Sumanth Sai on 10/24/16.
//  Copyright © 2016 Sumanth Sai. All rights reserved.
//

#ifndef SmoothSort_h
#define SmoothSort_h


int counter;
class LeonardoNumber{
public:
    LeonardoNumber();
    int Difference();
    LeonardoNumber Increase();
    LeonardoNumber Decrease();
    int NextNumReturn();
    void Heapify(int *array,int root, LeonardoNumber l);
    void InsertionSortRoots(int* array,int head,int Adj, LeonardoNumber l);
    void Retrace(int* array,int head, int Adj, LeonardoNumber k);
public:
    int Number;
    int Next_Number;

};

class SmoothSort
{
public:
    int* Sort(int* array, int size);
};

#endif /* SmoothSort_h */
