# 600B — Queries about less or equal elements

- Link: https://codeforces.com/problemset/problem/600/B
- Rating: 1300 · Tags: `data structures`, `binary search`, `sortings`, `two pointers`
- Topic: **sort + `upper_bound`**

## Problem in three lines

Given arrays `a` (size `n`) and `b` (size `m`), for each `b_j` print how many elements
of `a` are **less than or equal to** `b_j`.

## Observations

- `n, m` up to `2*10^5` → `O(n*m)` is `4*10^10`, out.
- The queries are independent and only ask "how many are `<= x`". That is a prefix
  count on a sorted array — binary search, nothing more.

## Key insight

Sort `a` once. Then "number of elements `<= x`" is exactly
`upper_bound(a.begin(), a.end(), x) - a.begin()`.

`upper_bound` finds the first element **strictly greater** than `x`; its distance from
the start is the count of elements `<= x`. If you want strictly-less-than, that is
`lower_bound`. Getting these two the right way round is the whole problem.

## Step by step

1. Read `a`, sort it — `O(n log n)`.
2. For each `b_j`, print `upper_bound(a, b_j) - a.begin()`.

Worked example, `a = [1, 3, 5, 7, 9]`, `b = [6, 4, 2, 8]`:
`<= 6` → 3 (`1,3,5`); `<= 4` → 2; `<= 2` → 1; `<= 8` → 4. Output `3 2 1 4`.

## Alternative: two pointers

Sort `b` too (keeping original positions), then sweep both arrays with one pointer
each — `O((n + m) log(n + m))` with no binary search. Not faster here, and it costs
you an index-restoring step. Binary search is the lazy correct choice.

## Implementation notes (C++)

- Values can be **negative** (down to `-10^9`). Nothing breaks, but do not assume
  non-negative and reach for a counting array.
- Output with `'\n'` or spaces per the statement; buffer it (`ios_base::sync_with_stdio(false)`)
  or `2*10^5` prints will crawl.
- Template: the `upper_bound`/`lower_bound` recipes are in
  [`docs/ds-cheatsheet.md`](../../docs/ds-cheatsheet.md).

## Complexity

`O((n + m) log n)`.

## Pitfalls

- `lower_bound` vs `upper_bound`. With `a = [5]` and `x = 5`: `upper_bound` gives
  count 1 (correct, `5 <= 5`), `lower_bound` gives 0 (wrong).
- Forgetting to sort `a`.

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
