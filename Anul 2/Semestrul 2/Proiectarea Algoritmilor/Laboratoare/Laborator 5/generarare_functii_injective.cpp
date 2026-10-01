#include <iostream>
using namespace std;

int x[100], n, m, k;

int VALID(int x[], int k) {
    for (int i = 1; i < k; i++)
        if (x[i] == x[k])
            return false;
    return true;
}

void AFISARE(int x[]) {
    for (int i = 1; i <= m; i++)
        cout << x[i] << " ";
    cout << endl;
}

void GENERARE_FUNCTII_INJECTIVE(int m, int n) {
    k = 1;
    x[k] = 0;

    while (k > 0) {
        if (x[k] < n) {
            x[k]++;
            if (VALID(x, k)) {
                if (k == m)
                    AFISARE(x);
                else {
                    k=k+1;
                    x[k] = 0;
                }
            }
        } else {
            k=k-1;
        }
    }
}

int main() {
    cin >> m >> n;
    if (m > n) {
        cout << "Nu exista functii injective: m trebuie sa fie <= n.\n";
        return 0;
    }
    GENERARE_FUNCTII_INJECTIVE(m, n);
    return 0;
}
