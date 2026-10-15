#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_CAP 1024
#define NAME_CAP 800

static void trim_newline(char *text) {
    size_t length = strlen(text);
    while (length > 0 && (text[length - 1] == '\n' || text[length - 1] == '\r')) {
        text[--length] = '\0';
    }
}

static char *trim_spaces(char *text) {
    while (isspace((unsigned char)*text)) {
        text++;
    }
    size_t length = strlen(text);
    while (length > 0 && isspace((unsigned char)text[length - 1])) {
        text[--length] = '\0';
    }
    return text;
}

static int parse_score(const char *text, double *score) {
    char *end = NULL;
    errno = 0;
    double value = strtod(text, &end);
    if (text == end || errno == ERANGE) {
        return 0;
    }
    while (*end != '\0' && isspace((unsigned char)*end)) {
        end++;
    }
    if (*end != '\0' || value < 0.0 || value > 100.0) {
        return 0;
    }
    *score = value;
    return 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s FILE.csv\n", argv[0]);
        return 2;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("Could not open input file");
        return 1;
    }

    char line[LINE_CAP];
    size_t line_number = 0;
    size_t valid_rows = 0;
    size_t invalid_rows = 0;
    double total = 0.0;
    double minimum = 0.0;
    double maximum = 0.0;

    while (fgets(line, sizeof line, input) != NULL) {
        line_number++;
        if (strchr(line, '\n') == NULL && !feof(input)) {
            int ch;
            while ((ch = fgetc(input)) != '\n' && ch != EOF) {
                /* Discard the rest of an overlong row. */
            }
            fprintf(stderr, "Line %zu is too long; skipped.\n", line_number);
            invalid_rows++;
            continue;
        }

        trim_newline(line);
        char *comma = strchr(line, ',');
        if (comma == NULL) {
            if (*trim_spaces(line) != '\0') {
                fprintf(stderr, "Line %zu has no comma; skipped.\n", line_number);
                invalid_rows++;
            }
            continue;
        }

        *comma = '\0';
        char *name = trim_spaces(line);
        char *score_text = trim_spaces(comma + 1);
        double score = 0.0;
        if (*name == '\0' || strlen(name) >= NAME_CAP || !parse_score(score_text, &score)) {
            fprintf(stderr, "Line %zu is invalid; expected name,score in the range 0..100.\n",
                    line_number);
            invalid_rows++;
            continue;
        }

        if (valid_rows == 0 || score < minimum) {
            minimum = score;
        }
        if (valid_rows == 0 || score > maximum) {
            maximum = score;
        }
        total += score;
        valid_rows++;
    }

    if (ferror(input)) {
        perror("Error while reading input");
        fclose(input);
        return 1;
    }
    fclose(input);

    printf("Valid records: %zu\n", valid_rows);
    printf("Skipped records: %zu\n", invalid_rows);
    if (valid_rows == 0) {
        printf("No valid scores found.\n");
        return 0;
    }

    printf("Average: %.2f\n", total / (double)valid_rows);
    printf("Minimum: %.2f\n", minimum);
    printf("Maximum: %.2f\n", maximum);
    return 0;
}
