#include "ReadyQueue.h"
#include <time.h>

//First Test: Tests the creation and removal of PCB into/out of the ReadyQueue. Also uses the display function to output the entire contents of the ReadyQueue
void test1() {
	ReadyQueue q1;

	PCB testPCB(15, 15, NEW);
	PCB testPCB2(6, 6, NEW);
	PCB testPCB3(23, 23, NEW);
	PCB testPCB4(39, 39, NEW);
	PCB testPCB5(8, 8, NEW);


	q1.addPCB(testPCB);
	q1.addPCB(testPCB2);
	q1.addPCB(testPCB3);
	q1.addPCB(testPCB4);
	q1.addPCB(testPCB5);
	q1.removePCB();
	q1.display();


	PCB testPCB6(47, 47, NEW);
	PCB testPCB7(1, 1, NEW);
	PCB testPCB8(37, 37, NEW);
	PCB testPCB9(5, 5, NEW);

	q1.addPCB(testPCB6);
	q1.addPCB(testPCB7);
	q1.addPCB(testPCB8);
	q1.addPCB(testPCB9);
	q1.removePCB();
	q1.display();

	PCB testPCB10(43, 43, NEW);
	PCB testPCB11(17, 17, NEW);
	PCB testPCB12(32, 32, NEW);
	PCB testPCB13(12, 12, NEW);
	PCB testPCB14(19, 19, NEW);

	q1.addPCB(testPCB10);
	q1.addPCB(testPCB11);
	q1.addPCB(testPCB12);
	q1.addPCB(testPCB13);
	q1.addPCB(testPCB14);

	while (q1.size() != 0) {
		q1.removePCB();
	}
}

//Second Test: Tests the execution speed of the program. We use a coin flip type method for determining if we should try to add or remove from queue.
void test2() {
	ReadyQueue q2;

	for (int i = 0; i < 100; i++) {
		int randomPrio = rand() % 50;
		PCB tempPCB(i, randomPrio, NEW);
		q2.addPCB(tempPCB);
	}

	int uniqueID = 100; 
	for (int i = 0; i < 1000000; i++) {

		int coinFlip = rand() % 2 + 1;


		if (coinFlip == 1) { //add a pcb
			int randomPrio = rand() % 50;
			PCB tempPCB(++uniqueID, randomPrio, NEW);
			q2.addPCB(tempPCB);
		}
		else if (coinFlip == 2) { //remove a pcb
			q2.removePCB();
		}
	}
}

//used this resource ->(https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/)<- to help with timing the tests
//main will just call the test1() and test2() to make main a little cleaner
int main() {

	cout << "/////Project Members: Jake Tremblay, Brian Richey, Danny Ha/////" << endl;
	cout << "/////Project emulates processes being entered and run from a priority queue/////" << endl;

	//-------TEST 1---------
	clock_t start, end;
	start = clock();

	test1();

	end = clock();

	double elapsedTime = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Time taken in test 1: " << fixed << elapsedTime;
	cout << " sec " << endl;

	//-------TEST 2---------
	clock_t start2, end2;
	start2 = clock();

	test2();

	end2 = clock();

	double elapsedTime2 = double(end2 - start2) / double(CLOCKS_PER_SEC);
	cout << "Time taken in test 2: " << fixed << elapsedTime2;
	cout << " sec " << endl;

	return 0;
}