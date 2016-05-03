#include "HashTable.h"
#include <iostream>

using namespace std;

int index;
HashElem *temp = NULL;

HashTable::HashTable(){
	clearTable();
}

HashTable::~HashTable(){

}

void HashTable::clearTable(){
	for(int i = 0; i < tableSize; i++){
		hashTable[i] = NULL;
	}
}

void HashTable::insertMovie(std::string name, int year, int index){
	HashElem *he  = new HashElem(name, year);
	if(hashTable[index] == NULL){
		hashTable[index] = he;
	}else{
		temp = hashTable[index];
		while(temp -> next != NULL){
			temp = temp -> next;
		}
		temp -> next = he;
		he -> previous = temp;
	}
}

int HashTable::sumHash(std::string name) {
	int sum = 0;
	for(int i = 0; i < name.length(); i++){
		sum += name[i];
	}
    	return sum % tableSize;
}

int HashTable::simpleHash(std::string name) {
    	return name.length() % tableSize;
}

int HashTable::elfHash (std::string name) {
	int hashValue = 0;
    	for (int i = 0; i < name.length(); i++) {
    		hashValue = (hashValue << 4) + name[i];
        		int hiBits = hashValue & 0xF0000000;
        		if (hiBits != 0){
        			hashValue ^= hashValue >> 24;
        		}
        		hashValue &= ~hiBits;
    	}
    	return hashValue % tableSize;
}

int HashTable::cryptoHash (std::string name) {
    	int hashValue = sumHash(name);
    	for (int i = 0; i < name.length(); i++) {
        		hashValue = (hashValue << 4) + name[i];
        		int hiBits = hashValue & 0xF0000000;
        		if (hiBits != 0)
            			hashValue ^= hashValue >> 24;
        		hashValue &= ~hiBits;
    	}
    	return hashValue % tableSize;
}

int HashTable::djb2Hash(std::string name){
	unsigned long g = 5381;
	string m;
        	for(int i = 0; i < name.length(); i++){
            		g = ((g << 5) + g) + m[i];
        	}
        	return g % tableSize;
}

int HashTable::sdbmHash(std::string name){
	unsigned long g = 0;
	string m;
        	for(int i = 0; i < name.length(); i++){
            		g = m[i] + (g << 6) + (g << 16) - g;
        	}
        	return g % tableSize;
}

void HashTable::runTests(vector<HashElem> movies){
	cout << "Total movies: " << movies.size() << endl;
	cout << "Table size: " << tableSize << endl;
}
