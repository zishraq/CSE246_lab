#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int isSubsequence(string main_string, string subsequence) {
    long unsigned int i = 0;
    long unsigned int j = 0;

    while (i < main_string.size() && j < subsequence.size()) {
        if (main_string[i] == subsequence[j]) {
            j++;
        }

        i++;
    }

    return j == subsequence.size();
}

int main() {

    string main_string, subsequence;

    cin >> main_string;
    cin >> subsequence;

    cout << isSubsequence(main_string, subsequence) << endl;

    return 0;
}
