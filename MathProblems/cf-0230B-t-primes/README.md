# 230B — T-primes

- Link: https://codeforces.com/problemset/problem/230/B
- Rating: 1300 · Tags: `math`, `number theory`, `binary search`, `implementation`
- Topic: **sieve of Eratosthenes**

## Problem in three lines

You are given `n` numbers `x` (up to `10^12`). A number is a *T-prime* if it has
**exactly three** distinct positive divisors. For each number print `YES` or `NO`.

## Observations

- `n` is up to `10^5` and `x` up to `10^12`, so you get roughly one cheap test per
  number. Factorizing each `x` by trial division up to `10^6` would be `10^5 * 10^6`
  operations — far too slow. The constraints are telling you to precompute once.
- Divisors come in pairs `(d, x/d)`. An odd number of divisors means `x` is a perfect
  square. Three is odd, so `x = y^2` for some integer `y`.

## Key insight

`x` has exactly 3 divisors **iff** `x = p^2` for a prime `p`.
The divisors are then `1, p, p^2` — exactly three.

Proof sketch: if `x = p^2`, its divisors are `1, p, p^2`. Conversely a number with
exactly 3 divisors is a perfect square (odd divisor count), say `x = y^2`; if `y` were
composite, `y = ab` with `1 < a <= b < y`, then `1, a, y, x` are already four distinct
divisors. So `y` must be prime.

## Step by step

1. `x <= 10^12`, so `sqrt(x) <= 10^6`. Sieve all primes up to `10^6` once — `O(N log log N)`.
2. For each query `x`, compute `y = round(sqrt(x))`.
3. Reject if `y * y != x` (not a perfect square) → `NO`.
4. Otherwise answer `YES` iff `y` is prime according to the sieve.

## Implementation notes (C++)

- Read `x` as `long long`. `10^12` overflows `int`.
- `sqrtl(x)` on a `long long` can be off by one because of floating point. Always
  correct it: take `y = (long long)sqrtl(x)`, then nudge `y` down while `y*y > x` and
  up while `(y+1)*(y+1) <= x`. Never trust the raw cast.
- `vector<bool>` for the sieve is fine here (10^6 bits), and cache-friendly.
- Template: [`notebook/math/sieve.cpp`](../../notebook/math/sieve.cpp)

## Complexity

Precompute `O(10^6 log log 10^6)`, then `O(1)` per query.

## Pitfalls

- `1` is not a T-prime (one divisor). The perfect-square check gives `y = 1`, and the
  sieve must mark `1` as **not** prime. Check your sieve does.
- `4` is the smallest T-prime (`2^2`).
- Using `sqrt()` (double) instead of `sqrtl` loses precision near `10^12`.

## Worked examples

| x | y = sqrt(x) | square? | y prime? | answer |
|---|---|---|---|---|
| 4 | 2 | yes | yes | YES |
| 5 | 2 | no | — | NO |
| 6 | 2 | no | — | NO |
| 1 | 1 | yes | no | NO |
| 999966000289 | 999983 | yes | yes | YES |

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
