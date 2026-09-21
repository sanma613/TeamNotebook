#!/usr/bin/env bash
# Build a printable PDF of notebook/ (the thing you take into the contest room).
# Needs: pandoc + pdflatex.
set -euo pipefail
cd "$(dirname "$0")/.."

OUT=notebook.md
{
    echo "% Team Notebook"
    echo "% "
    echo "% $(date +%Y-%m-%d)"
    echo
    for dir in math structures graphs geometry; do
        [ -d "notebook/$dir" ] || continue
        echo "# ${dir^}"
        echo
        for f in notebook/"$dir"/*.cpp; do
            [ -e "$f" ] || continue
            echo "## $(basename "$f" .cpp)"
            echo
            echo '```cpp'
            cat "$f"
            echo '```'
            echo
        done
    done
    echo "# Template"
    echo
    echo '```cpp'
    cat notebook/template.cpp
    echo '```'
} > "$OUT"

pandoc "$OUT" -o notebook.pdf \
    --pdf-engine=pdflatex \
    --highlight-style=tango \
    -V geometry:margin=1.5cm \
    -V colorlinks=true \
    --toc

echo "wrote notebook.pdf"
