#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include "print.hpp"

using namespace std;
int main() {
	set<int> coll;
	//create insert iterator for coll
	// - inconvenient way
	insert_iterator < set<int> > iter(coll, coll.begin());
	//insert elements with the usual iterator interface
	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;
	print(coll, "set: ");
	//create inserter and insert elements
	// - convenient way
	inserter(coll, coll.end()) = 44;
	inserter(coll, coll.end()) = 55;
	print(coll, "set: ");
	//use inserter to insert all elements into a list
	list<int> coll2;
	copy(coll.begin(), coll.end(), inserter(coll2, coll2.begin()));
	//destination
	//source
	print(coll2, "list: ");
	//use inserter to reinsert all elements into the list before the second element
	copy(coll.begin(), coll.end(),
	//source
	inserter(coll2, ++coll2.begin()));
	//destination
	print(coll2,"list: ");
	return 0;
}
