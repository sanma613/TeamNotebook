# 466C — Number of Ways

- Link: https://codeforces.com/problemset/problem/466/C
- Rating: 1700 · Tags: `data structures`, `dp`, `binary search`, `two pointers`, `brute force`
- Topic: **prefix sums + counting in one pass**

## Problem in three lines

Split the array into **three contiguous non-empty** parts whose sums are all equal.
Count the number of ways. `n` up to `5*10^5`, values can be negative.

## Observations

- The split is determined by two cut points `i < j`. Trying all pairs is `O(n^2)`.
- If the total is `S`, each part must sum to `S / 3`. So `S % 3 != 0` → answer `0`
  immediately.
- Prefix sums turn "part 1 sums to `S/3`" into "`pref[i] == S/3`" and
  "parts 1+2 sum to `2S/3`" into "`pref[j] == 2S/3`".

## Key insight

Scan left to right maintaining a running prefix `pref`.

- Whenever `pref == 2*S/3` at index `i`, every earlier index `k < i` with
  `pref[k] == S/3` gives a valid split.
- So keep a counter `cnt` of how many prefixes equal `S/3` have been seen **strictly
  before** the current index, and add it to the answer whenever the current prefix hits
  `2*S/3`.

The ordering inside the loop is the whole correctness argument: **add to the answer
first, then update `cnt`**. Otherwise a single index counts as both cut points.

## Step by step

1. Compute `S = sum(a)`. If `S % 3 != 0`, print `0`.
2. `t = S / 3`; `cnt = 0`, `ans = 0`, `pref = 0`.
3. For `i` from `0` to `n - 1`:
   - `pref += a[i]`;
   - if `i == n - 1`, **break** — the third part must be non-empty, so the second cut
     can never be the last index;
   - if `pref == 2*t`, `ans += cnt`;
   - if `pref == t`, `cnt++`.
4. Print `ans`.

Worked example, `a = [1, 2, 3, 0, 3]`, `S = 9`, `t = 3`:
`i=0` pref 1 — nothing. `i=1` pref 3 == t → `cnt = 1`. `i=2` pref 6 == 2t → `ans += 1`
(`ans = 1`); pref != t. `i=3` pref 6 == 2t → `ans += 1` (`ans = 2`). `i=4` is the last
index → break. Answer `2`.
Check: `[1,2] [3] [0,3]` and `[1,2] [3,0] [3]`. ✓

## Implementation notes (C++)

- `n` up to `5*10^5`, values up to `10^9` in absolute value → `S` up to `5*10^14`.
  **`long long` for the sums**, and the answer is up to `~n^2/2` so `long long` there
  too.
- `S % 3` with a **negative** `S` is implementation-defined in sign but `% 3 != 0`
  still correctly detects non-divisibility in C++. And `S / 3` truncates toward zero,
  which for an exactly-divisible `S` is exact. So negatives are safe here — but only
  because we checked divisibility first.
- Template: [`notebook/structures/prefix_sums.cpp`](../../notebook/structures/prefix_sums.cpp)

## Complexity

`O(n)` time, `O(1)` extra space.

## Pitfalls

- `S == 0`: then `t == 0` and `2t == 0`, so the same index satisfies both tests. The
  "add to `ans` before incrementing `cnt`" ordering is what keeps this correct —
  test `a = [0, 0, 0, 0]`, the answer is `3`.
- Letting the second cut fall on the last index (empty third part). Hence the `break`.
- `int` overflow in the prefix sum.

Solution: [`solution.cpp`](solution.cpp) — submit on Codeforces to confirm the verdict.
