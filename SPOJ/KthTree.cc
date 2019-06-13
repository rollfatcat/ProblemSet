/* has not any function to find the k-th smallest minimum or find the index of an element,
 * bust there is a data structure in C++ with does it in O(log(n))(also contains all set functions), tree
 */

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	ordered_set<int>  s;
	s.insert(1);
	s.insert(3);
	cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2
	cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based)
}
