#include <iostream>
#include <climits>
#define NUM 100
using namespace std;

void mergesort(int x[], int n) {

    int aux[NUM];
    int i,j,k,l1,l2,size,u1,u2;

    size = 1;

    while(size < n) {
        l1 = 0;
        k = 0;

        while((l1 + size) < n) {
            l2 = l1 + size;
            u1 = l2 - 1;
            u2 = (l2 + size - 1 < n) ? l2 + size - 1 : n - 1;

            for(i = l1, j = l2; i <= u1 && j <= u2; k++)
                if(x[i] <= x[j])
                    aux[k] = x[i++];
                else
                    aux[k] = x[j++];

            for(; i <= u1; k++)
                aux[k] = x[i++];

            for(; j <= u2; k++)
                aux[k] = x[j++];

            l1 = u2 + 1;
        }

        for(i = l1; k < n; i++)
            aux[k++] = x[i];

        for(i = 0; i < n; i++)
            x[i] = aux[i];

        size *= 2;
    }
}

int main() {

    int a[100];
    int n;
    int m;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    mergesort(a, n);

    for(int i = 1; i <= n; i++) {
        cout << a[i] <<" ";
    }

    return 0;
}
