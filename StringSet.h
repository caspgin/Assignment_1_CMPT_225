#ifndef STRINGSET_H
#define STRINGSET_H

#include <string>
using namespace std;

class StringSet
{
public:

	StringSet();

	StringSet(const StringSet& targetSet);

	~StringSet();

	bool insert(string aString);

	bool remove(string bString);

	int find(string cString) const;

	int size() const;

	StringSet unions(const StringSet& aStringSet) const;

	StringSet intersection(const StringSet& bStringSet) const;

	StringSet difference(const StringSet& cStringSet) const;

private:

	int currentSize;
	int maxSize;
	string* set;
};

#endif
