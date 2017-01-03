//
//  main.cpp
//  PQMinHeap
//
//  Created by Sumanth Sai on 10/13/16.
//  Copyright © 2016 Sumanth Sai. All rights reserved.
//

#include <iostream>
#include "PQMinHeap.h"
#include "SmoothSort.h"
#include <cstdlib>
using namespace std;


//Constructor for PQMinHeap
PQMinHeap::PQMinHeap(){
    heapsize = -1;
}

//Returns the parent of an element
int PQMinHeap::Parent(int p) {
    
    int parent =  max((p+1)/2-1,0);
    return parent;
    
}


//Returns the LeftChild of an element
int PQMinHeap::LeftChild(int l){
    int leftchild = 2*(l+1)-1;
    return leftchild;
    
}


//Returns the RightChild of an element
int PQMinHeap::RightChild(int r){
    int leftchild = 2*(r+1);
    return leftchild;
    
}

//Inserts an Item into the PQ and builds a MinHeap
void PQMinHeap::InsertItem(int key,int value){
    heapsize++;
    BuildMinHeap(heapsize, key, value);
    
}

//Prints the Dictionary
void PQMinHeap::PrintDict(){
    if(heapsize <0){
        cout<<"No Elements in the Queue"<<endl;
        cout<<endl;
        return;
    }
    for(int i =0;i<=heapsize;i++){
        cout<<"["<<PQDict[i].key<<" " <<PQDict[i].value<<"]"<<"   ";
    }
    
}


//Builds the MinHeap
void PQMinHeap::BuildMinHeap(int index,int key, int value){
    
    PQDict[index].key = key;
    PQDict[index].value = value;
    int ParentKey =PQDict[Parent(index)].key;
    int ChildKey =PQDict[index].key;
    while((index>0) && (ParentKey > ChildKey )){
        int str_key,str_value;
        
        //Swapping the parent and the child
        str_key = PQDict[index].key;
        str_value = PQDict[index].value;
        
        PQDict[index].key = PQDict[Parent(index)].key;
        PQDict[index].value = PQDict[Parent(index)].value;
        
        
        PQDict[Parent(index)].key = str_key;
        PQDict[Parent(index)].value = str_value;
        
        
        index = Parent(index);
    }
    
}


//Returns all the Minimum elements
void PQMinHeap::AllMinimum(){
    if(heapsize <0){
        cout<<"No Elements in the Queue"<<endl;
        cout<<endl;
        return;
    }
    
    cout<<"Displaying all the minimum values"<<endl;
    int minkey = PQDict[0].key;
    
    for(int i =0; i<=heapsize;i++){
        
        if(PQDict[i].key == minkey){
            
            cout<<"["<<PQDict[i].key<<" " <<PQDict[i].value<<"]"<<"   ";
            
        }
    }
    cout<<endl;
    
    
}


//Heapifies an unbalanaced heap recursively
void PQMinHeap::Heapify(int i){
    int l = LeftChild(i);
    int r = RightChild(i);
    int least = i;
    
    
    if((l< heapsize) && (PQDict[l].key<PQDict[i].key)){
        least = l;
    }
    
    if(r<heapsize && PQDict[r].key<PQDict[least].key){
        least = r;
    }
    
    if(i != least){
        
        Dictionary temp;
        temp = PQDict[i];
        PQDict[i] = PQDict[least];
        PQDict[least] = temp;
        Heapify(least);
        
    }
}

//Extracts all Minimum values
void PQMinHeap::ExtractAllMinimum(){
    if(heapsize <0){
        cout<<"No Elements in the Queue"<<endl;
        return ;
    }
    
    Dictionary minvalue = {0,0} ;
    
    do{
        
        if(heapsize < 0){
            break;
        }
        
        minvalue = PQDict[0];
        PQDict[0] = PQDict[heapsize];
        heapsize--;
        Heapify(0);
        
        cout<<"["<<minvalue.key<<" " <<minvalue.value<<"]"<<"   ";
        
        
    }while (minvalue.key == PQDict[0].key) ;
    cout<<endl;
}


//Decreases the Priority of random number
void PQMinHeap::DecreaseRandomKey(int newPriority){
    if(heapsize <0){
        cout<<"No Elements in the Queue"<<endl;
        return;
    }
    
    else{
        if(heapsize == 0){
            BuildMinHeap(PQDict[0].key, newPriority, PQDict[0].value);
        }
        
        else{
            int randomNumber = rand()%heapsize;
            
            
            int value = PQDict[randomNumber].value;
            
            BuildMinHeap(randomNumber,newPriority,value);
        }
    }
}

//Returns the MinKey
int PQMinHeap::ReturnAllMinimum(){
    if(heapsize <0){
        cout<<"No Elements in the Queue"<<endl;
        return -1;
    }
    
    int MinKey = PQDict[0].key;
    return MinKey;
    
    
}

//Constructor to Leonardo Number
LeonardoNumber::LeonardoNumber(){
    //Setting up the default values for the Leonardo sequence
    Number =1;
    Next_Number=1;
}


//This method gives difference of the Number and Next_Number
int LeonardoNumber::Difference(){
    int Diff = Number - Next_Number;
    return Diff;
}

//This Method updates the Leonardo Number to the next
LeonardoNumber LeonardoNumber::Increase(){
    
    int reserve;
    reserve = Number;
    Number = Number+Next_Number+1;
    Next_Number = reserve;
    return *this;
}


//This Method updates the Leonardo Number to the previous
LeonardoNumber LeonardoNumber::Decrease(){
    int reserve;
    reserve = Next_Number;
    Next_Number = Number-Next_Number-1;
    Number = reserve;
    return *this;
}

//This method returns the immediate previous element
int LeonardoNumber::NextNumReturn(){
    return Next_Number;
}



//This method maintains the Heap property of the Heap
void LeonardoNumber::Heapify(int *arr,int head, LeonardoNumber l){
    int MaxHead;
    
    //No Need to Heapify a heap less than 3 elements
    if(l.Number <3){
        return;
    }
    //Heapify
    else{
        
        //Recursively calling the function to Heapify
        while(l.Number>=3){
            int p =l.Difference();
            
            //Left Child
            int a1=arr[head- p];
            //Right Child
            int a2 =arr[head-1];
            
            //Finding the Greatest among Left and Right child
            if(a1 >= a2){
                counter++;
                MaxHead = head - l.Difference();
                
            }
            else{
                counter++;
                MaxHead = head-1;
                l.Decrease();
            }
            
            //Making the greatest element Head of the heap
            if(arr[head] >= arr[MaxHead]){
                counter++;
                
                //return;
                break;
            }
            else{
                counter++;
                int reserve;
                reserve = arr[head];
                arr[head] = arr[MaxHead];
                arr[MaxHead]= reserve;
                head = MaxHead;
                l.Decrease();
                
            }
        }
        
        
        return;
        
    }
}


//This Method maintains the Sequence order of the roots by using Insertion sort
void LeonardoNumber::InsertionSortRoots(int* arr,int head,int Adj, LeonardoNumber l){
    while(Adj){
        for(; !(Adj %2);Adj >>=1){
            
            l.Increase();
        }
        
        //Checking if all the Heads are in Ascending Order
        if(!--Adj || (arr[head] >= arr[head - l.Number]))
        {
            counter++;
            //return;
            break;
            
        }
        
        //if Not the heads are choosen and sorted in Ascending Order
        else{
            if(l.Number==1)
            {
                int reserve;
                reserve = arr[head];
                arr[head] = arr[head-l.Number];
                arr[head-l.Number] = reserve;
                head -= l.Number;
            }
            else if( l.Number >=3){
                int LeftChild = head - l.Difference();
                int rightChild = head - l.Number;
                
                if(arr[head - 1] >= arr[LeftChild]){
                    counter++;
                    LeftChild = head -1;
                    Adj<<=1;
                    l.Decrease();
                    
                }
                if(arr[rightChild]>=arr[LeftChild]){
                    counter++;
                    int reserve;
                    reserve = arr[head];
                    arr[head]=arr[rightChild];
                    arr[rightChild] = reserve;
                    head = rightChild;
                }
                
                else{
                    counter++;
                    int reserve;
                    reserve = arr[head];
                    arr[head] = arr[LeftChild];
                    arr[LeftChild] = reserve;
                    head = LeftChild;
                    l.Decrease();
                    //return;
                    break;
                }
            }
            
        }
    }
    
    //Heapifying the Rearranged Heap
    Heapify(arr, head, l);
    
    return;
}

//This Method sorts an Almost sorted array by calling the InsertionSortRoots
void LeonardoNumber::Retrace(int* arr,int head,int Adj,LeonardoNumber k){
    
    if(arr[head - k.NextNumReturn()] >= arr[head]){
        int reserve;
        reserve = arr[head];
        arr[head] = arr[head - k.NextNumReturn()];
        arr[head - k.NextNumReturn()] = reserve;
        InsertionSortRoots(arr, head-k.NextNumReturn(), Adj, k);
    }
    counter++;
    return;
    
}


//The SmoothSort algorithm which sorts a given array by applying smooth sort to it
int* SmoothSort::Sort(int* arr, int length){
    
    LeonardoNumber l;
    int Marker = 1;
    for(int i =0;++i<length;++Marker)
        if(Marker % 8 ==3){
            l.Heapify(arr, i-1, l);
            l.Increase(); l.Increase();
            Marker>>=2;
            
        }
    
        else if(Marker %4 ==1){
            if( i+l.NextNumReturn() < length){
                l.Heapify(arr, i-1, l);
            }
            else{
                l.InsertionSortRoots(arr, i-1, Marker, l);
            }
            for( Marker <<=1; l.Decrease().Number >1;Marker<<=1);
        }
    
    l.InsertionSortRoots(arr, length-1, Marker, l);
    
    
    for(--Marker; length-->1;--Marker){
        if(l.Number ==1){
            counter++;
            for(; !(Marker %2);Marker >>=1) {l.Increase();}
            
        }
        else if (l.Number >=3){
            counter++;
            if(Marker)
            {
                
                // l.InsertionSortRoots(arr, length-l.Difference(), Marker, l);
                l.Retrace(arr, length-l.Difference(), Marker, l);
                
            }
            
            l.Decrease();
            Marker <<=1;
            ++Marker;
            l.Retrace(arr, length-1, Marker, l);
            l.Decrease();
            Marker<<=1;
            ++Marker;
        }
    }
    
    return arr;
    
}


int main(int argc, const char * argv[]) {
    
    
    cout<<"*******TestCase1*******"<<endl;
    cout<<endl;
    PQMinHeap p;
    cout<<"Inserting [100 1] [99 2] ... [1 100] into the PQ"<<endl;
    cout<<endl;
    for(int i =1, j=100;i <=100;i++,j--){
        
        p.InsertItem(j,i);
        
    }
    
    
    p.AllMinimum();
    cout<<endl;
    cout<<"Extracting out all the Minimum Values"<<endl;
    p.ExtractAllMinimum();
    cout<<endl;
    cout<<"After Extracting the minimum value from PQ"<<endl;
    p.AllMinimum();
    cout<<"Inserting [1,0] to the PQ"<<endl;
    p.InsertItem(1,0);
    
    p.AllMinimum();
    
    cout<<endl;
    cout<<"*******TestCase2*******"<<endl;
    cout<<endl;
    
    PQMinHeap q;
    cout<<"Inserting [1000 1] [999 2] ... [1 1000] into the PQ"<<endl;
    for(int i =1, j=1000;i <=1000;i++){
        
        q.InsertItem(j,i);
        j--;
    }
    cout<<endl;
    q.AllMinimum();
    cout<<endl;
    cout<<"Inserting [1 1] [1 2] ... [1 30] into the PQ"<<endl;
    for(int i =1;i <=30;i++){
        
        q.InsertItem(1,i);
        
    }
    cout<<"Extracting out all the Minimum Values"<<endl;
    cout<<endl;
    q.ExtractAllMinimum();
    cout<<endl;
    q.AllMinimum();
    
    cout<<endl;
    cout<<"*******TestCase3*******"<<endl;
    cout<<endl;
    
    PQMinHeap r;
    cout<<"Inserting 500 randomly generated data items to PQ."<<endl;
    cout<<endl;
    for(int counter = 1;counter <=500;counter++){
        int i = 10+(rand()%1010);
        int j = 10+(rand()%1010);
        
        r.InsertItem(i,j);
        
    }
    cout<<"Applying Extra-all-min operation to PQ 5 times,"<<endl;
    cout<<endl;
    for(int i =1;i<=5;i++){
        
        r.ExtractAllMinimum();
        cout<<endl;
    }
    cout<<endl;
    cout<<"Randomly selecting a data item from the PQ. Decrease the key value to 5"<<endl;
    r.DecreaseRandomKey(5);
    cout<<endl;
    r.AllMinimum();
    
    
    cout<<endl;
    cout<<"*******TestCase4*******"<<endl;
    cout<<endl;
    PQMinHeap s;
    
    cout<<"Inserting 500 randomly generated data items to PQ."<<endl;
    cout<<endl;
    for(int counter = 1;counter <=500;counter++){
        int i = 10+(rand()%1010);
        int j = 10+(rand()%1010);
        
        s.InsertItem(i,j);
        
    }
    cout<<"Decreasing the Priority 10 times to a random value which is between 0 to 9"<<endl;
    for(int i =1; i<=10;i++){
        int r =rand() %10;
        
        s.DecreaseRandomKey(r);
    }
    cout<<"Performing ExtractAllMinimum operation 10 times"<<endl;
    for(int i =1; i<=10;i++){
        
        s.ExtractAllMinimum();
    }
    
    cout<<endl;
    cout<<"*******TestCase5*******"<<endl;
    cout<<endl;
    PQMinHeap t;
    
    for(int i =1;i<=100;i++){
        if(i%20 ==0){
            
            cout<<endl;
            cout<<"Completion of 20 operations..."<<endl;
            cout<<"The Queue is now:"<<endl;
            t.PrintDict();
            
        }
        cout<<endl;
        cout<<endl;
        
        
        int randomOperation = (rand()%4);
        
        switch (randomOperation) {
            case 0:
                cout<<"Insert Operation"<<endl;
                
                t.InsertItem(rand()%10, rand()%100);
                cout<<endl;
                break;
                
            case 1:
                cout<<"ExtractAllOperation"<<endl;
                t.ExtractAllMinimum();
                cout<<endl;
                break;
                
                
            case 2:
                cout<<"AllMinimum Operation"<<endl;
                t.AllMinimum();
                cout<<endl;
                break;
                
            case 3:
                
                cout<<"DecreaseRandomKey Operation"<<endl;
                
                
                int MinKey = t.ReturnAllMinimum();
                if(MinKey != -1){
                    t.DecreaseRandomKey(MinKey-1);
                }
                cout<<endl;
                break;
                
         
        }
   
        
    }
    
    
    //Smooth sort Testcases
    cout<<"*******TestCase6*******"<<endl;
    cout<<endl;
    SmoothSort a;
    int A[10000] = {};
    int *SAArrayPoint,*LeoNumber1;
    for(int i = 1000,j=0;i>=1;i--,j++){
        
        // i = rand()%2000;
        A[j] =i;
        
    }
    SAArrayPoint = A;
    counter =0;
    
    
    cout<<"Array A has elements [1000; 999; 998; :::; 1]"<<endl;
    cout<<"Applying Smoothsort to Array A..."<<endl;
    LeoNumber1 = a.Sort(SAArrayPoint, 1000);
    cout<<endl;
    cout<<"A Sorted shortened listing of elements of A"<<endl;
    cout<<endl;
    for(int i =0;i<50;i++){
        cout<<(*LeoNumber1)<<"   ";
        //LeoNumber++;
        LeoNumber1=LeoNumber1+20;
    }
    cout<<endl;
    cout<<endl;
    cout<<"The total number of comparisons among elements in A performed = ";
    cout<<counter<<endl;
    
    cout<<"*******TestCase7*******"<<endl;
    cout<<endl;
    SmoothSort b;
    int B[10000] = {};
    int *SBArrayPoint,*LeoNumber2;
    cout<<"Array A has elements [1; 2; 3; :::; 2000]"<<endl;
    for(int i = 1,j=0;i<=2000;i++,j++){
        
        B[j] =i;
        
    }
    cout<<"Swapping 20 random elements..."<<endl;
    for(int i =0;i<20;i++){
        
        int reserve;
        int randomindex = rand()%2000;
        reserve = B[randomindex];
        B[randomindex] = B[randomindex +1];
        B[randomindex+1] = reserve;
        
    }
    SBArrayPoint = B;
    counter =0;
    cout<<"Applying Smoothsort to Array A..."<<endl;
    LeoNumber2 = b.Sort(SBArrayPoint, 2000);
    cout<<endl;
    cout<<"A Sorted shortened listing of elements of A"<<endl;
    cout<<endl;
    for(int i =0;i<100;i++){
        cout<<(*LeoNumber2)<<"   ";
        //LeoNumber++;
        LeoNumber2=LeoNumber2+20;
    }
    
    
    cout<<endl;
    cout<<endl;
    cout<<"The total number of comparisons among elements in A performed = ";
    cout<<counter<<endl;
    
    //TestCase3
    cout<<"*******TestCase8*******"<<endl;
    cout<<endl;
    SmoothSort u;
    int C[10000] = {};
    int *SCArrayPoint,*LeoNumber3;
    cout<<"Array A has elements [1; 2; 3; :::; 2000]"<<endl;
    for(int i = 1,j=0;i<=2000;i++,j++){
        
        C[j] =i;
        
    }
    cout<<"Permutating 3 elements by choosing a Random Number"<<endl;
    for(int i =0;i<60;i++){
        
        int reserve1;
        int randomindex = rand()%1000;
        reserve1 = C[randomindex];
        C[randomindex] = C[randomindex +2];
        C[randomindex+2] = reserve1;
        
    }
    SCArrayPoint = C;
    counter =0;
    
    
    cout<<"Applying Smoothsort to Array A..."<<endl;
    LeoNumber3 = u.Sort(SCArrayPoint, 2000);
    cout<<endl;
    cout<<"A Sorted shortened listing of elements of A"<<endl;
    cout<<endl;
    for(int i =0;i<100;i++){
        cout<<(*LeoNumber3)<<"   ";
        //LeoNumber++;
        LeoNumber3=LeoNumber3+20;
    }
    cout<<endl;
    cout<<endl;
    cout<<"The total number of comparisons among elements in A performed = ";
    cout<<counter<<endl;
    
    
    
    //TestCase4
    cout<<"*******TestCase9*******"<<endl;
    cout<<endl;
    SmoothSort v;
    int D[3193] = {};
    int *SDArrayPoint,*LeoNumber4;
    cout<<"Array A is of length 3193 and have random numbers "<<endl;
    for(int i = 1;i<=3193;i++){
        int num = 1+rand()%9999;
        D[i] =num;
        
    }
    
    SDArrayPoint = D;
    counter =0;
    
    
    cout<<"Applying Smoothsort to Array A..."<<endl;
    LeoNumber4 = v.Sort(SDArrayPoint, 3193);
    cout<<endl;
    cout<<"A Sorted shortened listing of elements of A"<<endl;
    cout<<endl;
    for(int i =0;i<160;i++){
        cout<<(*LeoNumber4)<<"   ";
        LeoNumber4=LeoNumber4+20;
    }
    cout<<endl;
    cout<<endl;
    cout<<"The total number of comparisons among elements in A performed = ";
    cout<<counter<<endl;
    
    
    
    //TestCase5
    cout<<"*******TestCase10*******"<<endl;
    cout<<endl;
    SmoothSort w;
    int E[5166] = {};
    int *SEArrayPoint,*LeoNumber5;
    cout<<"Array A is of length 5166 and have random numbers "<<endl;
    for(int i = 1;i<=5166;i++){
        int num = 1+rand()%9999;
        E[i] =num;
        
    }
    
    SEArrayPoint = E;
    counter =0;
    
    
    cout<<"Applying Smoothsort to Array A..."<<endl;
    LeoNumber5 = w.Sort(SEArrayPoint, 5166);
    cout<<endl;
    cout<<"A Sorted shortened listing of elements of A"<<endl;
    cout<<endl;
    for(int i =0;i<258;i++){
        cout<<(*LeoNumber5)<<"   ";
        LeoNumber5=LeoNumber5+20;
    }
    cout<<endl;
    cout<<endl;
    cout<<"The total number of comparisons among elements in A performed = ";
    cout<<counter<<endl;
    cout<<endl;
    
    return 0;
}
