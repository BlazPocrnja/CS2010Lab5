#include "memory.h"

/*
Author : Blaz Pocrnja 
Student ID : 5035473
Lab #5 
Purpose: Demonstrates the use of the "Memory" class by using its member functions to simulate computer memory.
*/

int main(void){
	
	Memory mem(200);
	int retrieval;	

	for(int i = 0; i < mem.getSize(); i++){
		mem.insert(i,i);
	}
	printf("\n-------------------------Memory Test--------------------------\n");
	printf("\n200 integers have been inserted into Memory from 0 to 199.\n");	
	mem.dump();
	mem.BlockCopy(0,100,99);
	printf("\nThe first 100 integers have been copied into the last 100 locations.\n");
	mem.dump();
	retrieval = mem.retrieve(199);
	printf("\nThe last integer in Memory is");
	printf("%3d",retrieval);
	printf(".\n");
	mem.BlockCopy(190, 10, 9);
	printf("\nThe last ten integers have been copied into location 10.\n");
	mem.dump(10, 19);

	printf("\n-------------------------Overloaded Operators Test--------------------------\n");
	
	Memory mem2;
	Memory mem3(200);
	for(int i = 0; i < mem2.getSize(); i++){
		mem2[i] = i;
	}
	
	cout << "\n100 integers have been inserted into Memory 2.\n";
	cout << mem2;

	for(int i = 0; i < mem3.getSize(); i++){
		mem3[i] = i;
	}
	cout << "\n200 integers have been inserted into Memory 3.\n";
	cout << mem3;
	
	cout << "\nMemory 4 is the Sum of both Memory 2 and Memory 3\n";
	Memory mem4 = mem2+mem3;
	cout << mem4;	

	cout << "\nMemory 5 is a Copy of Memory 4\n";
	Memory mem5 = mem4;
	cout << mem5;

	cout << "\nMemory 5 is Added to Memory 5\n";
	mem5 = mem5 + mem5;
	cout << mem5;

	if (mem5!=mem4) cout << "\nMemory 5 does not equal Memory 4\n";
	else cout << "\nMemory 5 equals Memory 4\n";
	
	mem5[50] = 99999;
	int value = mem5[50];
	cout << "\n" << value << " has been inserted at location 50 in Memory 5\n";
	cout << mem5;
	
	return -1;
}

