# Math cheatsheet

## When you see X, reach for Y

| In the statement | Reach for | Template |
|---|---|---|
| "exactly `k` divisors", perfect squares | divisor pairing `(d, n/d)` — odd count ⇒ perfect square | `notebook/math/sieve.cpp` |
| `n <= 10^12`, need primality of many numbers | sieve up to `sqrt(n) = 10^6` | `notebook/math/sieve.cpp` |
| "factor many numbers `<= 10^6`" | smallest-prime-factor table, `O(log x)` each | `notebook/math/sieve.cpp` |
| "find divisors of `n <= 10^9`" | `O(sqrt n)` loop, handle `d` and `n/d` | `notebook/math/divisors.cpp` |
| "move factors between elements" | product is invariant ⇒ work in exponent space | `notebook/math/sieve.cpp` |
| "count pairs with `(a_i ± a_j) % m == 0`" | map keyed on residues | — |
| "mod `10^9+7`", "count arrangements" | factorial + inverse-factorial tables | `notebook/math/combinatorics.cpp` |
| "split into groups, min/max pairs" | `C(k,2)` is convex ⇒ extremes vs balanced | `notebook/math/combinatorics.cpp` |
| `x ≡ r1 (mod m1)`, `x ≡ r2 (mod m2)` | CRT | `notebook/math/gcd_crt.cpp` |
| `ax + by = c` in integers | extended Euclid / linear Diophantine | `notebook/math/gcd_crt.cpp` |

## Formulas worth not re-deriving

- `C(n,2) = n(n-1)/2` · `C(n,3) = n(n-1)(n-2)/6`
- Sum `1..n` = `n(n+1)/2` · Sum of squares = `n(n+1)(2n+1)/6`
- Number of multiples of `d` in `[1, n]` = `floor(n/d)`
- Number of integers in `[1, n]` **not** divisible by `d` = `n - floor(n/d)`
- `k`-th positive integer not divisible by `n` = `k + (k-1)/(n-1)`
- `lcm(a,b) = a / gcd(a,b) * b` — divide **first**, or you overflow
- Divisor count of `n = p1^e1 * ... * pk^ek` is `(e1+1)*...*(ek+1)`
- Divisor sum is `prod (p^(e+1) - 1) / (p - 1)`
- Stars and bars: `n` into `k` ordered non-negative parts = `C(n+k-1, k-1)`
- Rearrangement inequality: to maximise `sum a_i * b_i`, sort both the same way;
  to minimise, sort them opposite ways
- Number of primes below `N` ≈ `N / ln N` (≈ 78498 below `10^6`)

## Overflow reference (signed 64-bit maxes at ~9.2 * 10^18)

| Expression | Safe while |
|---|---|
| `a * b` | `a, b <= 3 * 10^9` |
| `C(k,2)` | `k <= 4.3 * 10^9` |
| `C(k,3)` | `k <= 2.5 * 10^6` |
| `k^2` | `k <= 3 * 10^9` |
| `k^3` | `k <= 2 * 10^6` |

When in doubt: `__int128` for the accumulator, print by converting down at the end.

## Traps

- `(ll)sqrt(x)` is wrong near `10^12`. Use `sqrtl` and then correct `y` up/down.
- `%` on a negative number in C++ gives a **negative** result. Normalise with
  `((a % m) + m) % m`.
- Fermat's inverse `a^(m-2)` needs `m` **prime**. Otherwise use extended Euclid.
- Building a sieve inside the testcase loop is the classic TLE.
