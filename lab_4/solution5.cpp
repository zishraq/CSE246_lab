#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int isSubsequence(string main_string, string sequence) {
    long unsigned int i = 0;
    long unsigned int j = 0;

    while (i < main_string.size() && j < sequence.size()) {
        if (main_string[i] == sequence[j]) {
            j++;
        }

        i++;
    }

    return j == sequence.size();
}

int main() {

    string main_string, sequence;

    cin >> main_string;
    cin >> sequence;

    cout << isSubsequence(main_string, sequence) << endl;

    return 0;
}
