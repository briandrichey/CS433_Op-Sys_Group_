#include "ReadyQueue.h"

ReadyQueue::~ReadyQueue(){
    //delete heap here
}

ReadyQueue::ReadyQueue(){
    //not sure what to put in ready queue constructor?
    //vector is made in the maxheap.cpp and maxheap is created readyqueue.h
}

void ReadyQueue::addPCB(PCB& process){
    //adding to queue -> stored as heap
    
    process.setState(READY);
    processMaxHeap->insert(process);
    
    int numID = process.getID();
    cout<<"PCB "<< numID <<" added to priority queue."<<endl;

}

//should just be able to call maxheap.extractMax, set state to running,
PCB* ReadyQueue::removePCB(){
    
    cout<<"Highest priority PCB removed from priority queue."<<endl;
    
    return processMaxHeap->getMax();
}

int ReadyQueue::size(){
    return processMaxHeap->getSize(); //return how many process in the queue
}

void ReadyQueue::display(){
    //print the contents of the heap
    processMaxHeap->display();
}

