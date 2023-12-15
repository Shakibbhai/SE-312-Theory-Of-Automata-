
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("nfa_dfa_input_file.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    cout << "NFA Transition state: " << endl;
    int num_of_states, num_of_symbol;
    int i, j, k;

    inputFile >> num_of_states >> num_of_symbol;

    char start_state, final_state;
    char states[num_of_states];

    cout << "Enter the states: " << endl;
    for (i = 0; i < num_of_states; i++) {
        inputFile >> states[i];
    }

    inputFile >> start_state >> final_state;

    char nfa_transition[num_of_states][num_of_symbol][num_of_states];
    cout << "...............transition table for nfa.................: " << endl;
    for (i = 0; i < num_of_states; i++) {
        //cout << " " << states[i] << endl;
        for (j = 0; j < num_of_symbol; j++) {
            //cout << " " << j << ": ";
            for (k = 0; k < num_of_states; k++) {
                inputFile >> nfa_transition[i][j][k];
            }
            cout << endl;
        }
    }

    queue<string> dfa_states;
    string another_check[1000], mk_start_state;
    int index = 0;
    mk_start_state += start_state;
    dfa_states.push(mk_start_state);
    another_check[index] = mk_start_state;
    index++;
    string check_done[1000];
    int f = 0, row = 0;
    string dfa_transition[1000][num_of_symbol];
    while (1) {
        if (dfa_states.size() == 0) {
            break;
        }
        string front1 = dfa_states.front();
        dfa_states.pop();
        check_done[f] = front1;
        f++;
        for (j = 0; j < num_of_symbol; j++) {
            set<char> add;
            add.clear();
            for (i = 0; i < front1.size(); i++) {
                for (k = 0; k < num_of_states; k++) {
                    if (nfa_transition[front1[i] - 'a'][j][k] != 'x') {
                        add.insert(nfa_transition[front1[i] - 'a'][j][k]);
                    }
                }
            }
            string final_dfa;
            for (auto t : add) {
                final_dfa.push_back(t);
            }
            dfa_transition[row][j] = final_dfa;
            int flag = 0;
            for (i = 0; i < f; i++) {
                if (check_done[i] == final_dfa) {
                    flag = 1;
                    break;
                }
            }
            for (i = 0; i < index; i++) {
                if (final_dfa == another_check[i]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                dfa_states.push(final_dfa);
                another_check[index] = final_dfa;
                index++;
            }
        }
        row++;
    }

    cout << "dfa states are: " << endl;
    for (i = 0; i < row; i++) {
        cout << check_done[i] << endl;
    }
    cout << "....................DFA transition table:.................... " << endl;
    for (i = 0; i < row; i++) {
        cout << " state " << check_done[i] << ":" << endl;
        for (j = 0; j < num_of_symbol; j++) {
            cout << "  " << j << ":" << dfa_transition[i][j] << endl;
        }
    }

    inputFile.close();
    return 0;
}
