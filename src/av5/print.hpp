// print elements of an STL container
template<typename T>
void print(T const& coll) {
	typename T::const_iterator pos; // iterator to iterate over coll
	typename T::const_iterator end(coll.end()); // end position

	for (pos = coll.begin(); pos != end; ++pos) {
		std::cout << *pos << ' ';
	}
	std::cout << std::endl;
}

// print elements of an STL container
template<typename T>
void print(T const& coll, const char* prefix) {
	typename T::const_iterator pos; // iterator to iterate over coll
	typename T::const_iterator end(coll.end()); // end position
	std::cout << prefix << std::endl;
	for (pos = coll.begin(); pos != end; ++pos) {
		std::cout << *pos << ' ';
	}
	std::cout << std::endl;
}
