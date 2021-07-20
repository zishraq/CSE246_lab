#include <stdio.h>


void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void selection_sort(int arr[], int n) {
    int min_idx;

    for (int i = 0; i < n-1; i++) {
        min_idx = i;

        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        swap(&arr[min_idx], &arr[i]);
    }
}

void print_array(int arr[], int size) {
    for (int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selection_sort(arr, n);

    print_array(arr, n);

    return 0;
}
