#include <iostream>
#define GOLEMINA 100
using namespace std;
template<typename T> class stack {
	T stck[GOLEMINA];
	int tos;
public:
	void init() {
		tos = 0;
	}
	void push(T ch);
	T pop();
};
template<typename T>
void stack<T>::push(T ob) {
	if (tos == GOLEMINA) {
		cout << "Stack e poln.\n";
		return;
	}
	stck[tos] = ob;
	tos++;
}

template<typename T>
T stack<T>::pop() {
	if (tos == 0) {
		cout << "Stack e prazen.\n";
		return 0;
	}
	tos--;
	return stck[tos];
}
int main() {
	stack<char> s1, s2;
	int i;
	s1.init();
	s2.init();
	s1.push('a');
	s2.push('x');
	s1.push('b');
	s2.push('y');
	s1.push('c');
	s2.push('z');
	for (i = 0; i < 3; i++)
		cout << "Pop s1: " << s1.pop() << "\n";
	for (i = 0; i < 3; i++)
		cout << "Pop s2: " << s2.pop() << "\n";
	stack<double> ds1, ds2; // kreiraj dva stack - a
	ds1.init();
	ds2.init();
	ds1.push(1.1);
	ds2.push(2.2);
	ds1.push(3.3);
	ds2.push(4.4);
	ds1.push(5.5);
	ds2.push(6.6);
	for (i = 0; i < 3; i++)
		cout << "Pop ds1: " << ds1.pop() << "\n";
	for (i = 0; i < 3; i++)
		cout << "Pop ds2: " << ds2.pop() << "\n";
	return 0;
}
