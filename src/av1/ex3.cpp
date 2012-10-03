inline int const& maximum(int const& a, int const& b) {
	return a < b ? b : a;
}
// maximum of two values of any type
template<typename T>
inline T const& maximum(T const& a, T const& b) {
	return a < b ? b : a;
}
// maximum of three values of any type
template<typename T>
inline T const& maximum(T const& a, T const& b, T const& c) {
	return maximum(maximum(a, b), c);
}
int main() {
	::maximum(7, 42, 68); // calls the template for three arguments
	::maximum(7.0, 42.0); // calls max<double> (by argument deduction)
	::maximum('a', 'b'); // calls max<char> (by argument deduction)
	::maximum(7, 42); // calls the nontemplate for two ints
	::maximum<>(7, 42); // calls max<int> (by argument deduction)
	::maximum<double>(7, 42); // calls max<double> (no argument deduction)
	::maximum('a', 42.7); // calls the nontemplate for two ints
	return 0;
}
