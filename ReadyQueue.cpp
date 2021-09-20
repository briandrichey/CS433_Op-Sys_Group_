#include "ReadyQueue.h"

//Default deconstructor
ReadyQueue::~ReadyQueue() {  }

//Creating the ReadyQueue will invoke creation of a new MaxHeap
ReadyQueue::ReadyQueue() {
    processMaxHeap = new MaxHeap();
}

//Takes a PCB address as parameter, sets processState to READY, and invokes the insert() function from MaxHeap
void ReadyQueue::addPCB(PCB& process) {
    process.setState(READY);

    processMaxHeap->insert(process);
}

//Returns a pointer to PCB, invokes getMax() function from MaxHeap
PCB* ReadyQueue::removePCB() {
    return processMaxHeap->getMax();
}

//Simply calls MaxHeap getSize() function and returns it
int ReadyQueue::size() {
    return processMaxHeap->getSize();
}

//Displaying the whole PCB ReadyQueue will display all READY processes
void ReadyQueue::display() {
    processMaxHeap->display();
}