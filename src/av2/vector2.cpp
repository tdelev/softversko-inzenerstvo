#include <iostream>
#include <exception>
#include <stdexcept>
#include <stdlib.h>
#include <vector>
using namespace std;
#define EXCEPTION_DEBUG

template<typename T>
class Array: public vector<T> {
public:
	Array() {
	}
	Array(int n) :
		vector<T> (n, T(0)) {
	}
	//	Array(const Array &x) : vector<T>(x) {}
	~Array() {
	}
	int operator[](int) const;
	int &operator[](int);
};

template<typename T>
int Array<T>::operator[](int i) const {
	try {
		return vector<T>::at(i);
	} catch (exception &e) {
#ifdef EXCEPTION_DEBUG
		cout << e.what() << " : 0 za indeksi nadvor od opseg..." << endl;
		//throw;
#endif
		return 0;
	}
}

template<typename T>
int &Array<T>::operator[](int i) {
	for (;;) {
		try {
			return vector<T>::at(i);
		} catch (exception &e) {
#ifdef EXCEPTION_DEBUG
			cout << e.what() << " - correcting size..." << endl;
#endif
			vector<T>::resize(i + 1, 0);
			continue;
		}
		break;
	}
}

int main() {
	void Obraboti1(Array<int> &);
	void Obraboti2(Array<int> &);

	for (int t = 1;; t++) {
		int s;
		cout << "Try#" << t << ": ";
		cout << "Vnesi golemina na vektor: ";
		cin.clear();
		cin >> s;
		try {
			Array<int> a(s);
			Obraboti1(a);
			Obraboti2(a);
		} catch (bad_alloc) {
			cerr << "Not enought memory! Try smaller number." << endl;
			continue;
		} catch (out_of_range) {
			cerr << "IllegalIndex exception" << endl;
			exit(-1);
		} catch (exception &e) {
			cerr << "Exception: " << e.what() << endl;
			exit(-1);
		} catch (...) {
			cerr << "Unknown unhandled exception" << endl;
			exit(-1);
		}
		break;
	}
	return 0;
}

void Obraboti1(Array<int> &a) {
	cout << "Array.size=" << a.size() << endl;
	for (int i = 0; i < 12; i++) {
		cout << "a[" << i << "] <- " << i << endl;
		a[i] = i;
	}
	cout << "a[" << 20 << "] <- " << 20 << endl;
	a[20] = 20;
	for (int i = 0; i <= 20; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void Obraboti2(Array<int> &a) {
	const Array<int> *b = &a;
	for (int i = -5; i < 25; i++)
		cout << "*b[" << i << "] == " << (*b)[i] << endl;
	cout << endl;
	cout << "*b[23] == " << (*b)[23] << endl;
	//	const Array<int> c=a;
	//	for(int i=-2; i<22; i++)
	//		cout << "c[" << i << "] == " << c[i] << endl;
}

