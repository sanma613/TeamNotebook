# 1324D — Pair of Topics

- Link: https://codeforces.com/problemset/problem/1324/D
- Rating: 1400 · Tags: `data structures`, `binary search`, `sortings`, `two pointers`
- Topic: **collapse two arrays into one, then two pointers**

## Problem in three lines

Given arrays `a` and `b` of length `n`, count the pairs `i < j` with
`a_i + a_j > b_i + b_j`.

## Observations

- `n` up to `2*10^5` → no `O(n^2)`.
- The condition couples `i` and `j` across two arrays. Same move as
  [1520D](../cf-1520D-same-differences/README.md): separate the indices.

## Key insight

`a_i + a_j > b_i + b_j`  ⟺  `(a_i - b_i) + (a_j - b_j) > 0`.

Define `c_i = a_i - b_i`. The problem becomes: **count pairs `i < j` with
`c_i + c_j > 0`** — a single array, one condition. Because the condition is symmetric
in `i` and `j`, the original index order stops mattering and you are free to **sort**
`c`.

## Step by step

1. Build `c_i = a_i - b_i` and sort `c` ascending.
2. Two pointers: `l = 0`, `r = n - 1`.
3. While `l < r`:
   - if `c[l] + c[r] > 0`, then `c[r]` pairs with **every** index in `[l, r-1]`
     (all of them are `>= c[l]`), so add `r - l` to the answer and do `r--`;
   - else `c[l]` is too small to pair with anything up to `r`, so `l++`.
4. Print the answer.

Worked example, `c = [-2, -1, 1, 3]`: `l=0, r=3`: `-2+3 = 1 > 0` → add `3`, `r=2`.
`l=0, r=2`: `-2+1 = -1` → `l=1`. `l=1, r=2`: `-1+1 = 0`, not `> 0` → `l=2`. Stop.
Answer `3`. Check by hand: pairs summing `> 0` are `(-2,3), (-1,3), (1,3)` → 3. ✓

## Alternative: sort + binary search

For each `i`, count `j > i` with `c_j > -c_i` via `upper_bound` on the sorted array,
then correct for self-pairing and halve. Same complexity, more fiddly off-by-ones.
Two pointers is the cleaner write-up.

## Implementation notes (C++)

- `a_i, b_i` up to `10^9`, so `c_i` lives in `[-10^9, 10^9]` — `int` is fine, but
  `c_i + c_j` reaches `2*10^9` and **overflows `int`**. Use `long long` for the sum,
  or store `c` as `long long` outright.
- Answer up to `C(2*10^5, 2) ≈ 2*10^10` → `long long`.
- Strict `>`, not `>=`. `c = [0, 0]` gives answer `0`.

## Complexity

`O(n log n)` for the sort, `O(n)` for the sweep.

## Pitfalls

- 32-bit overflow in `c[l] + c[r]`. This is the intended trap of the problem.
- Adding `r - l + 1` instead of `r - l` (that would include pairing `r` with itself).
- Using `>=`.

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
