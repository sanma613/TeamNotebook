# 1294C — Product of Three Numbers

- Link: https://codeforces.com/problemset/problem/1294/C
- Rating: 1300 · Tags: `math`, `number theory`, `greedy`
- Topic: **divisor enumeration in O(sqrt n)**

## Problem in three lines

Given `n` (up to `10^9`), find three **pairwise distinct** integers `a, b, c`, each
`>= 2`, with `a * b * c = n`. Print `YES` and the triple, or `NO` if impossible.
Up to `100` queries.

## Observations

- `n <= 10^9`, `t <= 100`: an `O(sqrt n)` scan per query is `~31623 * 100 = 3 * 10^6`
  operations. Comfortable. Anything per-query worse than `O(sqrt n)` is suspicious.
- If `a * b * c = n` with all three `>= 2` and distinct, then the smallest one is at
  most `n^(1/3)`. But you do **not** need that bound — greedily taking the *smallest*
  divisor works and is easier to argue.

## Key insight

Take `a` = the **smallest** divisor of `n` that is `>= 2` (so `a` is prime, and
`a <= sqrt(n)`). Then take `b` = the smallest divisor of `m = n / a` that is `>= 2`
and `!= a`. Finally `c = m / b`. If `c` is `>= 2` and differs from both, you are done;
otherwise the answer is `NO`.

Why greedy is safe: making `a` and `b` as small as possible leaves `c` as large as
possible, which maximises the chance that `c` is distinct from the other two. If even
the greedy choice fails, no assignment works.

## Step by step

1. Scan `a` from `2` while `a * a <= n`, stop at the first divisor. If none, `n` is
   prime → `NO`.
2. Set `m = n / a`.
3. Scan `b` from `2` while `b * b <= m`, stop at the first divisor with `b != a`.
   If none → `NO`.
4. Set `c = m / b`.
5. Print `YES` and `a b c` if `c >= 2 && c != a && c != b`, else `NO`.

Worked example, `n = 64`: `a = 2`, `m = 32`, `b = 4` (skip `2`, it equals `a`),
`c = 8`. Distinct, all `>= 2` → `2 4 8`.

Worked example, `n = 8`: `a = 2`, `m = 4`, `b` scan finds nothing `!= 2` with
`b*b <= 4` → `NO`. Indeed `8 = 2*2*2` only.

## Implementation notes (C++)

- The loop bound must be `(ll)a * a <= n`, not `a <= sqrt(n)` — avoid floating point.
- `n` fits in `int` but intermediate products do not; use `long long` throughout.
- Step 3 scans divisors of `m`, not of `n`. Re-deriving `m` is the whole trick.
- Template: [`notebook/math/divisors.cpp`](../../notebook/math/divisors.cpp)

## Complexity

`O(sqrt n)` per query.

## Pitfalls

- Forgetting `b != a`. For `n = 12` the scan for `b` finds `2`, which equals `a`;
  if you accept it you output `2 2 3`, which is not pairwise distinct. The real
  answer for `12` is `NO` (the smallest distinct triple is `2*3*4 = 24`).
- Forgetting `c != a` and `c != b`. For `n = 30`: `a = 2`, `m = 15`, `b = 3`,
  `c = 5` — fine. But for `n = 2*3*3 = 18`: `a = 2`, `m = 9`, `b = 3`, `c = 3`,
  and `c == b`, so `NO`.
- Forgetting `c >= 2`, i.e. `c == 1`.

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
