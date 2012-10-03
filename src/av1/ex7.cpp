#include <iostream>
using namespace std;
template<typename T>
void qsort(T *ia, int dolu, int gore) {
	if (dolu < gore) {
		int d = dolu;
		int go = gore + 1;
		T element = ia[dolu];
		for (;;) {
			while (ia[++d] < element)
				;
			while (ia[--go] > element)
				;
			if (d < go)
				smeni(ia, d, go);
			else
				break;
		}
		smeni(ia, dolu, go);
		qsort(ia, dolu, go - 1);
		qsort(ia, go + 1, gore);
	}
}
template<typename T>
void smeni(T *element, int i, int j) {
	T temp = element[i];
	element[i] = element[j];
	element[j] = temp;
}
template<typename T>
void prikazi(T *ia, int golemina) {
	cout << "< ";
	for (int ix = 0; ix < golemina; ix++)
		cout << ia[ix] << "  ";
	cout << " >\n";
}
double da[] =
		{ 26.7, 5.7, 37.7, 1.7, 61.7, 11.7, 59.7, 15.7, 48.7, 19.7, 14.9 };
int ia[] = { 503, 87, 512, 61, 908, 170, 897, 275, 653, 426, 154, 509, 612,
		677, 765, 703 };
int main() {
	int golemina = sizeof(da) / sizeof(double);
	cout << " Sortiranje na double pole (golemina == " << golemina << ") \n";
	qsort(da, 0, golemina - 1);
	prikazi(da, golemina);
	golemina = sizeof(ia) / sizeof(int);
	cout << " Sortiranje na int pole (golemina == " << golemina << ") \n";
	qsort(ia, 0, golemina - 1);
	prikazi(ia, golemina);
	return 0;
}
