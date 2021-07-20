#include <bits/stdc++.h>

using namespace std;


vector <int> NumberOfDivisorSieve(int n) {
    vector <int> number_of_divisors(n, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            number_of_divisors[j]++;
        }
    }

    return number_of_divisors;
}

vector <int> SumOfDivisorSieve(int n) {
    vector <int> sum_of_divisors(n, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            sum_of_divisors[j] += i;
        }
    }

    return sum_of_divisors;
}


int main() {
    int n;

    cin >> n;

    vector <int> number_of_divisors = NumberOfDivisorSieve(n);
    vector <int> sum_of_divisors = SumOfDivisorSieve(n);

    for (int i = 1; i <= n; i++) {
        cout << number_of_divisors[i] << " " << sum_of_divisors[i] << endl;
    }

    return 0;
}
