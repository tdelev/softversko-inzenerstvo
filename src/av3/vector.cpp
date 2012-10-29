#include <iostream>
#include <vector>
#include <iterator>
#include <exception>
#include <stdexcept>
using namespace std;

class Word {
private:
	string w;
	int n;
public:
	Word(string ww) {
		w = ww;
		n = ww.size();
	}
	Word() {
		w = "default";
		n = w.size();
	}
	friend ostream& operator<<(ostream &out, const Word &w) {
			out << w.w << " (" << w.n << ")";
			return out;
	}
};

int main() {
	vector<int> v1;
	v1.reserve(50);
	cout << "size: " << v1.size() << endl;
	cout << "capacity: " << v1.capacity() << endl;
	v1.push_back(5);
	v1.push_back(10);
	v1.push_back(20);
	v1.insert(v1.begin() + 1, 1);
	//v1[3] = 2;
	try {
		cout << "3:" << v1.at(3);
	} catch(out_of_range &e) {
		cout << "Wait for it: " << endl;
		cout << e.what() << endl;
	}
	//copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " : "));
	cout << endl;
	for(int i = 0; i < v1.size(); i++) {
		//v1[i] = (i + 1) * 15;
		cout << i << ": " << v1[i] << endl;
	}
	vector<Word> v2(5);
	copy(v2.begin(), v2.end(), ostream_iterator<Word>(cout, " "));
	return 0;
}
