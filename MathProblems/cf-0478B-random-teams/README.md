# 478B — Random Teams

- Link: https://codeforces.com/problemset/problem/478/B
- Rating: 1300 · Tags: `combinatorics`, `greedy`, `constructive algorithms`
- Topic: **C(k,2) sums and extremal distributions**

## Problem in three lines

`n` participants are split into exactly `m` non-empty teams. Two people *become
friends* if they land in the same team. Print the **minimum** and **maximum** possible
number of friend pairs. `1 <= m <= n <= 10^9`.

## Observations

- A team of size `k` produces `C(k,2) = k*(k-1)/2` pairs. Total is
  `sum of C(k_i, 2)` subject to `sum k_i = n`, all `k_i >= 1`.
- `C(k,2)` is **convex** in `k`. Convex sums under a fixed total are maximised at the
  extremes and minimised when balanced. That single fact gives you both answers.
- `n` up to `10^9` means no loop over teams — closed form only.

## Key insight

- **Maximum**: pile everyone into one team, giving the other `m - 1` teams a single
  person each (they must be non-empty). One team of size `n - m + 1`:
  `max = C(n - m + 1, 2)`.
- **Minimum**: distribute as evenly as possible. With `q = n / m` and `r = n % m`,
  you get `r` teams of size `q + 1` and `m - r` teams of size `q`:
  `min = r * C(q+1, 2) + (m - r) * C(q, 2)`.

## Step by step

1. Read `n, m` as `long long`.
2. `maxAns = (n - m + 1) * (n - m) / 2`.
3. `q = n / m`, `r = n % m`.
4. `minAns = r * (q + 1) * q / 2 + (m - r) * q * (q - 1) / 2`.
5. Print `minAns` then `maxAns`.

Worked example, `n = 5, m = 1`: `max = C(5,2) = 10`; `q = 5, r = 0`,
`min = 1 * C(5,2) = 10`. Both `10` — only one split exists.

Worked example, `n = 3, m = 2`: `max = C(2,2) = 1`; `q = 1, r = 1`,
`min = 1 * C(2,2) + 1 * C(1,2) = 1 + 0 = 1`. Both `1`.

Worked example, `n = 6, m = 3`: `max = C(4,2) = 6`; `q = 2, r = 0`,
`min = 3 * C(2,2) = 3`.

## Implementation notes (C++)

- `C(10^9, 2) ≈ 5 * 10^17` — fits in `long long` (max `~9.2 * 10^18`), but nothing
  larger does. Do **not** compute `k * (k-1)` before dividing if `k` could be bigger.
  Here it is safe: `10^9 * 10^9 = 10^18 < 9.2 * 10^18`.
- Divide by 2 only after the multiply — `k * (k-1)` is always even, so this is exact.
- Template: [`notebook/math/combinatorics.cpp`](../../notebook/math/combinatorics.cpp)

## Complexity

`O(1)`.

## Pitfalls

- `int` overflow. This problem exists to punish `int`.
- `m == n`: every team has one person, `q = 1, r = 0`, `min = 0`; and
  `max = C(1,2) = 0`. Both zero — verify your formula does not go negative.
- `m == 1`: `min == max`.

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
