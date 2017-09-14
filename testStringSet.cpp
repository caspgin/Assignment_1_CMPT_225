// Assignment.cpp : Defines the entry point for the console application.
//


#include <iostream>

using namespace std;


int main()
{
	StringSet a;
	/*cout << "current size of a is " << a.size() << endl;*/
	
	a.insert("hello");
		a.insert("bye");
		a.insert("now the size should increase");
	a.insert("hello");
	//cout << "current size of a is " << a.size() << endl << endl;
	
	StringSet b = a;

	cout << "current size of b is " << b.size() << endl;
	cout << "current size of a is " << a.size() << endl;

	cout << b.insert("b is not same as a") << endl;
	
	cout << "current size of b is " << b.size() << endl;
	cout << "current size of a is " << a.size() << endl;

	cout << b.insert("bye") << endl;

	cout << "current size of b is " << b.size() << endl;
	cout << "current size of a is " << a.size() << endl << endl << endl << endl;

	StringSet c = a.unions(b);

	cout << "current size of b is " << b.size() << endl;
	cout << "current size of a is " << a.size() << endl;
	cout << "current size of c is " << c.size() << endl;

	StringSet d;
	cout << "current size of d is " << d.size() << endl;
	
	StringSet e = d.unions(a);
	cout << "current size of a is " << a.size() << endl;
	cout << "current size of d is " << d.size() << endl;
	cout << "current size of e is " << e.size() << endl;

	StringSet f = a.unions(d);
	cout << "current size of a is " << a.size() << endl;
	cout << "current size of d is " << d.size() << endl;
	cout << "current size of f is " << f.size() << endl;

	StringSet h, i = d.unions(h);
	cout << "current size of h is " << h.size() << endl;
	cout << "current size of d is " << d.size() << endl;
	cout << "current size of i is " << i.size() << endl;

	StringSet j = a.intersection(b);

	cout << "current size of a is " << a.size() << endl;
	cout << "current size of b is " << b.size() << endl;
	cout << "current size of j is " << j.size() << endl;

	StringSet k = a.intersection(d);
	cout << "current size of a is " << a.size() << endl;
	cout << "current size of d is " << d.size() << endl;
	cout << "current size of k is " << k.size() << endl;

	StringSet l = d.intersection(a);
	cout << "current size of a is " << a.size() << endl;
	cout << "current size of d is " << d.size() << endl;
	cout << "current size of l is " << l.size() << endl;

	StringSet m = d.intersection(h);
	cout << "current size of h is " << h.size() << endl;
	cout << "current size of d is " << d.size() << endl;
	cout << "current size of m is " << m.size() << endl;

	StringSet n;
	n.insert("why");
	n.insert("hello");
	n.insert("sale");

	StringSet o = n.intersection(a);
	cout << "current size of a is " << a.size() << endl;
	cout << "current size of n is " << n.size() << endl;
	cout << "current size of o is " << o.size() << endl;

	StringSet p = a.difference(b);
	cout << "current size of a is " << a.size() << endl;
	cout << "current size of b is " << b.size() << endl;
	cout << "current size of p is " << p.size() << endl;

	StringSet q = a.difference(h);
	cout << "\n\n\ncurrent size of a is " << a.size() << endl;
	cout << "current size of h is " << h.size() << endl;
	cout << "current size of q is " << q.size() << endl;

	StringSet r = h.difference(a);
	cout << "\n\ncurrent size of a is " << a.size() << endl;
	cout << "current size of h is " << h.size() << endl;
	cout << "current size of r is " << r.size() << endl;

	StringSet s = h.difference(d);
	cout << "\n\ncurrent size of d is " << d.size() << endl;
	cout << "current size of h is " << h.size() << endl;
	cout << "current size of s is " << s.size() << endl;
    return 0;
}

