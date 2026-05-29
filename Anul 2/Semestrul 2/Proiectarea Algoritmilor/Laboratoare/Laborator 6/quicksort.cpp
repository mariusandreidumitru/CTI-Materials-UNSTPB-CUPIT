#include <iostream>
using namespace std;

int A[101], n;

int PIVOT(int A[], int p, int u) {
    int d = 0, aux;

    while (p < u) {
        if (A[p] > A[u]) {
            aux = A[p];
            A[p] = A[u];
            A[u] = aux;
            d = 1 - d;
        }
        p = p + d;
        u = u - 1 + d;
    }
    return p;
}

void QUICKSORT(int A[], int p, int u) {
    if (p < u) {
        int k = PIVOT(A, p, u);
        QUICKSORT(A, p, k - 1);
        QUICKSORT(A, k + 1, u);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    QUICKSORT(A, 1, n);

    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    return 0;
}
