#include <string>
#include "StringSet.h"

using namespace std;



// Default Constructor
StringSet::StringSet()
{
	currentSize = 0;
	maxSize = 2;
	set = new string[maxSize];
}



// Copy Constructor
// POST: returns a deep copy of the parameter(targetSet)
// PARAM: targetSet = set to be copied
StringSet::StringSet(const StringSet& targetSet)
{
	maxSize = targetSet.maxSize;
	currentSize = targetSet.size();
	
	set = new string[maxSize];
	for (int i = 0; i < currentSize; i++)
		set[i] = targetSet.set[i];
}



// Destructor
StringSet::~StringSet()
{
	delete[] set;

}



// inserts a string  at the end of the set(array) 
// POST: returns true if string is inserted and false if string already exists. 
//		 Increases currentSize by 1. Doubles the actual size if array is full. 
// PARAM: aString = A string to be inserted.

bool StringSet::insert(string aString)
{
	bool stringInserted = false;

	if (find(aString) == -1)
	{
		if (currentSize == maxSize)
			maxSize *= 2;

		string* temp = new string[maxSize];
		for (int i = 0; i<currentSize; i++)
			temp[i] = set[i];

		delete[] set;

		set = temp;

		set[currentSize] = aString;

		currentSize++;

		stringInserted = true;
	}

	return stringInserted;
}



// removes a string by replacing it with the end string
// POST: returns true if string is removed and false if string does not exists. Decreases currentSize by 1.
// PARAM: target = target string to be removed

bool StringSet::remove(string target)
{
	bool found = false;
	int index = find(target);
	if (index != -1)
	{
		found = true;
		set[index] = set[currentSize - 1];
		currentSize--;
	}
	
	return found;
}



// searches for a string in the set
// POST: returns the index of the searched string or returns -1 if string does not exsit.
// PARAM: targetString = string to be searched

int StringSet::find(string targetString) const
{
	for (int i = 0; i < currentSize; i++)
		if (targetString == set[i])
			return i;
	
	return -1;
}



// returns the current size of the set
// POST: returns the currentSize 

int StringSet::size() const
{
	return currentSize;
}



// gives an union of two sets (the calling set and the parameter set)
// POST: returns a StringSet object with all elements without repetion and an empty object if both sets are empty.
// PARAM: stringSetA = other set to be unioned with the calling set

StringSet StringSet::unions(const StringSet & stringSetA) const
{
	StringSet unionSet = *this;
	
 	for (int i = 0; i < stringSetA.size(); i++)
		unionSet.insert(stringSetA.set[i]);
		
	return unionSet;
}



// gives an intersection of two sets (the calling set and the parameter set)
// POST: returns a StrinSet object with common elements. returns an empty object if both sets are empty.
// PARAM: stringSetB = set to intersect with the calling set.

StringSet StringSet::intersection(const StringSet & stringSetB) const
{
	StringSet intersectionSet;
	
	for (int i = 0; (i < this->size()) && (stringSetB.size() !=0); i++)
		if (stringSetB.find(this->set[i]) != -1)
			intersectionSet.insert(this->set[i]);


	return intersectionSet;
}



// gives a differnce between calling set and parameter(stringSetC) set
// POST: returns a StringSet object with elements of calling set without the common elements.
// PARAM: stringSetC = set to be subtracted from the calling set

StringSet StringSet::difference(const StringSet & stringSetC) const
{
	StringSet commonSet = this->intersection(stringSetC),
			  differenceSet = *this;

	for (int i = 0; i < commonSet.size(); i++)
		differenceSet.remove(commonSet.set[i]);

	return differenceSet;
}

