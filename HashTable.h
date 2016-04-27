#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>

struct HashElem{
	std::string title;
	int year;
	HashElem *next;
    	HashElem *previous;

	HashElem(){};
	HashElem(std::string in_title, int in_year)
	{
		title = in_title;
		year = in_year;
		next = NULL;
		previous = NULL;
	}

};

class HashTable
{
	public:
		HashTable();
		~HashTable();
		void insertMovie(std::string name, int year);
		void runTests(std::vector<HashElem> movies);
		void clearTable();
		int simpleHash(std::string);
        		int sumHash(std::string);
        		int elfHash(std::string);
        		int cryptoHash(std::string);
        		int djb2Hash(std::string);
        		int sdbmHash(std::string);
	private:
		int tableSize = 10;
		HashElem* hashTable[10];

};

#endif // HASHTABLE_H
