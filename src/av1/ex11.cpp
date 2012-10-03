#include <iostream>
using namespace std;
class iBazenVektor {
public:
	iBazenVektor(unsigned int element);
	virtual ~iBazenVektor();
	int &operator [](unsigned int index) const;
	unsigned int dolz() const;
private:
	int * podatoci;
	unsigned int golemina;
};
iBazenVektor::iBazenVektor(unsigned int element) :
	golemina(element) {
	podatoci = new int[golemina];
}
iBazenVektor::~iBazenVektor() {
	delete[] podatoci;
	podatoci = 0;
}
int & iBazenVektor::operator [](unsigned int index) const {
	return podatoci[index];
}
unsigned int iBazenVektor::dolz() const {
	return golemina;
}
void pecati(iBazenVektor & a) {
	for (int i = 0; i < a.dolz(); i++)
		cout << a[i] << "  ";
	cout << endl;
}
int main() {
	iBazenVektor A(15);
	cout << "dolz na A (15) e " << A.dolz() << endl;
	for (int i = 0; i < A.dolz(); i++)
		A[i] = 2 * i;
	cout << "podatoci vo A (0, 2, 4,...) se ";
	pecati(A);
	return 0;
}
