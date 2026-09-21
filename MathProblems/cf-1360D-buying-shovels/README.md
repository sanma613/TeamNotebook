# 1360D — Buying Shovels

- Link: https://codeforces.com/problemset/problem/1360/D
- Rating: 1300 · Tags: `math`, `number theory`
- Topic: **divisor enumeration in O(sqrt n)**

## Problem in three lines

You need **exactly** `n` shovels. The shop sells packages in `k` different sizes:
`1, 2, ..., k`. You must buy any number of packages, but all of the **same size**.
Minimise the number of packages. `n, k <= 10^9`, up to `100` queries.

## Observations

- "All packages the same size `d`, total exactly `n`" means `d` divides `n` and you
  buy `n / d` packages.
- To minimise `n / d` you want the **largest** valid `d`, and `d` must satisfy
  `d <= k`.
- `k` can be `>= n`, in which case `d = n` and the answer is `1`.

## Key insight

The answer is `min { n / d : d divides n and d <= k }`.
Divisors come in pairs `(d, n/d)` around `sqrt(n)`, so enumerating `d` from `1` to
`sqrt(n)` gives you **every** divisor in `O(sqrt n)`.

## Step by step

1. Set `best = n` (always achievable with `d = 1`, since `k >= 1`).
2. For `d = 1` while `d * d <= n`:
   - if `n % d != 0`, skip.
   - `d` is a divisor: if `d <= k`, try `best = min(best, n / d)`.
   - `n / d` is the paired divisor: if `n / d <= k`, try `best = min(best, d)`.
3. Print `best`.

Worked example, `n = 8, k = 7`: divisors are `1, 2, 4, 8`. Those `<= 7` are
`1, 2, 4`; the largest is `4`, so `8 / 4 = 2` packages.

Worked example, `n = 6, k = 10`: `6 <= 10`, so one package of size 6 → `1`.

## Implementation notes (C++)

- `d * d <= n` with `d` as `long long`, to avoid `int` overflow at `n = 10^9`
  (`31623^2` fits in `int`, but the habit costs nothing).
- Do **not** loop `d` from `1` to `k` — `k` is up to `10^9`.
- Template: [`notebook/math/divisors.cpp`](../../notebook/math/divisors.cpp)

## Complexity

`O(sqrt n)` per query.

## Pitfalls

- Handle the pair `(d, n/d)` in both directions. If you only check `d <= k` you miss
  the case where the *large* divisor is the one under `k`... and if you only check
  `n/d <= k` you miss the symmetric case. Check both every iteration.
- When `n` is a perfect square, `d == n/d` — checking twice is harmless here because
  you are taking a `min`.

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
