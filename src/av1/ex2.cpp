#include <iostream>
using namespace std;

template<typename T>
inline T const& maximum(T const& a, T const& b) {
	// if a < b then use b else use a
	return a < b ? b : a;
}

int main() {
	cout << maximum(15, 78) << endl;
	cout << maximum(23.4f, (float)17.1) << endl;
	cout << maximum(143L, 13334L) << endl;
	return 0;
}
