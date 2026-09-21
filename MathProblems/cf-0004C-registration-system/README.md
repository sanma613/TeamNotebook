# 4C — Registration System

- Link: https://codeforces.com/problemset/problem/4/C
- Rating: 1300 · Tags: `data structures`, `hashing`, `implementation`
- Topic: **`std::map` as the entire algorithm**

## Problem in three lines

`n` users request a name. If the name is free, register it and print `OK`. If it is
taken, print the name with the smallest positive integer appended that makes it new
(`name1`, `name2`, ...), and register that.

## Observations

- `n` up to `10^5`, names up to 32 lowercase letters. Nothing clever is needed; the
  whole problem is "which container".
- The naive reading — "search for the smallest free suffix" — suggests a loop per
  query. But you never need it.

## Key insight

Keep a `map<string, int>` from a **base name** to how many times it has been
requested. The `k`-th request for `name` (0-indexed `k`) is answered with:

- `k == 0` → `OK`
- `k >= 1` → `name` + `k`

because the suffixes are handed out in order `1, 2, 3, ...` and never skip.
So the counter *is* the smallest free suffix. No inner loop.

## Step by step

1. `map<string,int> cnt;`
2. For each requested `s`:
   - if `cnt[s] == 0`, print `OK`;
   - else print `s << cnt[s]`;
   - `cnt[s]++` in both cases.

Worked example: `abacaba, acaba, abacaba, acab` →
`OK`, `OK`, `abacaba1`, `OK`.

## Implementation notes (C++)

- `map` vs `unordered_map`: `map` is `O(len * log n)` and always safe.
  `unordered_map<string,int>` is faster on average but can be anti-hash-tested on
  Codeforces. For `10^5` strings either passes; prefer `map` unless it is tight.
- `cnt[s]` on a missing key **inserts** a `0` — that is exactly the behaviour we want
  here, but be aware it mutates the map. If you ever need a pure lookup, use `find`.
- Do not build the reply with string concatenation in a loop; just stream
  `cout << s << cnt[s]`.

## Complexity

`O(n * len * log n)`.

## Pitfalls

- Printing `name0` for the first request. The `k == 0` case is `OK`.
- There is a theoretical hole: if a user later explicitly requests `abacaba1` after it
  was auto-generated, this solution prints `OK` and issues it twice. This is the
  intended solution and the official tests do not contain that case — but know that
  you are relying on it.

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
