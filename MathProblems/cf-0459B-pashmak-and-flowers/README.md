# 459B — Pashmak and Flowers

- Link: https://codeforces.com/problemset/problem/459/B
- Rating: 1300 · Tags: `combinatorics`, `sortings`, `implementation`
- Topic: **counting by frequency, the all-equal edge case**

## Problem in three lines

Given `n` flowers with beauty values `b_i`, choose two flowers so that the
**difference** in beauty is as large as possible. Print that maximum difference and
the **number of ways** to pick such a pair.

## Observations

- The maximum difference is obviously `max(b) - min(b)`. The interesting half is the
  count.
- `n` up to `2*10^5`, answer count up to `C(n,2) ≈ 2*10^10` → `long long`.

## Key insight

Two cases, and the second one is where everybody loses the problem:

- **If `max != min`**: any pair consisting of one maximum-valued flower and one
  minimum-valued flower works, and nothing else does.
  `ways = cntMax * cntMin`.
- **If `max == min`** (all values identical): the maximum difference is `0`, and
  **every** pair achieves it. `ways = C(n, 2) = n*(n-1)/2`.

The all-equal case is not a degenerate rounding detail — `cntMax * cntMin` would give
`n * n`, which is wrong (it counts ordered pairs and pairs an element with itself).

## Step by step

1. Read the array, find `mn = min`, `mx = max`.
2. Count `cntMin` = occurrences of `mn`, `cntMax` = occurrences of `mx`.
3. If `mn == mx`, print `0` and `n*(n-1)/2`.
4. Otherwise print `mx - mn` and `cntMin * cntMax`.

Worked example, `b = [1, 2, 3, 4]`: `mx - mn = 3`, `cntMax = cntMin = 1` → `3 1`.
Worked example, `b = [1, 1, 1]`: all equal → `0 3`.
Worked example, `b = [1, 4, 5, 5, 1]`: diff `4`, `cntMin = 2`, `cntMax = 2` → `4 4`.

## Implementation notes (C++)

- One pass with `min_element` / `max_element` then `count` is fine; or a single manual
  pass. No sorting required — `O(n)` beats `O(n log n)` and is shorter.
- `long long` for the count.

## Complexity

`O(n)`.

## Pitfalls

- The all-equal case. Test `n = 2, b = [7, 7]` → `0 1`.
- Using `int` for `n*(n-1)/2`.

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
