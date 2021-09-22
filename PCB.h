#pragma once
#include <iostream>

using namespace std;

enum processStates {
    //different process states for the PCB
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};

class PCB {
    int id;
    int prio;
    processStates state;

public:
    PCB();
    PCB(int id, int prio, processStates state);
    ~PCB();

    void setID(int id);
    int getID();

    void setPrio(int prio);
    int getPrio();

    void setState(processStates state);
    processStates getState();

    void display();
};