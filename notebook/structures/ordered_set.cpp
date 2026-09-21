// GNU pbds ordered set: a std::set that also answers "how many are smaller than x"
// and "what is the k-th smallest", both in O(log n).
// GCC only. Works on Codeforces; will not compile with clang or MSVC.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

// For DUPLICATES, store pair<value, unique_id> instead, or use less_equal<T> as the
// comparator - but then find() and erase(value) stop working. The pair trick is safer.
template <class T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag,
                              tree_order_statistics_node_update>;

void demo()
{
    ordered_set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);

    assert(s.order_of_key(20) == 1);   // how many elements are strictly < 20
    assert(*s.find_by_order(0) == 10); // 0-indexed k-th smallest
    assert(s.order_of_key(25) == 2);   // works for values not in the set
}
