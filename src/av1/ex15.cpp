#include <iostream>
using namespace std;
template<typename T>
void f(T t) {
	static T s = 0;
	s = t;
	cout << "s = " << s << endl;
}
int main() {
	f(10);
	f("Nemoj da programiras");
	return 0;
}
