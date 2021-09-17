#include "MaxHeap.h"
#include "ReadyQueue.h"


MaxHeap::MaxHeap(){
    size = 0;
}

int MaxHeap::getSize(){
    return size;
}

bool MaxHeap::isLeaf(int i){
    return (i < size/2) ? false : true; 
}

void MaxHeap::siftDown(int i){
    while(!isLeaf(i)){
        int leftIndex = (2 * i) + 1;
        int rightIndex = (2 * i) + 2;
        int larger = leftIndex;

        if(rightIndex < size){
            larger = (processList[leftIndex] < processList[rightIndex]) ? rightIndex : leftIndex;
        }
        if(processList[i] >= processList[larger]){
            break;
        }
        swap(*processList[i], *processList[larger]);
        i = larger;
    }
}

void MaxHeap::siftUp(int i){
    int parentIndex = (i - 1) / 2;

    while(i > 0 && processList[parentIndex]->getPrio() > processList[i]->getPrio()){
        swap(*processList[i], *processList[parentIndex]);
        i = parentIndex;
    }
}

void MaxHeap::display(){
    //remember we need to print out a header with our info on it
        for(int i = 0; i<processList.size();i++){
            proccessList[i].display();
        }
            
}

PCB* MaxHeap::getMax(){
    return processList[0];
}

void MaxHeap::swap(PCB& a, PCB& b){
    PCB temp = b;
    b = a;
    a = temp;
}

void MaxHeap::insert(PCB& process){
    //need to follow older code from cs311 - asgn 4
}
