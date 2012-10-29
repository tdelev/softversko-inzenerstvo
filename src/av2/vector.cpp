#include <iostream>
#include <exception>
#include <string.h>
#include <stdlib.h>
using namespace std;

class IllegalIndex: public exception {
	const char* what() const throw() {
		return "IllegalIndex exception";
	}
};

class BigIndex: public exception {
public:
	BigIndex(int x) {
		i = x;
	}
	int get_idx() const {
		return i;
	}
	const char* what() const throw() {
		return "BigIndex exception";
	}
private:
	int i;
};

class BadSize: public exception {
	const char* what() const throw() {
		return "BadSize exception";
	}
};

class UnrecoverableException: public exception {
	const char* what() const throw() {
		return "UnrecoverableException";
	}
};

class Array {
public:
	Array(int) throw (BadSize);
	Array(const Array &) throw (BadSize);
	int size() const {
		return nsize;
	}
	~Array();
	int operator[](int) const throw (IllegalIndex);
	int &operator[](int) throw (IllegalIndex, BigIndex);
	void Expand(int n) throw (UnrecoverableException);
private:
	int *array;
	int nsize;
};

Array::Array(int n) throw (BadSize) {
	try {
		array = new int[nsize = n];
	} catch (bad_alloc) {
		throw BadSize();
	}
	memset(array, 0, nsize * sizeof(int));
	// for(int i=0; i<nsize; array[i++]=0);
}

Array::Array(const Array &x) throw (BadSize) {
	try {
		array = new int[nsize = x.nsize];
	} catch (bad_alloc) {
		throw BadSize();
	}
	memcpy(array, x.array, nsize * sizeof(int));
	// for(int i=0; i<nsize; array[i]=x.array[i++]);
}

Array::~Array() {
	delete[] array;
}

void Array::Expand(int n) throw (UnrecoverableException) {
	int *newarr;
	try {
		newarr = new int[++n];
	} catch (bad_alloc) {
		throw UnrecoverableException();
	}
	memcpy(newarr, array, nsize * sizeof(int));
	memset(newarr + nsize, 0, (n - nsize) * sizeof(int));
	//	for(int i=0; i<nsize; newarr[i]=array[i++]);
	//	for( ; i<n; newarr[i++]=0);
	nsize = n;
	delete[] array;
	array = newarr;
}

int Array::operator[](int i) const throw (IllegalIndex) {
	if (i < 0)
		throw IllegalIndex();
	//		return 0;
	else if (i >= nsize)
		throw IllegalIndex();
	//		return 0;
	else
		return array[i];
}

int &Array::operator[](int i) throw (IllegalIndex, BigIndex) {
	if (i < 0)
		throw IllegalIndex();
	else if (i >= nsize)
		throw BigIndex(i);
	else
		return array[i];
}
void Obraboti1(Array &) throw (IllegalIndex, UnrecoverableException);
void Obraboti2(Array &) throw (IllegalIndex, UnrecoverableException);

int main() {
	for (;;) {
		int s;
		cout << "Vnesi golemina na vektor: ";
		cin >> s;
		try {
			Array a(s);
			Obraboti1(a);
			Obraboti2(a);
		} catch (BadSize) {
			cerr << "Not enough memory! Try smaller number." << endl;
			continue;
		} catch (IllegalIndex) {
			cerr << "IllegalIndex exception" << endl;
			exit(-1);
		} catch (...) {
			cerr << "Unknown unhandled exception" << endl;
			exit(-1);
		}
		break;
	}
	return 0;
}

void Obraboti1(Array &a) throw (IllegalIndex, UnrecoverableException) {
	for (int t = 1;; t++) {
		cout << endl << "try #" << t << endl;
		try {
			cout << "*Array.size=" << a.size() << endl;
			for (int i = 0; i < 12; i++)
				a[i] = i;
			a[20] = 20;
		} catch (BigIndex ix) {
			// perform correcting action
			cout << "Exception raised: Index too big (" << ix.get_idx()
					<< ")- performing correcting action..." << endl;
			a.Expand(ix.get_idx());
			cout << "Correcting... Array.size=" << a.size()
					<< " now. Trying again..." << endl;
			continue; // and try again
		}
		break;
	}
}

void Obraboti2(Array &a) throw (IllegalIndex, UnrecoverableException) {
	const Array *b = &a;
	for (int i = -5; i < 25; i++)
		cout << (*b)[i] << ' ';
	cout << endl;
}

