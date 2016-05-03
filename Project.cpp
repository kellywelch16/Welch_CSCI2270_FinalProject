#include "HashTable.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){

	int choice, year;
    string name;
    int index;
	HashTable ht;
	string s;
	ifstream file;
	vector<HashElem> movies;

	file.open(argv[1]);
	while(getline(file,s)){
		stringstream ss(s);
		vector<string> result;
		while(ss.good()){
			string substr;
    			getline( ss, substr, ',' );
    			result.push_back(substr);
		}
		HashElem he(result[0], atoi(result[1].c_str()));
		movies.push_back(he);
	}

	while(true){
		cout << "======Main Menu======" << endl;
		cout << "1. Run tests" << endl;
		cout << "2. Add Movie" <<endl;
		cout << "3. Quit" << endl;
		cin >> choice;
		cin.ignore();
		switch(choice){
			case 1 : ht.runTests(movies);
				break;
            case 2 : ht.insertMovie(name, year, index);
            cout<<"name a movie"<<endl;
            cin.ignore();
            getline(cin, name);
            cout<<"name the year"<<endl;
            cin>>year;

                break;
			case 3 : cout << "Goodbye!" << endl;
				ht.~HashTable();
				exit(0);
				break;
		}
	}

	return 0;
}
