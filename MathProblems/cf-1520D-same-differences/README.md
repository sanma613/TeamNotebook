# 1520D — Same Differences

- Link: https://codeforces.com/problemset/problem/1520/D
- Rating: 1200 · Tags: `data structures`, `hashing`, `math`
- Topic: **rewrite the condition into an invariant, then count with a map**

## Problem in three lines

Given an array `a[0..n-1]`, count the pairs `i < j` with `a_j - a_i == j - i`.

## Observations

- `n` up to `2*10^5` per test, sum bounded: `O(n^2)` is out.
- The condition mixes values and indices. Whenever that happens, try to move
  everything that depends on `i` to one side and everything on `j` to the other.

## Key insight

`a_j - a_i = j - i`  ⟺  `a_j - j = a_i - i`.

Define `key_i = a_i - i`. The condition becomes "**two elements have the same key**".
Counting pairs with equal keys is a frequency map plus `C(c, 2)` per group.

This "move the index into the value" rewrite is one of the highest-value tricks at
this rating. See also [1324D](../cf-1324D-pair-of-topics/README.md), which does the
same thing to a different condition.

## Step by step

1. Build `key_i = a_i - i` for every `i`.
2. Count occurrences of each key in a `map<long long,long long>`.
3. Answer is `sum over groups of C(c, 2) = c*(c-1)/2`.

(Equivalently, one pass: for each `i`, add the count of `key_i` seen so far, then
increment it. Same result, no second loop.)

Worked example, `a = [1, 2, 3]` (0-indexed): keys `1-0=1, 2-1=1, 3-2=1`.
One group of size 3 → `C(3,2) = 3` pairs. All three pairs work, since the array is
an arithmetic run of step 1. ✓

Worked example, `a = [1, 2, 4]`: keys `1, 1, 2`. → `C(2,2) + C(1,2) = 1 + 0 = 1`.

## Implementation notes (C++)

- `a_i` can be up to `10^9` and `i` up to `2*10^5`, so `key` fits in `int` — but the
  **answer** is up to `C(2*10^5, 2) ≈ 2*10^10` and needs `long long`.
- Use 0-indexing or 1-indexing consistently; the key differs by a constant between
  the two, which does not change the grouping.

## Complexity

`O(n log n)` per test.

## Pitfalls

- `long long` for the answer.
- Using `a_i + i` instead of `a_i - i`. Re-derive the algebra rather than guessing.

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
