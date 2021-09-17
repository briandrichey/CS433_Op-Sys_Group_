#include "ReadyQueue.h"
#include <time.h>

//we should make a small helper function to automate the creation of all the PCB stuff, especially for the 1000000 test

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


void test2() {
	ReadyQueue q2;

	for (int i = 0; i < 100; i++) {
		int randomPrio = rand() % 50;
		PCB tempPCB(i, randomPrio, NEW);
		q2.addPCB(tempPCB);
	}

	int uniqueID = 100;
	for (int i = 0; i < 1000000; i++) {

		int coinFlip = rand() % 2;
		

		if (coinFlip == 1) { //add
			int randomPrio = rand() % 50;
			PCB tempPCB(++uniqueID, randomPrio, NEW);
			q2.addPCB(tempPCB); 
		} else if (coinFlip == 2) { //remove
			q2.removePCB();    
		}
	}
}
//used geeksforgeeks code to help with timing the code
int main() {
	clock_t start, end;

	start = clock();

	test1();

	end = clock();

	double elapsedTime = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Time taken: " << fixed << elapsedTime;
	cout << " sec " << endl;

	///test 2
	clock_t start2, end2;
	start2 = clock();

	test2();

	end2 = clock();

	double elapsedTime2 = double(end2 - start2) / double(CLOCKS_PER_SEC);
	cout << "Time taken in test 2: " << fixed << elapsedTime2;


	return 0;
}