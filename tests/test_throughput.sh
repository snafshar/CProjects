#!/bin/sh
set -eu
cc -std=c11 -Wall -Wextra -Werror src/throughput.c -o /tmp/c-throughput-test
output=$(/tmp/c-throughput-test)
printf '%s\n' "$output" | grep -q 'throughput: 5.000 Mbps'
printf '%s\n' 'throughput example passed'
