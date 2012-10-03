#include <iostream>
#include <string.h>
using namespace std;
template<typename T>
int baraj(T objekt, T *lista, int golemina) {
	for (int i = 0; i < golemina; i++)
		if (objekt == lista[i])
			return i;
	return -1;
}
int main() {
	int a[] = { 1, 2, 3, 4 };
	char *c = "Ova e test";
	double d[] = { 1.1, 2.2, 3.3 };
	cout << baraj(3, a, 4) << endl;
	cout << baraj('a', c, (int) strlen(c)) << endl;
	cout << baraj(0.0, d, 3) << endl;
	return 0;
}
