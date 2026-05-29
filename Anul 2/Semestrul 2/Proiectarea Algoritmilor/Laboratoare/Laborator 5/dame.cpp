#include <iostream>
#include <cmath>
using namespace std;

int n;

int VALID(int x[], int k) {
    for (int i = 1; i <= k - 1; i++)
        if (x[k] == x[i] || (k - i) == abs((x[k] - x[i])))
            return 0;
    return 1;
}

void AFISARE(int x[]) {
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void DAME(int n) {
    int k, x[100];
    k = 1;
    x[k] = 0;

    while (k > 0) {
        if (x[k] < n) {
            x[k] = x[k] + 1;
            if (VALID(x, k)) {
                if (k == n) {
                    AFISARE(x);

                } else {
                    k = k + 1;
                    x[k] = 0;
                }
            }
        } else {
            k = k - 1;
        }
    }
}

int main() {
    cin >> n;
    DAME(n);
    return 0;
}
