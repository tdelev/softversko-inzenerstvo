#include <iostream>
using namespace std;
template<typename T>
class X {
public:
	static T s;
};
template<typename T> T X<T>::s = 0;
template<> int X<int>::s = 3;
template<> char* X<char*>::s = "Programiraj";
int main() {
	X<int> xi;
	cout << "xi.s = " << xi.s << endl;
	X<char*> xc;
	cout << "xc.s = " << xc.s << endl;
	cout << X<int>::s << endl;
	return 0;
}
