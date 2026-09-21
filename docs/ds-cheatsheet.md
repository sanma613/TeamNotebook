# Data structures cheatsheet

## Pick the cheapest thing that works

| Need | Structure | Build | Query | Update |
|---|---|---|---|---|
| Static range sum | prefix sums | `O(n)` | `O(1)` | — |
| Static range min/max/gcd | sparse table | `O(n log n)` | `O(1)` | — |
| Range add, point read | difference array | `O(n)` | `O(1)` | `O(1)` |
| Point add, prefix sum | Fenwick (BIT) | `O(n)` | `O(log n)` | `O(log n)` |
| Point set, range anything | segment tree | `O(n)` | `O(log n)` | `O(log n)` |
| Range add, range sum | segment tree with lazy / two BITs | `O(n)` | `O(log n)` | `O(log n)` |
| Connectivity, merging groups | DSU | `O(n)` | `~O(1)` | `~O(1)` |
| k-th smallest, rank of a value | pbds `ordered_set` | — | `O(log n)` | `O(log n)` |
| "how many `<= x`" on a fixed array | sort + `upper_bound` | `O(n log n)` | `O(log n)` | — |

**Go down this table, not up.** Most 1200–1500 "data structures" problems are a
prefix sum or a `std::map`, not a segment tree.

## When you see X, reach for Y

| In the statement | Reach for | Template |
|---|---|---|
| condition mixes `a_i` and the index `i` | move the index into the value (`a_i - i`), then group | — |
| condition mixes two arrays (`a_i + a_j > b_i + b_j`) | collapse to `c_i = a_i - b_i` | — |
| "count pairs with property P" | frequency map + `C(c,2)`, or sort + two pointers | `notebook/math/combinatorics.cpp` |
| "reorder the array to maximise ..." | count how often each position is used, then rearrangement inequality | `notebook/structures/prefix_sums.cpp` |
| many range `[l, r]` updates, one final read | difference array | `notebook/structures/prefix_sums.cpp` |
| "split into k parts with equal sums" | prefix sums + counting in one pass | `notebook/structures/prefix_sums.cpp` |
| "register / deduplicate names" | `map<string,int>` | — |
| grid rectangle sums | 2D prefix sums | `notebook/structures/prefix_sums.cpp` |

## `lower_bound` vs `upper_bound` (on a sorted range)

| You want | Write | Count via |
|---|---|---|
| first element `>= x` | `lower_bound(b, e, x)` | elements `< x` = `lower_bound - b` |
| first element `> x` | `upper_bound(b, e, x)` | elements `<= x` = `upper_bound - b` |
| elements in `[l, r]` | — | `upper_bound(r) - lower_bound(l)` |
| does `x` exist | `binary_search(b, e, x)` | — |

On a `std::set` / `std::map`, use the **member** `s.lower_bound(x)`, not `std::lower_bound`
— the free function is `O(n)` on a node-based container.

## Two pointers

Valid when the predicate is **monotone** as a pointer moves. Typical shape for
"count pairs with `c_i + c_j > 0`" on a sorted array:

```cpp
int l = 0, r = n - 1;
while (l < r) {
    if (c[l] + c[r] > 0) { ans += r - l; r--; }  // c[r] works with all of [l, r-1]
    else                   l++;                  // c[l] is too small for anything
}
```

## Traps

- Answers that count pairs reach `C(2*10^5, 2) ≈ 2*10^10` → **`long long`**.
- Difference array must be sized `n + 2` so `d[r+1]` is in bounds.
- Query the map **before** inserting the current element, or you count `i == j`.
- `map::operator[]` inserts a default-constructed value on a miss. Use `find` for
  pure lookups.
- `unordered_map` can be anti-hash-tested on Codeforces. Use `map`, or add a random
  salt to your hash.
