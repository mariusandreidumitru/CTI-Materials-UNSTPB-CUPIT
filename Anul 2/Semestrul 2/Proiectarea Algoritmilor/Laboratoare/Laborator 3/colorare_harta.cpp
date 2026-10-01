#include <iostream>
using namespace std;


int esteSigur(int nod, int culoare, int adiacenta[][5], int culori[], int n) {

    for (int i = 0; i < n; i++) {
        if (adiacenta[nod][i] == 1 && culori[i] == culoare) {
            return 0;
        }
    }
    return 1;
}

int colorareUtil(int adiacenta[][5], int m, int culori[], int nod, int n) {
    if (nod == n) {
        return 1;
    }


    for (int culoare = 1; culoare <= m; culoare++) {
        if (esteSigur(nod, culoare, adiacenta, culori, n)) {
            culori[nod] = culoare;


            if (colorareUtil(adiacenta, m, culori, nod + 1, n)) {
                return true;
            }


            culori[nod] = 0;
        }
    }

    return 0;
}


int colorare(int adiacenta[][5], int m, int n) {
    int culori[5] = {0};

    return colorareUtil(adiacenta, m, culori, 0, n);
}

int main() {
    int n, m = 4;
    cout << "Introduceti numarul de tari: ";
    cin >> n;

    int adiacenta[5][5] = {0};


    cout << "Introduceti frontierle (relatiile de adiacenta):\n";
    for (int i = 0; i < n; i++) {
        int numarVecini;
        cout << "Numarul de tari vecine ale tarii " << i + 1 << ": ";
        cin >> numarVecini;
        cout << "Tari vecine: ";
        for (int j = 0; j < numarVecini; j++) {
            int vecin;
            cin >> vecin;
            adiacenta[i][vecin - 1] = 1;
            adiacenta[vecin - 1][i] = 1;
        }
    }

    if (colorare(adiacenta, m, n)) {
        cout << "Este posibila colorarea cu maxim 4 culori.\n";
    } else {
        cout << "Nu este posibila colorarea cu maxim 4 culori.\n";
    }

    return 0;
}
