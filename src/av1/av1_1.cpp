int suma(int *pole, unsigned n) {
	int zbir = 0;
	for (int i = 0; i < n; ++i)
		zbir += pole[i];
	return zbir;
}

double suma(double *pole, unsigned n) {
	double zbir = 0;
	for (int i = 0; i < n; ++i)
		zbir += pole[i];
	return zbir;
}

template<typename T>
inline T const& max(T const& a, T const& b) {
	// if a < b then use b else use a
	return a < b ? b : a;
}
