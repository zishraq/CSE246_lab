#include <bits/stdc++.h>

using namespace std;


map <string, vector <int>> numberAndSumOfDivisorsGenerator(int n) {
    vector <int> number_of_divisors(n + 1, 0);
    vector <int> sum_of_divisors(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            number_of_divisors[j]++;
            sum_of_divisors[j] += i;
        }
    }

    map <string, vector <int>> result;
    result["number_of_divisors"] = number_of_divisors;
    result["sum_of_divisors"] = sum_of_divisors;
    return result;
}

int main() {
    int n;

    cin >> n;

    map <string, vector <int>> result = numberAndSumOfDivisorsGenerator(n);

    for (int i = 1; i <= n; i++) {
        cout << result["number_of_divisors"][i] << " " << result["sum_of_divisors"][i] << endl;
    }

    return 0;
}
