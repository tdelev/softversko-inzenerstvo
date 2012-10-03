#include <iostream>
using namespace std;
template<typename T>
class abc {
	T data;
public:
	abc(T x) {
		data = x;
		cout << data << endl;
	}
};
int main() {
	abc<char> a('a');
	abc<int> b(123);
	abc<float> c(123.45f);
	return 0;
}
