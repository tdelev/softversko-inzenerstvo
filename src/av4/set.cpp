#include <iostream>
#include <set>
#include <iterator>
using namespace std;
int main() {
	typedef set<int, greater<int> > IntSet;
	IntSet coll1; // empty set container
	//insert elements in random order
	coll1.insert(4);
	coll1.insert(3);
	coll1.insert(5);
	coll1.insert(1);
	coll1.insert(6);
	coll1.insert(2);
	coll1.insert(5);//ignored
	//iterate over all elements and print them
	IntSet::iterator pos;
	for (pos = coll1.begin(); pos != coll1.end(); ++pos) {
		cout << *pos << ' ';
	}
	cout << endl;
	//insert 4 again and process return value
	pair<IntSet::iterator, bool> status = coll1.insert(4);
	if (status.second) {
		cout << "4 inserted as element " << distance(coll1.begin(),
				status.first) + 1 << endl;
	} else {
		cout << "4 already exists" << endl;
	}
	//assign elements to another set with ascending order
	set<int> coll2(coll1.begin(),coll1.end());
	//print all elements of the copy
	copy(coll2.begin(), coll2.end(), ostream_iterator<int> (cout, " "));
	cout << endl;
	//remove all elements up to element with value 3, without 3
	coll2.erase(coll2.begin(), coll2.find(3));
	//remove all elements with value 5
	int num;
	num = coll2.erase(5);
	cout << num << " element(s) removed" << endl;
	//print all elements
	copy(coll2.begin(), coll2.end(), ostream_iterator<int> (cout, " "));
	cout << endl;
	return 0;
}
