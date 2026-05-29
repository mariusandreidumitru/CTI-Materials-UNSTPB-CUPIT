#include <iostream>
using namespace std;

int x[100], m, n, k;

void AFISARE(int x[]) {
    for (int i = 1; i <= m; i++)
        cout << x[i] << " ";
    cout << endl;
}

void GENERARE_FUNCTII_CRESC(int m, int n) {
    k = 1;
    x[k] = 0;

    while (k > 0) {
        if (x[k] < n) {
            x[k]++;
            if (x[k] > x[k - 1]) {
                if (k == m)
                    AFISARE(x);
                else {
                    k++;
                    x[k] = x[k - 1];
                }
            }
        } else {
            k--;
        }
    }
}

int main() {
    cin >> m >> n;
    if (m > n) {
        cout << "Nu exista functii strict crescatoare: m trebuie sa fie <= n.\n";
        return 0;
    }
    x[0] = 0;
    GENERARE_FUNCTII_CRESC(m, n);
    return 0;
}
