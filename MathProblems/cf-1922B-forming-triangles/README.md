# 1922B — Forming Triangles

- Link: https://codeforces.com/problemset/problem/1922/B
- Rating: 1200 · Tags: `combinatorics`, `math`, `sortings`
- Topic: **counting triples by group, nC2 / nC3**

## Problem in three lines

You have `n` sticks; stick `i` has length `2^{a_i}` with `0 <= a_i <= n`. Count the
triples of sticks that form a **non-degenerate** triangle.

## Observations

- Lengths are powers of two. That is not decoration — it collapses the triangle
  inequality into a single, very rigid condition.
- `n` up to `3*10^5`, so you count by **group** (by exponent), never by triple.

## Key insight

Take exponents `x <= y <= z`. The triangle inequality that can fail is
`2^x + 2^y > 2^z`.

If `y < z`, then `y <= z - 1` and `x <= z - 1`, so
`2^x + 2^y <= 2^{z-1} + 2^{z-1} = 2^z`, which is **not** greater. Fails.

So a valid triple must have **`y == z`**: the two largest exponents are equal.
And then `2^x + 2^z > 2^z` holds for any `x`, automatically.

**A triple is valid iff its two largest sticks have the same length.**

## Step by step

1. Count occurrences `cnt[v]` of each exponent `v` in `0..n`.
2. Sweep `v` from `0` upward, maintaining `below` = number of sticks with exponent
   strictly less than `v`.
3. For each `v` add:
   - `C(cnt[v], 2) * below` — two sticks of exponent `v` plus one strictly smaller;
   - `C(cnt[v], 3)` — all three of exponent `v` (an equilateral triangle, always valid).
4. Then `below += cnt[v]`.

Worked example, `a = [1, 1, 1]`: `cnt[1] = 3`, `below = 0`.
`C(3,2)*0 + C(3,3) = 0 + 1 = 1`. One equilateral triangle. ✓

Worked example, `a = [0, 1, 1]`: at `v = 0`, `cnt = 1`, contributes `0`; `below = 1`.
At `v = 1`, `C(2,2)*1 + C(2,3) = 1*1 + 0 = 1`. Sticks `1, 2, 2` → `1 + 2 > 2` ✓.

Worked example, `a = [0, 0, 1]`: at `v = 0`, `C(2,2)*0 + 0 = 0`; `below = 2`.
At `v = 1`, `cnt = 1`, `C(1,2) = 0`, `C(1,3) = 0` → total `0`.
Sticks `1, 1, 2` → `1 + 1 = 2`, degenerate. ✓

## Implementation notes (C++)

- `C(k,2) = k*(k-1)/2`, `C(k,3) = k*(k-1)*(k-2)/6`. Compute in `long long`:
  with `k = 3*10^5`, `k^3 ≈ 2.7*10^16` — fits, but only in 64-bit.
- Exponents are bounded by `n`, so a plain `vector<ll> cnt(n+1)` is the counting
  structure. No map needed, no sorting needed.
- Template: [`notebook/math/combinatorics.cpp`](../../notebook/math/combinatorics.cpp)

## Complexity

`O(n)` per test.

## Pitfalls

- Forgetting the all-three-equal case `C(cnt,3)`.
- Using `below` **after** adding `cnt[v]` — then you count `v` as "strictly smaller
  than `v`" and overcount badly. Add to `below` last.
- 32-bit overflow in `C(k,3)`.

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
