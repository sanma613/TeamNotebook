# Team Notebook — Competitive Programming (Math & Data Structures)

Two things live here:

- **`notebook/`** — the reusable templates you copy-paste in contest. Buildable into a
  printable PDF (`tools/build_notebook.sh`).
- **`problems/`** — a curated Codeforces ladder. Every problem folder has a
  `README.md` with a full step-by-step derivation and a working `solution.cpp`.

Language: C++20. Everything compiles with `g++ -std=c++20 -O2 -Wall -Wextra`.

---

## The ladder

Work top to bottom inside each block. Read the guide **after** you have tried the
problem for 20 minutes, not before.

### Math / number theory

| # | Problem | Rating | Concept |
|---|---|---|---|
| 1 | [1352C — K-th Not Divisible by n](problems/cf-1352C-kth-not-divisible/) | 1200 | closed-form counting |
| 2 | [1541B — Pleasant Pairs](problems/cf-1541B-pleasant-pairs/) | 1200 | harmonic-sum enumeration |
| 3 | [230B — T-primes](problems/cf-0230B-t-primes/) | 1300 | sieve, divisor pairing |
| 4 | [1294C — Product of Three Numbers](problems/cf-1294C-product-of-three/) | 1300 | `O(sqrt n)` divisors, greedy |
| 5 | [1360D — Buying Shovels](problems/cf-1360D-buying-shovels/) | 1300 | divisors, minimise `n/d` |
| 6 | [1931D — Divisible Pairs](problems/cf-1931D-divisible-pairs/) | 1300 | pair counting on residues |
| 7 | [1881D — Divide and Equalize](problems/cf-1881D-divide-and-equalize/) | 1300 | factorization, exponent invariant |

### Combinatorics

| # | Problem | Rating | Concept |
|---|---|---|---|
| 8 | [1922B — Forming Triangles](problems/cf-1922B-forming-triangles/) | 1200 | counting triples by group |
| 9 | [459B — Pashmak and Flowers](problems/cf-0459B-pashmak-and-flowers/) | 1300 | frequency counting, all-equal edge case |
| 10 | [478B — Random Teams](problems/cf-0478B-random-teams/) | 1300 | convexity of `C(k,2)` |

### Data structures

| # | Problem | Rating | Concept |
|---|---|---|---|
| 11 | [1520D — Same Differences](problems/cf-1520D-same-differences/) | 1200 | rewrite into an invariant, then map |
| 12 | [4C — Registration System](problems/cf-0004C-registration-system/) | 1300 | `map` as the whole algorithm |
| 13 | [600B — Queries about less or equal](problems/cf-0600B-queries-less-or-equal/) | 1300 | sort + `upper_bound` |
| 14 | [1324D — Pair of Topics](problems/cf-1324D-pair-of-topics/) | 1400 | collapse two arrays, two pointers |
| 15 | [276C — Little Girl and Maximum Sum](problems/cf-0276C-little-girl-max-sum/) | 1500 | difference array + rearrangement |
| 16 | [466C — Number of Ways](problems/cf-0466C-number-of-ways/) | 1700 | prefix sums, count in one pass |

Already solved, kept for reference: [`problems/cses-graphs/`](problems/cses-graphs/),
[`problems/cses-geometry/`](problems/cses-geometry/),
[`problems/cf-2061B-kevin-and-geometry/`](problems/cf-2061B-kevin-and-geometry/).

---

## The notebook

| Area | Files |
|---|---|
| `notebook/math/` | `sieve.cpp` (sieve + smallest-prime-factor + `isqrt`), `divisors.cpp`, `modular.cpp`, `combinatorics.cpp`, `gcd_crt.cpp` |
| `notebook/structures/` | `prefix_sums.cpp` (1D/2D/difference array), `fenwick.cpp`, `segtree.cpp`, `sparse_table.cpp`, `ordered_set.cpp` |
| `notebook/graphs/` | `BFS.cpp`, `DFS.cpp`, `DIJKSTRA.cpp`, `DSU.cpp` |
| `notebook/geometry/` | `Point2D.cpp` |
| | `notebook/template.cpp` — the contest starting file |

Quick lookup while solving: [`docs/math-cheatsheet.md`](docs/math-cheatsheet.md) and
[`docs/ds-cheatsheet.md`](docs/ds-cheatsheet.md). Both have a
"when you see X, reach for Y" table.

---

## Commands

```bash
bash tools/check.sh           # compile every solution + syntax-check every template
bash tools/build_notebook.sh  # produce notebook.pdf for printing
g++ -std=c++20 -O2 -Wall -Wextra -o sol problems/<dir>/solution.cpp && ./sol
```

---

## Conventions

- Problem folders are `cf-<contest><index>-<slug>` (contest zero-padded to 4 digits so
  they sort correctly) or `cses-<topic>`.
- Every solution is a **single self-contained file** — that is what you submit.
  Templates are copied in, not `#include`d.
- Guides never reproduce the official statement (they are not fetchable and it is a
  copyright question); they summarise it in 2–3 lines and link out.
- Every guide ends with "submit on Codeforces to confirm the verdict". The solutions
  here are compiled and checked against the worked examples in their guide, and the
  trickier ones are stress-tested against brute force — but **nothing here has been
  submitted**. Treat a verdict as unconfirmed until you submit it.

## Adding a problem

1. `mkdir problems/cf-XXXXY-slug`
2. Copy `notebook/template.cpp` to `solution.cpp`, solve it.
3. Write `README.md` following the shape every other guide uses:
   link/rating/tags → problem in three lines → observations → key insight →
   step by step → implementation notes → complexity → pitfalls → worked examples.
4. `bash tools/check.sh`
5. Add a row to the ladder table above.
