# 276C — Little Girl and Maximum Sum

- Link: https://codeforces.com/problemset/problem/276/C
- Rating: 1500 · Tags: `data structures`, `greedy`, `sortings`, `implementation`
- Topic: **difference array + rearrangement inequality**

## Problem in three lines

You have an array of `n` numbers and `q` queries `[l, r]`. You may **reorder the array
however you like**, once, before answering. Maximise the sum of all query sums.

## Observations

- `n, q` up to `2*10^5`. Running each query is `O(n)` each → `4*10^10`, out.
- The array is reorderable, so positions are interchangeable. What matters about a
  position is only **how many queries cover it**.

## Key insight

Two independent halves:

1. **How often is each position used?** Position `p` contributes `value * freq[p]`
   where `freq[p]` is the number of queries covering `p`. Computing `freq` for all
   positions is a classic **difference array**: `d[l] += 1`, `d[r+1] -= 1`, then take
   the prefix sum.
2. **Which value goes where?** To maximise `sum(value[p] * freq[p])`, pair the largest
   value with the largest frequency. That is the **rearrangement inequality**: sort
   both descending and take the dot product.

## Step by step

1. Read the array `a`; sort it **descending**.
2. `vector<ll> d(n + 2, 0)`; for each query `(l, r)` (1-indexed): `d[l]++`, `d[r+1]--`.
3. Prefix-sum `d` into frequencies `f[1..n]`.
4. Sort `f` **descending**.
5. Answer `= sum of a[i] * f[i]` over the sorted arrays.

Worked example, `n = 3, a = [5, 3, 2]`, queries `[1,2], [2,3], [1,3]`:
`d` gives `f = [2, 3, 2]` → sorted desc `[3, 2, 2]`. `a` desc `[5, 3, 2]`.
Dot product `5*3 + 3*2 + 2*2 = 15 + 6 + 4 = 25`.

## Implementation notes (C++)

- Size the difference array `n + 2` so `d[r+1]` with `r = n` does not write out of
  bounds. This is the single most common runtime error on this problem.
- **`long long` everywhere.** Worst theoretical case: all `q` queries cover the whole
  array, giving `q * sum(a) = 2*10^5 * (2*10^5 * 10^9) = 4*10^19`, which is **larger
  than `int64` can hold** (`~9.2*10^18`). `long long` is what passes in practice and
  what everyone submits; if that bound makes you uneasy, `unsigned long long` (up to
  `1.8*10^19`) or `__int128` for the accumulator costs you nothing here. Re-read the
  statement's exact constraint on `a_i` before deciding.
- Input is 1-indexed in the statement. Keep it 1-indexed in code and do not translate.
- Template: [`notebook/structures/prefix_sums.cpp`](../../notebook/structures/prefix_sums.cpp)

## Complexity

`O((n + q) + n log n)`.

## Pitfalls

- `d[r+1]` out of bounds.
- Sorting one array ascending and the other descending — that **minimises** the sum.
- Reading `q` queries but building frequencies with a nested loop (`O(nq)`, TLE).

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
