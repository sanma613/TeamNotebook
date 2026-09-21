# 1352C — K-th Not Divisible by n

- Link: https://codeforces.com/problemset/problem/1352/C
- Rating: 1200 · Tags: `math`, `binary search`
- Topic: **counting / closed form**

## Problem in three lines

Given `n` and `k` (both up to `10^9`, `n >= 2`), find the `k`-th smallest **positive**
integer that is **not** divisible by `n`. Up to `1000` queries.

## Observations

- `k` up to `10^9` and many queries: you cannot loop over the integers. The answer is
  either a formula or a binary search.
- The non-multiples come in blocks: between consecutive multiples of `n` there are
  exactly `n - 1` of them.

## Key insight

In every block of `n` consecutive integers `[1..n], [n+1..2n], ...` exactly `n - 1`
numbers survive. So the `k`-th survivor sits in block number `b = ceil(k / (n-1))`,
and you have skipped exactly `b - 1`... but it is cleaner to say:

**answer = `k + (number of multiples of n that are <= answer)`** and the number of
multiples skipped before the `k`-th survivor is `(k - 1) / (n - 1)` (integer division).

So: `answer = k + (k - 1) / (n - 1)`.

## Step by step

1. If the `k`-th survivor is `x`, then among `1..x` there are `x - floor(x/n)`
   survivors, and we want that to equal `k`.
2. Walk it block by block: each full block of `n` numbers contributes `n - 1`
   survivors and consumes one multiple. After `k` survivors you have consumed
   `floor((k - 1) / (n - 1))` multiples — the `-1` is because the survivor exactly
   at position `k` must not itself be counted as closing a block.
3. Therefore `answer = k + (k - 1) / (n - 1)`.

Sanity check by hand, `n = 3`: survivors are `1, 2, 4, 5, 7, 8, 10, ...`
`k = 7` → `7 + 6/2 = 7 + 3 = 10`. Correct.

## Alternative: binary search

If the formula does not come to you in contest, binary search on `x` with the
monotone predicate `x - x/n >= k`. `O(log(2k))` per query, always safe. Both are in
the solution file.

## Implementation notes (C++)

- Use `long long`. With `n = 2, k = 10^9` the answer is `~2 * 10^9`, which overflows
  a signed 32-bit `int`.
- `n >= 2` is guaranteed, so `n - 1` is never zero — but if you binary search, keep
  the upper bound at `2 * k` and you never have to think about it.

## Complexity

`O(1)` per query with the formula, `O(log k)` with binary search.

## Pitfalls

- `(k - 1) / (n - 1)`, not `k / (n - 1)`. Test `n = 2, k = 1`: formula gives `1`
  (correct); `k / (n-1)` would give `2`.
- `int` overflow, as above.

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
