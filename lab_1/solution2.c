#include <stdio.h>


int main()
{
    int a, b, result;

    scanf("%d %d", &a, &b);

    result = a - b;

    if (result < 0) {
        result -= (result + result);
    }

    printf("%d\n", result);

    return 0;
}
