#include <stdio.h>


int main()
{
    int n, x;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &x);

    int largest_segment = 0;
    int sum = 0;

    int count = 0;
    while (count < n) {
        sum = 0;
        int inner_count = 0;

        for (int index = count; index < n; index++) {
            if (arr[index] > x) {
                break;
            }

            sum += arr[index];
            inner_count += 1;

            if (sum <= x) {
                if (inner_count > largest_segment) {
                    largest_segment = inner_count;
                }
            }

        }
        count++;
    }

    printf("%d\n", largest_segment);

    return 0;
}
