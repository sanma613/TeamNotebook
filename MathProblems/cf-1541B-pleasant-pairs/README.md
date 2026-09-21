# 1541B — Pleasant Pairs

- Link: https://codeforces.com/problemset/problem/1541/B
- Rating: 1200 · Tags: `math`, `number theory`, `brute force`
- Topic: **harmonic-sum enumeration**

## Problem in three lines

Given an array `a[1..n]` of **pairwise distinct** integers with `1 <= a_i <= 2n`,
count the pairs `i < j` such that `a_i * a_j = i + j`.

## Observations

- `n` up to `10^5` and sum of `n` up to `2*10^5`: `O(n^2)` (`10^10`) is out.
- The right-hand side `i + j` is at most `2n`. So `a_i * a_j <= 2n` — the product is
  **tiny**. Any pair where `a_i * a_j > 2n` is instantly dead.
- The values are distinct and bounded by `2n`, which is the hint that the total work
  is a harmonic sum.

## Key insight

Fix `i`. The equation says `a_i` **divides** `i + j`, and `i + j <= 2n`.
So `i + j` ranges over the multiples of `a_i` that are at most `2n` — there are only
`2n / a_i` of them. Summing over all `i`, the total work is
`sum over i of 2n / a_i`. Because the `a_i` are **distinct** values in `[1, 2n]`,
that sum is bounded by `2n * (1 + 1/2 + 1/3 + ... )` = `O(n log n)`.

**The distinctness of the values is what makes this fast.** Without it, an array of
all `1`s would make every `i` cost `2n`.

## Step by step

1. Loop `i` from `1` to `n`.
2. Loop `s` over the multiples of `a_i`: `s = a_i, 2*a_i, 3*a_i, ...` while `s <= 2n`
   (you can start at `s > i`, since `j >= 1`).
3. Set `j = s - i`. Reject unless `j > i` and `j <= n` (this enforces `i < j` and
   counts each pair once).
4. If `a_i * a_j == s`, increment the answer.

Worked example, `a = [3, 1]` (1-indexed): `i = 1, a_1 = 3`, multiples of 3 up to 4
are `3`; `j = 3 - 1 = 2 <= n` and `j > i`; check `a_1 * a_2 = 3 * 1 = 3 = i + j`. ✓
Answer `1`.

## Implementation notes (C++)

- 1-indexing makes this much less painful. Read into `a[1..n]`.
- `a_i * a_j` fits in `int` (`<= 2n <= 4*10^5`) but use `long long` for the count.
- Multi-testcase: the sum of `n` is bounded, so per-test allocation is fine.

## Complexity

`O(n log n)` per test, thanks to distinctness.

## Pitfalls

- Counting each pair twice. Enforce `j > i` strictly, not `j != i`.
- Starting the multiple loop at `s = 0`.
- Forgetting `j <= n`.

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
