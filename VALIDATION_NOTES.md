# Input Validation Notes

This note documents a simple validation pattern for command-line programs.

## Recommended flow

1. Read the complete input.
2. Validate required fields before processing.
3. Report the failure clearly.
4. Return a non-zero status for invalid input.

Keeping validation separate from processing makes small utilities easier to test and reuse.
