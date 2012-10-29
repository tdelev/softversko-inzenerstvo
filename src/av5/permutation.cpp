#include "algostuff.hpp"
using namespace std;
int main() {
	vector<int> coll;
	insert(coll, 1, 3);
	print(coll, "on entry: ");
	/*permute elements until they are sorted
	 *-runs through all permutations because the elements are sorted now*/
	while (next_permutation(coll.begin(), coll.end())) {
		print(coll, " ");
	}
	print(coll, "afterward: ");
	/*permute until descending sorted
	 *-this is the next permutation after ascending sorting
	 *-so the loop ends immediately
	 */
	while (prev_permutation(coll.begin(), coll.end())) {
		print(coll, " ");
	}
	print(coll, "now: ");
	/*permute elements until they are sorted in descending order
	 *-runs through all permutations because the elements are sorted
	 * in descending order now
	 */
	while (prev_permutation(coll.begin(), coll.end())) {
		print(coll, " ");
	}
	print(coll, "afterward: ");
	return 0;
}
