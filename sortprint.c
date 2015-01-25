#include <stdio.h>

void print(int a[], int i, int end)
{
    if(i > end)
        return;

    print(a, 2*i + 1, end);
    printf("%d ", a[i]);
    print(a, 2*i + 2, end);
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int a[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    print(a, 0, n - 1);
    return 0;
}
