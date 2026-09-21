# 1881D — Divide and Equalize

- Link: https://codeforces.com/problemset/problem/1881/D
- Rating: 1300 · Tags: `math`, `number theory`
- Topic: **prime factorization with a smallest-prime-factor sieve**

## Problem in three lines

Given `n` numbers (each up to `10^6`), you may repeatedly pick `i != j` and a divisor
`d` of `a_i`, then set `a_i /= d` and `a_j *= d`. Decide whether you can make all `n`
numbers equal.

## Observations

- The operation moves a factor from one element to another. **The product of the whole
  array never changes** — that is the invariant, and invariants are the whole game in
  these problems.
- "All equal to `v`" means `v^n = product`. So the product must be a perfect `n`-th
  power.
- The product is astronomically large (`(10^6)^(10^4)`), so you can never compute it.
  You must work in the exponent space.

## Key insight

Factor every `a_i` and accumulate the **total exponent of each prime** across the
whole array. The answer is `YES` **iff every total exponent is divisible by `n`**.

Why sufficient: if prime `p` has total exponent `e = n * q`, you can freely shuttle
copies of `p` around until each element holds exactly `q` of them. The operations let
you move any divisor anywhere, so the primes are independent and unconstrained.

## Step by step

1. Sieve a **smallest prime factor** (SPF) table up to `10^6`, once for all tests.
2. For each `a_i`, repeatedly divide by `spf[a_i]` to read off its prime exponents in
   `O(log a_i)`.
3. Accumulate exponents into a hash map `prime -> total exponent`.
4. Answer `YES` iff every value in the map is `% n == 0`.

Worked example, `n = 2, a = [4, 9]`: exponents `2 -> 2`, `3 -> 2`. Both divisible by
`2` → `YES` (target `6`, product `36 = 6^2`).

Worked example, `n = 2, a = [2, 3]`: `2 -> 1`, `3 -> 1`. Not divisible by `2` → `NO`.

## Implementation notes (C++)

- Build the SPF table **once**, outside the testcase loop. Rebuilding it per test is
  the classic TLE here.
- Use `unordered_map<int,int>` (or a plain array of size `10^6 + 1` that you clear
  only on the primes you touched — clearing the whole array per test is `O(10^6 * t)`
  and too slow).
- Template: [`notebook/math/sieve.cpp`](../../notebook/math/sieve.cpp) — the SPF
  variant with `factorize()`.

## Complexity

`O(10^6)` once, then `O(n log A)` per test.

## Pitfalls

- Trial division per element (`O(sqrt A)` = 1000 ops each) is `10^4 * 1000 = 10^7`
  per test and will TLE over many tests. The SPF table turns it into `~20` ops.
- Clearing a `10^6` array per testcase. Use a map, or clear only the touched keys.
- `a_i = 1` contributes nothing — the factorization loop must terminate cleanly on it.

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
