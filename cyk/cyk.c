#include <stdio.h>
#include <string.h>

// Define the production rules of the grammar
struct Productions {
    char variable;
    char results[10][3]; // Assuming each variable can produce strings of length up to 2
};

struct Productions productions[] = {
    {'S', {"AB", "BC"}},
    {'A', {"BA", "a"}},
    {'B', {"CC", "b"}},
    {'C', {"AB", "a"}}
};

// Function to check if a variable produces a given result
int produces(char variable, const char* result) {
    for (int i = 0; i < sizeof(productions) / sizeof(productions[0]); ++i) {
        if (productions[i].variable == variable) {
            for (int j = 0; j < sizeof(productions[i].results) / sizeof(productions[i].results[0]); ++j) {
                if (strcmp(productions[i].results[j], result) == 0) {
                    return 1;
                }
            }
            return 0;
        }
    }
    return 0;
}

// CYK algorithm implementation
int cykAlgorithm(const char* input) {
    int n = strlen(input);

    // Initialize the table
    char table[n][n][10];

    // Fill in the table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sizeof(productions) / sizeof(productions[0]); ++j) {
            char symbol = input[i];
            if (produces(productions[j].variable, &symbol)) {
                strcpy(table[i][i], productions[j].results[0]);
            }
        }
    }

    // Fill in the rest of the table
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                for (int m = 0; m < sizeof(productions) / sizeof(productions[0]); ++m) {
                    for (int p = 0; p < sizeof(productions[m].results) / sizeof(productions[m].results[0]); ++p) {
                        char combination[3];
                        combination[0] = table[i][k][m];
                        combination[1] = table[k + 1][j][m];
                        combination[2] = '\0';

                        if (produces(productions[m].variable, combination)) {
                            strcat(table[i][j], productions[m].results[p]);
                        }
                    }
                }
            }
        }
    }

    // Check if the start symbol is in the top-right cell
    for (int i = 0; i < sizeof(productions) / sizeof(productions[0]); ++i) {
        if (productions[i].variable == 'S') {
            for (int j = 0; j < sizeof(productions[i].results) / sizeof(productions[i].results[0]); ++j) {
                if (strstr(table[0][n - 1], productions[i].results[j]) != NULL) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main() {
    // Test string
    const char* input = "ababa";

    // Check if the string is accepted by the grammar
    if (cykAlgorithm(input)) {
        printf("String '%s' is accepted by the grammar.\n", input);
    } else {
        printf("String '%s' is not accepted by the grammar.\n", input);
    }

    return 0;
}
