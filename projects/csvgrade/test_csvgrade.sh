#!/usr/bin/env sh
# Small integration test for csvgrade. Run from this directory with sh test_csvgrade.sh.
set -eu

CC="${CC:-cc}"
TMP_DIR="$(mktemp -d)"
trap 'rm -rf "$TMP_DIR"' EXIT HUP INT TERM

if ! command -v "$CC" >/dev/null 2>&1; then
    echo "Compiler not found: $CC" >&2
    exit 1
fi

"$CC" -std=c11 -Wall -Wextra -Wpedantic -O2 csvgrade.c -o "$TMP_DIR/csvgrade"

cat > "$TMP_DIR/scores.csv" <<'EOF'
Ada,90
Grace,80
Invalid,101
,75
Linus,0
EOF

"$TMP_DIR/csvgrade" "$TMP_DIR/scores.csv" > "$TMP_DIR/output.txt" 2> "$TMP_DIR/errors.txt"

grep -Fqx 'Valid records: 3' "$TMP_DIR/output.txt"
grep -Fqx 'Skipped records: 2' "$TMP_DIR/output.txt"
grep -Fqx 'Average: 56.67' "$TMP_DIR/output.txt"
grep -Fqx 'Minimum: 0.00' "$TMP_DIR/output.txt"
grep -Fqx 'Maximum: 90.00' "$TMP_DIR/output.txt"

if "$TMP_DIR/csvgrade" > /dev/null 2>&1; then
    echo "Expected usage error when no input file is supplied." >&2
    exit 1
fi

echo "CSVGrade smoke tests passed."
