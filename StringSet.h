#pragma once
#include <string>
using namespace std;

class StringSet
{
public:
	
	// Default Constructor
	StringSet();

	// Copy Constructor
	// POST: returns a deep copy of the parameter(targetSet)
	// PARAM: targetSet = set to be copied
	StringSet(const StringSet& targetSet);


	// Destructor
	~StringSet();


	// inserts a string  at the end of the set(array) 
	// POST: returns true if string is inserted and false if string already exists. 
	//		 Increases currentSize by 1. Doubles the actual size if array is full. 
	// PARAM: aString = A string to be inserted.
	bool insert(string aString);


	// removes a string by replacing it with the end string
	// POST: returns true if string is removed and false if string does not exists. Decreases currentSize by 1.
	// PARAM: target = target string to be removed.
	bool remove(string target);


	// searches for a string in the set
	// POST: returns the index of the searched string or returns -1 if string does not exsit.
	// PARAM: targetString = string to be searched
	int find(string targetString) const;


	// returns the current size of the set
	// POST: returns the currentSize 
	int size() const;


	// gives an union of two sets (the calling set and the parameter set)
	// POST: returns a StringSet object with all elements without repetion and an empty object if both sets are empty.
	// PARAM: stringSetA = other set to be unioned with the calling set
	StringSet unions(const StringSet& stringSetA) const;


	// gives an intersection of two sets (the calling set and the parameter set)
	// POST: returns a StrinSet object with common elements. returns an empty object if both sets are empty.
	// PARAM: stringSetB = set to intersect with the calling set.
	StringSet intersection(const StringSet& stringSetB) const;


	// gives a differnce between calling set and parameter(stringSetC) set
	// POST: returns a StringSet object with elements of calling set without the common elements.
	// PARAM: stringSetC = set to be subtracted from the calling set
	StringSet difference(const StringSet& stringSetC) const;


private:

	int currentSize; // number of strings stored in the array
	int maxSize; // actual size of array
	string* set;// a pointer to store a dynamic string array
};

