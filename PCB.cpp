#include "PCB.h"

//Default deconstructor for PCB objects
PCB::~PCB() {

}

//Default construtor for PCB
PCB::PCB() {
    id = 0;
    prio = 0;
    state = NEW;
}

//Parameterized constructor for PCB objects
PCB::PCB(int id, int prio, processStates state) {
    this->id = id;
    this->prio = prio;
    this->state = state;
}

//PCB 'getters and setters' to facilitate creation/update of PCB
void PCB::setID(int id) {
    this->id = id;
}

void PCB::setPrio(int prio) {
    this->prio = prio;
}

void PCB::setState(processStates state) {
    this->state = state;
}

int PCB::getID() {
    return this->id;
}

int PCB::getPrio() {
    return this->prio;
}

processStates PCB::getState() {
    return this->state;
}

void PCB::display() {
    cout << "PCB ID:" << this->getID() << " /// " << "Priority: " << this->getPrio() << " /// " << "State: " << this->getState() << endl;
}