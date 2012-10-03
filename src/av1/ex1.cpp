#include <iostream>
using namespace std;
template<typename T>
T suma(T *pole, int n) {
	T suma = 0;
	for (int i = 0; i < n; ++i)
		suma += pole[i];
	return suma;
}
int main() {
	int x[] = { 1, 2 };
	double y[] = { 1.1, 2.2 };
	cout << suma(x, 2) << endl << suma(y, 2) << endl;
	return 0;
}
