// algo/algostuff.hpp

#ifndef ALGOSTUFF_HPP
#define ALGOSTUFF_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>

/*print()
 *-prints optional C-string optcstr followed by
 *-all elements of the collection coll
 *-separated by spaces
 */
template<typename T>
inline void print(const T& coll, const char* optcstr = "") {
	typename T::const_iterator pos;
	std::cout << optcstr;
	for (pos = coll.begin(); pos != coll.end(); ++pos) {
		std::cout << *pos << ' ';
	}
	std::cout << std::endl;
}

/*insert(collection, first, last)
 *-fill values from first to last into the collection
 *-NOTE: NO half-open range
 */
template<typename T>
inline void insert(T& coll, int first, int last) {
	for (int i = first; i <= last; ++i) {
		coll.insert(coll.end(), i);
	}
}

#endif /*ALGOSTUFF_HPP*/
