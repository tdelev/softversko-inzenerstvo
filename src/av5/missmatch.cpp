#include "algostuff.hpp"
using namespace std;
int main() {
	vector<int> coll1;
	list<int> coll2;
	insert(coll1, 1, 6);
	for (int i = 1; i <= 16; i *= 2) {
		coll2.push_back(i);
	}
	coll2.push_back(3);
	print(coll1, "coll1: ");
	print(coll2, "coll2: ");
	//find first mismatch
	pair < vector<int>::iterator, list<int>::iterator > values;
	values = mismatch(coll1.begin(), coll1.end(), //first range
			coll2.begin());
	//second range
	if (values.first == coll1.end()) {
		cout << "no mismatch" << endl;
	} else {
		cout << "first mismatch: " << *values.first << " and "
				<< *values.second << endl;
	}
	/*find first position where the element of coll1 is not
	 *less than the corresponding element of coll2
	 */
	values = mismatch(coll1.begin(), coll1.end(),
	//first range
			coll2. begin(),
			//second range
			less_equal<int> ());
	//criterion
	if (values.first == coll1.end()) {
		cout << "always less-or-equal" << endl;
	} else {
		cout << "not less-or-equal: " << *values.first << " and "
				<< *values.second << endl;
	}
	return 0;
}
