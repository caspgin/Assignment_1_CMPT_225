
#include <string>
#include "StringSet.h"

using namespace std;

StringSet::StringSet()
{
	currentSize = 0;
	maxSize = 2;
	set = new string[maxSize];
}

StringSet::StringSet(const StringSet& targetSet)
{
	maxSize = 2*targetSet.size();
	currentSize = targetSet.size();
	
	set = new string[maxSize];
	for (int i = 0; i < targetSet.size(); i++)
		set[i] = targetSet.set[i];
}

StringSet::~StringSet()
{
	delete[] set;

}

bool StringSet::insert(string aString)
{
	for (int index = 0; index < currentSize; index++)
		if (aString == set[index])
			return false;
	
	if (maxSize == 0)
		maxSize = 2;
	else if (currentSize == maxSize)
		maxSize *= 2;
	
	string* temp = new string[maxSize];
	for (int i=0; i<currentSize; i++)
		temp[i] = set[i];

	delete[] set;
	
	set = temp;
	
	set[currentSize] = aString;

	currentSize++;

	return true;
}

bool StringSet::remove(string bString)
{
	bool found = false;
	for (int index = 0; index < currentSize; index++)
		if (bString == set[index])
		{
			found = true;
			set[index] = set[currentSize - 1];
			currentSize--;
		}
	
	return found;
}

int StringSet::find(string cString) const
{
	for (int i = 0; i < currentSize; i++)
		if (cString == set[i])
			return i;
	return -1;
}

int StringSet::size() const
{
	return currentSize;
}

StringSet StringSet::unions(const StringSet & aStringSet) const
{
	StringSet unionSet = *this;
	
 	for (int i = 0; i < aStringSet.size(); i++)
		unionSet.insert(aStringSet.set[i]);
		
	return unionSet;
}

StringSet StringSet::intersection(const StringSet & bStringSet) const
{
	StringSet intersectionSet;
	
	for (int i = 0; i < this->size(); i++)
	{
		for (int j = 0; j < bStringSet.size(); j++)
			if (this->set[i] == bStringSet.set[j])
				intersectionSet.insert(set[i]);
	}
	
	return intersectionSet;
}

StringSet StringSet::difference(const StringSet & cStringSet) const
{
	StringSet commonSet = this->intersection(cStringSet),
			  differenceSet = *this;

	for (int i = 0; i < commonSet.size(); i++)
		differenceSet.remove(commonSet.set[i]);

	return differenceSet;
}

