#include "MaxHeap.h"
#include "ReadyQueue.h"

//Default constructor, sets size of heap to 0
MaxHeap::MaxHeap() {
    size = 0;
}

//Returns size of heap
int MaxHeap::getSize() {
    return size;
}

//Checks if the current index i is the index of a leaf node in our heap, if an index i is equal to half the size of the heap, that node is a leaf
bool MaxHeap::isLeaf(int i) {
    return (i < size / 2) ? false : true;
}

//Sift down uses the root (or in our case just index 0) and will test it against its children to see if it needs to go sift 'downwards' in the heap
void MaxHeap::siftDown(int i) {
    while (!isLeaf(i)) {
        int leftIndex = (2 * i) + 1;
        int rightIndex = (2 * i) + 2;
        int larger = leftIndex;

        if (rightIndex < size) {
            larger = (processList[leftIndex]->getPrio() < processList[rightIndex]->getPrio()) ? rightIndex : leftIndex;
        }
        if (processList[i]->getPrio() >= processList[larger]->getPrio()) {
            break;
        }

        swap(*processList[i], *processList[larger]);
        i = larger;
    }
}

//Sift up will normally use index i = size and sift the node up the heap to proper position, similar to siftDown
void MaxHeap::siftUp(int i) {
    int parentIndex = (i - 1) / 2;

    while (i > 0 && processList[parentIndex]->getPrio() < processList[i]->getPrio()) {
        swap(*processList[i], *processList[parentIndex]);
        i = parentIndex;
        parentIndex = (i - 1) / 2;
    }
}

//Display all elements currently within the readyQueue
void MaxHeap::display() {
    cout << "### Displaying ReadyQueue ###" << endl;
    for (int i = 0; i < processList.size() && processList[i] != NULL; i++) {
        processList[i]->display();
    }
}

//getMax returns a PCB pointer that is the highest priority process in the heap, or just the first element
PCB* MaxHeap::getMax() {
    if (size <= 0) {
        return NULL;
    }

    PCB* target = processList[0];
    target->setState(RUNNING);

    processList[0] = processList[--size];
    processList.pop_back();
    siftDown(0);

    return target;
}

//simply swap the address of PCB a and PCB b
void MaxHeap::swap(PCB& a, PCB& b) {
    PCB temp = b;
    b = a;
    a = temp;
}

//inserts PCB address into the processList vector<PCB&> and invokes the siftUp on i = size
void MaxHeap::insert(PCB& process) {
    processList.push_back(&process);
    int i = size;
    siftUp(i);
    size++;
}