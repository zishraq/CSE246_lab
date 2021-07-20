#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int count_notes(int amount) {
    int count = 0;

    while (amount > 0) {
        if (amount >= 500) {
            amount -= 500;
            count++;
        } else if (amount >= 100) {
            amount -= 100;
            count++;
        } else if (amount >= 50) {
            amount -= 50;
            count++;

        } else if (amount >= 20) {
            amount -= 20;
            count++;
        } else if (amount >= 10) {
            amount -= 10;
            count++;
        } else if (amount >= 5) {
            amount -= 5;
            count++;
        } else if (amount >= 2) {
            amount -= 2;
            count++;
        } else if (amount >= 1) {
            amount -= 1;
            count++;
        }
    }

    return count;
}

int main() {
    int n;

    cin >> n;

    cout << count_notes(n) << endl;

    return 0;
}
