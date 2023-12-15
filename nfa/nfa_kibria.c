#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_ALPHABET 2  // '0' and '1'

char transitions[MAX_STATES][MAX_ALPHABET][MAX_STATES];
bool final_states[MAX_STATES];
int nfa_size;

bool epsilon_closure(char current_states[], char epsilon_closure_states[]) {
    // Implement epsilon closure computation here
}

bool nfa_accepts(char input_string[], char start_state) {
    // Implement NFA simulation here
}

void read_transitions() {
    char targets[100];
    for (int i = 0; i < nfa_size; i++) {
        printf("Enter transitions for state q%d:\n", i);
        for (int j = 0; j < MAX_ALPHABET; j++) {
            printf("Transition for symbol '%c' ( press Enter if none): ", j + '0');
            scanf("%s", targets);
            if (strcmp(targets, "") == 0) {
                transitions[i][j][0] = '\0';  // No transition
            } else {
                strcpy(transitions[i][j], targets);
            }
        }
    }
}

int main() {
    char start_state;
    char input_string[100];

    printf("Enter the number of states in the NFA: ");
    scanf("%d", &nfa_size);

    read_transitions();

    // Read final states
    for (int i = 0; i < nfa_size; i++) {
        printf("Is state q%d final? (1 for yes, 0 for no): ", i);
        int is_final;
        scanf("%d", &is_final);
        final_states[i] = (is_final == 1);
    }

    printf("Enter the start state: ");
    scanf(" %c", &start_state);
    printf("Enter an input string: ");
    scanf("%s", input_string);

    if (nfa_accepts(input_string, start_state)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
