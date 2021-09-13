/**
 *  The ready queue will implement a max heap, so we need all the heap functions 
*/

#include "PCB.h"
#include "MaxHeap.h"

class ReadyQueue{

public:
    ReadyQueue();
    ~ReadyQueue();  

    MaxHeap * processMaxHeap; //heap is going to be used in ReadyQueue to enable us to easily extract highest prio

    void addPCB(PCB& process);
    PCB* removePCB(); //should remove highest prio, or top of heap

    int size();
    void display();
};