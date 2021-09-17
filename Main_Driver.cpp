#include <iostream>
#include <math> //????
#include "ReadyQueue.h"
using namespace std; 

int main{

ReadyQueue q1, q2;

q1.size(50);
q2.size(100);
 
 cout << "Names: Danny Ha, Jake Trembley, Brian Richey" << endl;
 cout << "Short Description: " << endl;

 //--------------Test 1----------------------
 PCB p1 (15,15,NEW);//CREATE 5 PCBs
 PCB p2 (6,6,NEW);
 PCB p3 (23,23,NEW);
 PCB p4 (39,39,NEW);
 PCB p5 (8,8,NEW);
 
q1.add(p1); //fill queue with PCBs (should change state to READY)***
q1.add(p2); //should it be q1.add(15) or q1.add(p1)???????
q1.add(p3);
q1.add(p4);
q1.add(p5);
 
q1.remove(); //should change p2 "6" state to RUNNING ***
q1.display();// displays all except 6
 
 PCB p6 (47,47,NEW); //CREATE 4 more PCBs
 PCB p7 (1,1,NEW);
 PCB p8 (37,37,NEW);
 PCB p9 (5,5,NEW);
 
q1.add(p6);//fill queue with PCBs (should change state to READY)***
q1.add(p7);
q1.add(p8);
q1.add(p9);
 
q1.remove(); //should change p7 "1" state to "RUNNING" ***
q1.display(); // displays all except 1
 
 PCB p10 (43,43,NEW); //CREATE 5 more PCBs
 PCB p11 (17,17,NEW);
 PCB p12 (32,32,NEW);
 PCB p13 (12,12,NEW);
 PCB p14 (19,19,NEW);
 
q1.add(p10);//fill queue with PCBs (should change state to READY)***
q1.add(p11);
q1.add(p12);
q1.add(p13);
 
 for(int = 0; i < q1.size(); i++){ //removes one at a time then displays q1 priority queue
  q1.remove();
  q1.display();
 }

 


  
  //-------------Test 2-------------------
for(int i=0; i<100; i++){
  int num = rand(23) % 50;
  q2.add(num);
  }
 for(int i=0; i<1000000; i++){
   int num = rand(23) % 50;
  q2.add(num);
 }
  
