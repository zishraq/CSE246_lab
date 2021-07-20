#include <stdio.h>


int binary_search(int arr[], int first_index, int last_index, int x) {
    while (first_index <= last_index) {
        int midpoint = (first_index + last_index) / 2;

        if (arr[midpoint] == x) {
            return midpoint;
        }

        if (arr[midpoint] < x) {
            first_index = midpoint + 1;
        }

        else {
            last_index = midpoint - 1;
        }
    }

    return -1;
}

int main()
{
    int n, q;

    scanf("%d %d", &n, &q);

    int arr[n], queries[q];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < q; i++) {
        scanf("%d", &queries[i]);
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", binary_search(arr, 0, n - 1, queries[i]));
    }

    return 0;
}
