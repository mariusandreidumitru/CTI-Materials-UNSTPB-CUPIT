#include <iostream>
using namespace std;

int cautareBinara(int A[], int p, int u, int x) {
    if (p > u)
        return -1;

    int m = (p + u) / 2;

    if (A[m] == x)
        return m;

    if (x < A[m])
        return cautareBinara(A, p, m - 1, x);
    else
        return cautareBinara(A, m + 1, u, x);
}

int main() {
    int A[101], n, x;

    cout << "n=";
    cin >> n;

    cout << "Elemente sortate crescator:\n";
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    cout << "x=";
    cin >> x;

    int poz = cautareBinara(A, 1, n, x);

    if (poz == -1)
        cout << "Elementul nu a fost gasit.\n";
    else
        cout << "Elementul se afla pe pozitia " << poz << ".\n";

    return 0;
}
