#include "memory.h"


/*
Author : Blaz Pocrnja 
Student ID : 5035473
Lab #5 
Purpose: Member functions to the class "Memory" which simulates computer memory. Stores a specified number of integers, with a default of 100.
*/

Memory::Memory(int s){
/*Constructor takes an int as an argument, allocates the specified amount of space and saves it into size */

	m = new int[size = s];
}

Memory::Memory(){
/*Default constructor which takes no parameters, initlializes size to 100*/

	m = new int[size = 100];
}

Memory::Memory(const Memory &other){
/*Copy constructor*/
	copy(other);
}

Memory::~Memory(void){
/*Destructor: Ensures destruction of pointer*/

	delete []m;
}

void Memory::BlockCopy(int source, int destination, int length){
/*Block Copy: One region of Memory is copied into another, copies from source, up to and including, source + length. If the block copied is too long to fit into the destination, then whatever is can fit is copied*/

		int tmp[length];
		for(int i = source; i <= (source+length); i++){
			tmp[i - source] = m[i];
		}
		
		if((destination + length) > size){
			for(int i = destination; i < size; i++){
				m[i] = tmp[i - destination];
			}
		}
		else{
			for(int i = destination; i <= (destination+length); i++){
				m[i] = tmp[i - destination];
			}
		}
}

void Memory::insert(int insertion, int location){
/*Stores an integer at any memory location, overwriting whatever was there before. If specified location is larger than last index of Memory, will insert at the end */
	if (location > size-1){
		printf("\n");
		printf("Out of range insertion: Placing at end.");
		printf("\n");
		printf("\n");
		m[size-1] = insertion;
	}
	else{
		m[location] = insertion;
	}
}


int Memory::getSize(void){
/*Returns member variable size*/

	return size;
}

int Memory::retrieve(int location){
/*Returns element at specified location*/

	return m[location];
}

void Memory::dump(int start, int end) const {
/*Prints values stored in Memory in rows of 10 from the closest to start, up to and including closest index of end*/

	int i, j, row, index;

	index = floor(start/10) * 10; //Sets starting index to the closest and smallest number divisible by 10 i.e 45's index starts at 40 and increments from there
	row = ceil(end / 10);         //If end value exceeds column length a new row is created

	if(end >= size){
		printf("\n");
		printf("Caution: Index out Range. Will output junk.");
		printf("\n \n");
	}

	printf("        ");
	for(i = 0; i < 10; i++){
		printf("%5d", i);
	}

	printf("\n");

	for(i = floor(start/10); i <= row; i++){	//i starts at the tens position of the start i.e 45 is in row 4, so it begins there
		printf("%05d : ", i);
		for(j = 0; j < 10; j++){
			printf("%05d" , m[index]);
			index++;
		}
		printf("\n");
	}

}

void Memory::dump() const {
/*prints all Memory values*/

	dump(0, size - 1);
}


int& Memory::operator[](int n){
/*Returns a reference to an int, as long as the index is not out of bounds*/
	if( n >= size ){
              printf("\nIndex out of bounds.\n"); 
              // return first element.
              return m[0];
	}

	return m[n];
}

const int& Memory::operator[](int n) const{
/*Returns a reference to a const, as long as the index is not out of bounds*/

	if( n >= size ){
              printf("\nIndex out of bounds.\n"); 
              // return first element.
              return m[0];
	}

	return m[n];
}

bool Memory::operator==(const Memory& other){
/*compares two Memories to see if they are equal*/

	bool equals = false;
	if (size == other.size){
		for(int i = 0; i < size; i++){
			if(m[i] == other.m[i]){
				equals = true;
			}
			else{
				equals = false;
				break;
			}
		}
	}
	return equals;
	
}

bool Memory::operator!=(const Memory& other){
/*calls == operator and returns the opposite*/

	return !(*this == other);
	
}

Memory& Memory::operator=(const Memory& other){
/*Assigns one Memory's contents into another instance of Memory*/
	if(this != &other){;
		delete[] m;
		copy(other);
	}	
	return *this;
}

void Memory::copy(const Memory& other){
/*Copies contents of other into calling object */
	m = new int[other.size];
	size = other.size;
	for(int i = 0; i < size; i++){
		m[i] = other[i];
	}
}

Memory operator+(const Memory &a,const Memory &b){
/*Adds two Memories together. If one is larger than the other it simply copies what's left*/
	
	int i;
	int newsize = max(a.size, b.size);
	Memory additionmem(newsize);

	for(i = 0; i < min(a.size, b.size); i++){
		additionmem[i] = a[i] + b[i];
	}
	if(a.size > b.size){
		for(i; i < newsize; i++){
			additionmem[i] = a[i];
		}
	}
	
	else if(a.size < b.size){
		for(i; i < newsize; i++){
			additionmem[i] = b[i];
		}
	}
	
	return additionmem;
}

ostream& operator<<(ostream &s, const Memory& m){
/*Prints all of Memory*/
	m.dump();
	return s;
}
	

