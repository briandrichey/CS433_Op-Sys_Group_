#include "PCB.h"

PCB::~PCB(){
    
}

PCB::PCB(){
    id = 0;
    prio = 0;
    state = NEW;
}

PCB::PCB(int id, int prio, processStates state){
    this->id = id;
    this->prio = prio;
    this->state = state;
}

void PCB::setID(int id){
    this->id = id;
}

void PCB::setPrio(int prio){
    this->prio = prio;
}

void PCB::setState(processStates state){
    this->state = state;
}

int PCB::getID(){
    return this->id;
}

int PCB::getPrio(){
    return this->prio;
}

processStates PCB::getState(){
    return this->state;
}

void PCB::display(){
    int pId,pPrio;
    processStates pState;
    
    pID = getID();
    pPrio= getPrio();
    pState= getState();
    
    cout << "PCB ID:"<< pID <<" /// "<< "Priority: " << pPrio <<" /// "<< "State: " << pState <<endl;   
}
   
        

