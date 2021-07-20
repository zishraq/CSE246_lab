#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll maximum_range(ll arr[], ll n, ll target) {
    ll sum = 0;
    ll count = 0, max_count = 0;

    for (ll i = 0; i < n; i++) {

        if ((sum + arr[i]) <= target) {
            sum += arr[i];
            count++;
        }

        else if (sum != 0) {
            sum = sum - arr[i - count] + arr[i];
        }

        if (count > max_count) {
            max_count = count;
        }
    }

    return max_count;
}

int main() {
    ll n, target;

    cin >> n;

    ll arr[n];

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    cout << maximum_range(arr, n, target);
    return 0;
}
