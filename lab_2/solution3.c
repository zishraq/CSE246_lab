#include <stdio.h>


void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1], right[n2];

    for (i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++) {
        right[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }


    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}


void merge_sort(int *arr, int left, int right) {
    if (left < right) {
        int midpoint = (left + right) / 2;

        merge_sort(arr, left, midpoint);
        merge_sort(arr, midpoint + 1, right);

        merge(arr, left, midpoint, right);
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
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

    merge_sort(arr, 0, n - 1);

    print_array(arr, n);

    return 0;
}
