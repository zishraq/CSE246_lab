#include <bits/stdc++.h>

using namespace std;

void sieve(int n) {
    vector <bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (long long int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << endl;

            for (long long int j = i * i; j <= n; j += i) {

                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    long long int n;

    cin >> n;

    sieve(n);

    return 0;
}
