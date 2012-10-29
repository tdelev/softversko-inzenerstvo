#include <iterator>
#include "algostuff.hpp"
using namespace std;
int main() {
	list<int> coll;
	insert(coll, 2, 6);
	insert(coll, 4, 9);
	print(coll);
	//print all elements with value 5 replaced with 55
	replace_copy(coll.begin(), coll.end(), ostream_iterator<int> (cout, " "),
			5, 55);
	cout << endl;
	//source
	//destination
	//old value
	//new value
	//print all elements with a value less than 5 replaced with 42
	replace_copy_if(coll.begin(), coll.end(),
	//source
			ostream_iterator<int> (cout, " "),
			//destination
			bind2nd(less<int> (), 5),
			//replacement criterion
			42);
	//new value
	cout << endl;
	//print each element while each odd element is replaced with 0
	replace_copy_if(coll.begin(), coll.end(),
	//source
			ostream_iterator<int> (cout, " "),
			//destination
			bind2nd(modulus<int> (), 2), //replacement criterion
			0);
	//new value
	cout << endl;
	return 0;
}
