#include "algostuff.hpp"
using namespace std;
int main() {
	/*initialize source collection with ".......... abcdef.........."
	 */
	vector<char> source(10, '.');
	for (int c = 'a'; c <= 'f'; c++) {
		source.push_back(c);
	}
	source.insert(source.end(), 10, '.');
	print(source, "source: ");
	//copy all letters three elements in front of the 'a'
	vector<char> c1(source.begin(), source.end());
	copy(c1.begin() + 10, c1.begin() + 16,
	//source range
			c1.begin() + 7);
	//destination range
	print(c1, "c1: ");
	//copy all letters three elements behind the 'f'
	vector<char> c2(source.begin(), source.end());
	copy_backward(c2.begin() + 10, c2.begin() + 16,
	//source range
			c2.begin() + 19);
	//destination range
	print(c2, "c2: ");
	return 0;
}
