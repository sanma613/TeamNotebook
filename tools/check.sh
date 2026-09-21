#!/usr/bin/env bash
# Compile every .cpp in the repo. Solutions are linked, notebook snippets are
# syntax-checked only (they have no main).
set -u
cd "$(dirname "$0")/.."
FLAGS="-std=c++20 -O2 -Wall -Wextra"
fail=0

for f in problems/*/solution.cpp problems/*/*.cpp; do
    [ -e "$f" ] || continue
    if ! g++ $FLAGS -o /tmp/cp_check.out "$f" 2>/tmp/cp_check.err; then
        echo "FAIL (link) $f"; sed 's/^/    /' /tmp/cp_check.err; fail=1
    fi
done

for f in notebook/*.cpp notebook/*/*.cpp; do
    [ -e "$f" ] || continue
    if ! g++ $FLAGS -fsyntax-only "$f" 2>/tmp/cp_check.err; then
        echo "FAIL (syntax) $f"; sed 's/^/    /' /tmp/cp_check.err; fail=1
    fi
done

[ $fail -eq 0 ] && echo "all good"
exit $fail
