#include <iostream>
using namespace std;
template<typename T>
class par {
	T vrednost1, vrednost2;
public:
	par(T prv, T vtor) {
		vrednost1 = prv;
		vrednost2 = vtor;
	}
	T modul() {
		return 1;
	}
};
template<> class par<int> {
	int vrednost1, vrednost2;
public:
	par(int prv, int vtor) {
		vrednost1 = prv;
		vrednost2 = vtor;
	}
	int modul() {
		return vrednost1 % vrednost2;
	}
};
template<> class par<double> {
	double v1, v2;
public:
	par(double v1, double v2) {
		this->v1 = v1;
		this->v2 = v2;
	}
	double modul() {
		return v1 / v2;
	}
};
int main() {
	par<int> celi(10, 7);
	par<float> decimalni(100.0, 75.0);
	par<char> znakovi('a', 'b');
	cout << celi.modul() << '\n';
	cout << decimalni.modul() << '\n';
	cout << znakovi.modul() << '\n';
	return 0;
}
