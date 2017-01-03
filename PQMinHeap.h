//
//  PQMinHeap.h
//  PQMinHeap
//
//  Created by Sumanth Sai on 10/13/16.
//  Copyright © 2016 Sumanth Sai. All rights reserved.
//

#ifndef PQMinHeap_h
#define PQMinHeap_h


#endif /* PQMinHeap_h */

class PQMinHeap{
    
    int heapsize;
    
public:
    PQMinHeap();
    struct Dictionary
    {
        int key;
        int value;
    };
    
    Dictionary PQDict[2000];
    
    void InsertItem(int key,int value);
   void BuildMinHeap(int index,int key, int value);
    int Parent(int i);
    void AllMinimum();
    void ExtractAllMinimum();
    void Heapify(int i);
    int LeftChild(int i);
    int RightChild(int i);
    void PrintDict();
    void DecreaseRandomKey(int p);
    int ReturnAllMinimum();
};
