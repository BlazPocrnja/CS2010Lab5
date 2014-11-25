#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;
using std::string;


/*
Author : Blaz Pocrnja 
Student ID : 5035473
Lab #5
Purpose: Interface for the class "memory" as well as related non member functions and overloaded operators, to be used in "driver.cpp" and "memory.cpp"
*/

class Memory{
	private:
		int *m;
		int size;
	public:
		//Constructor
		explicit Memory(int);
		Memory();
		Memory(const Memory &other);
		//Destructor
		~Memory(void);
		//Modifiers
		void BlockCopy(int, int, int);
		void insert(int,int);
		int& operator[](int n);
		//Selectors
		int getSize(void);
		int retrieve(int);
		void dump(void) const;
		void dump(int, int) const;
		const int& operator[](int n) const;
		//Memory Assignment
		void copy(const Memory& other);
		Memory& operator=(const Memory& other);
		//Equality Operators
		bool operator==(const Memory& other);
		bool operator!=(const Memory& other);
		//Friends
		friend Memory operator+(const Memory& a, const Memory& b);
		
};

//Nonmember functions
ostream& operator<<(ostream &s, const Memory& m);



#endif
