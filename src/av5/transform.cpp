#include <iterator>
#include "algostuff.hpp"
using namespace std;
int main() {
	vector<int> coll1;
	list<int> coll2;
	insert(coll1, 1, 9);
	print(coll1, "coll1: ");
	//negate all elements in coll1
	transform(coll1.begin(), coll1.end(), coll1.begin(), negate<int> ());
	//source range
	//destination range
	//operation
	print(coll1, "negated: ");
	//transform elements of coll1 into coll2 with ten times their value
	transform(coll1.begin(), coll1.end(),
	//source range
			back_inserter(coll2),
			//destination range
			bind2nd(multiplies<int> (), 10));
	//operation
	print(coll2, "coll2: ");
	//print coll2 negatively and in reverse order
	transform(coll2.rbegin(), coll2.rend(), ostream_iterator<int> (cout, " "),
			negate<int> ());
	cout << endl;
	//source range
	//destination range
	//operation
	return 0;
}

