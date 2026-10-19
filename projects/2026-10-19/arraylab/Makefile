CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -Werror -O2
PROGRAMS = array_stats linear_search binary_search insertion_sort merge_sorted_arrays remove_duplicates two_sum matrix_multiply

.PHONY: all test clean
all: $(PROGRAMS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

test:
	sh test_arraylab.sh

clean:
	rm -f $(PROGRAMS)
