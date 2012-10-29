#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "print.hpp"
using namespace std;

int main() {
	vector<int> coll;
	//create, back inserter for coll
	// - inconvenient way
	back_insert_iterator < vector<int> > iter(coll);
	//insert elements with the usual iterator interface
	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;
	print(coll);
	//create back inserter and insert elements
	// - convenient way
	back_inserter(coll) = 44;
	back_inserter(coll) = 55;
	print(coll);
	//use back inserter to append all elements again
	copy(coll .begin(), coll.end(), back_inserter(coll));
	print(coll);
	return 0;
}
