#include <iostream>
#include <math> //????
#include "ReadyQueue.h"
using namespace std; 

int main{

ReadyQueue q1, q2;

q1.size(50);
q2.size(100);

 //--------------Test 1----------------------
q1.add(15);
q1.add(6);
//.
//.
//.


q1.display();
q1.remove();
//......

  
  //-------------Test 2-------------------
for(int i=0; i<100; i++){
  int num = rand(23) % 50;
  q2.add(num);
  }
