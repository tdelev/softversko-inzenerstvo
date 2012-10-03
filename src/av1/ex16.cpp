#include <iostream>
using namespace std;
template<typename T>
class signal {
protected:
	T frekvencija;
public:
	signal(T x) {
		frekvencija = x;
		cout << "Klasa osnovna " << x << endl;
	}
};
template<typename T>
class FM: public signal<T> {
public:
	FM(T x) :
		signal<T> (x) {
		cout << "Klasa nasledena" << signal<T>::frekvencija << endl;
	}
};
int main() {
	FM<int> radio(94);
	return 0;
}
