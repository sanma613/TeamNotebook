# 1931D — Divisible Pairs

- Link: https://codeforces.com/problemset/problem/1931/D
- Rating: 1300 · Tags: `math`, `number theory`, `combinatorics`
- Topic: **counting pairs with a hash map on a key**

## Problem in three lines

Given `n`, `x`, `y` and an array `a`, count pairs `i < j` that are *beautiful*:
`(a_i + a_j)` is divisible by `x` **and** `(a_i - a_j)` is divisible by `y`.

## Observations

- `n` up to `2*10^5`, so `O(n^2)` is out. Pair counting at this size is almost always
  "map from a key to a frequency".
- Both conditions are modular and independent. That means the key is a **pair** of
  residues.

## Key insight

Rewrite both conditions as an exact requirement on `a_j` given `a_i`:

- `(a_i + a_j) % x == 0`  ⟺  `a_j % x == (x - a_i % x) % x`
- `(a_i - a_j) % y == 0`  ⟺  `a_j % y == a_i % y`

So while scanning left to right, for each `a_j` you need the number of **earlier**
elements whose key `(a % x, a % y)` equals `((x - a_j % x) % x, a_j % y)`.

## Step by step

1. Keep `map<pair<int,int>, int> seen`, from key `(a % x, a % y)` to how many times
   it has appeared so far.
2. For each element `a_j`:
   - compute the *complementary* key `((x - a_j % x) % x, a_j % y)`;
   - add `seen[complement]` to the answer;
   - then insert `a_j`'s own key `(a_j % x, a_j % y)` into `seen`.
3. Print the answer.

Inserting **after** querying is what enforces `i < j` and counts each pair exactly once.

Worked example, `n = 2, x = 2, y = 3, a = [1, 5]`:
`a_1` key `(1, 1)`, nothing seen, insert. `a_2 = 5`: complement is
`((2 - 5%2)%2, 5%3) = (1, 2)`. `seen` has `(1,1)`, no match → `0`.
Check by hand: `1 + 5 = 6`, divisible by 2 ✓; `1 - 5 = -4`, not divisible by 3 ✗.
Correctly `0`.

## Implementation notes (C++)

- The `(x - a % x) % x` outer `% x` matters: if `a % x == 0`, the complement must be
  `0`, not `x`.
- `map<pair<int,int>,int>` is `O(log n)` per op and fast enough. An
  `unordered_map` needs a custom hash for `pair` — not worth it in contest.
- Answer up to `C(2*10^5, 2) ≈ 2*10^10` → **`long long`**.

## Complexity

`O(n log n)` per test.

## Pitfalls

- `long long` for the answer. This is the single most common wrong-answer here.
- Inserting before querying (counts `i == j` and double-counts).
- Forgetting the outer modulo on the complement.

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
