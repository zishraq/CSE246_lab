#include <bits/stdc++.h>

using namespace std;


vector <vector <int>> numberAndSumOfDivisorsGenerator(int n) {
    vector <int> number_of_divisors(n + 1, 0);
    vector <int> sum_of_divisors(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            number_of_divisors[j]++;
            sum_of_divisors[j] += i;
        }
    }

    return {number_of_divisors, sum_of_divisors};
}


int main() {
    int n;

    cin >> n;

    vector <vector <int>> result = numberAndSumOfDivisorsGenerator(n);

    for (int i = 1; i <= n; i++) {
        cout << result[0][i] << " " << result[1][i] << endl;
    }

    return 0;
}
