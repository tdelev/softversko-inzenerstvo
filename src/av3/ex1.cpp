#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
int main() {
	vector < string > recenica;
	recenica.reserve(5);
	recenica.push_back("Hello,");
	recenica.push_back("how");
	recenica.push_back("are");
	recenica.push_back("you");
	recenica.push_back("?");
	copy(recenica.begin(), recenica.end(), ostream_iterator<string> (cout, " "));
	cout << endl;
	cout << " max_size(): " << recenica.max_size() << endl;
	cout << " size(): " << recenica.size() << endl;
	cout << " capacity(): " << recenica.capacity() << endl;
	swap(recenica[1], recenica[3]);
	recenica.insert(find(recenica.begin(), recenica.end(), "?"), "always");
	recenica.back() = "!";
	copy(recenica.begin(), recenica.end(), ostream_iterator<string> (cout, " "));
	cout << endl;
	cout << " max_size(): " << recenica.max_size() << endl;
	cout << "size(): " << recenica.size() << endl;
	cout << " capacity(): " << recenica.capacity() << endl;
	return 0;
}
