#include "PCB.h"

PCB::~PCB() {

}

PCB::PCB() {
    id = 0;
    prio = 0;
    state = NEW;
}

PCB::PCB(int id, int prio, processStates state) {
    this->id = id;
    this->prio = prio;
    this->state = state;
}

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

