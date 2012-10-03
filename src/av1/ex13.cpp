#include <iostream>
#define GOLEMINA 100
using namespace std;
template<typename T>
class queue {
	T pqueue[GOLEMINA];
	int glava, opaska;
public:
	queue() {
		glava = opaska = 0;
	}
	void q(T num); // stavi
	T deq(); // zemi
};
template<typename T>
void queue<T>::q(T num) {
	if (opaska + 1 == glava || (opaska + 1 == GOLEMINA && !glava)) {
		cout << "Redot e poln.\n";
		return;
	}
	opaska++;
	if (opaska == GOLEMINA)
		opaska = 0;
	pqueue[opaska] = num;
}
template<typename T>
T queue<T>::deq() {
	if (glava == opaska) {
		cout << "Redot e prazen.\n";
		return 0;
	}
	glava++;
	if (glava == GOLEMINA)
		glava = 0;
	return pqueue[glava];
}
int main() {
	queue<int> q1;
	queue<char> q2;
	int i;
	for (i = 1; i <= 10; i++) {
		q1.q(i);
		q2.q(i - 1 + 'A');
	}
	for (i = 1; i <= 10; i++) {
		cout << "Zemi 1: " << q1.deq() << "\n";
		cout << "Zemi 2: " << q2.deq() << "\n";
	}
	return 0;
}
