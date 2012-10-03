#include <iostream>
using namespace std;

template<typename T>
class bazenVektor {
public:
	bazenVektor(unsigned int size);
	virtual ~bazenVektor();
	T &operator [](unsigned int index) const;
	unsigned int dolz() const;
private:
	T* podatoci;
	unsigned int golemina;
};

template<typename T>
bazenVektor<T>::bazenVektor(unsigned int size) :
	golemina(size) {
	podatoci = new T[golemina];
}
template<typename T>
bazenVektor<T>::~bazenVektor() {
	delete[] podatoci;
	podatoci = 0;
}
template<typename T>
T & bazenVektor<T>::operator [](unsigned int index) const {
	return podatoci[index];
}
template<typename T>
unsigned int bazenVektor<T>::dolz() const {
	return golemina;
}
template<typename T>
void pecati(bazenVektor<T> &a) {
	for (int i = 0; i < a.dolz(); i++)
		cout << a[i] << "  ";
	cout << endl;
}

int main() {
	bazenVektor<int> A(15);
	bazenVektor<float> B(5);
	bazenVektor<char> C(8);
	int i;
	cout << "dolz na A (15) e " << A.dolz() << endl;
	cout << "dolz na B (5) e " << B.dolz() << endl;
	for (i = 0; i < A.dolz(); i++)
		A[i] = 2 * i;
	cout << "podatoci vo A (0, 2, 4,...) se ";
	pecati(A);
	float x;
	for (i = 0, x = 2.5; i < B.dolz(); i++, x += 3.0)
		B[i] = x;
	cout << "podatoci vo B (2.5, 5.5,...)se ";
	pecati(B);
	char c = 'f';
	for (i = 0; i < C.dolz(); i++, c++)
		C[i] = c;
	cout << "podatoci vo C ('f', 'g',...)se ";
	pecati(C);
	return 0;
}
