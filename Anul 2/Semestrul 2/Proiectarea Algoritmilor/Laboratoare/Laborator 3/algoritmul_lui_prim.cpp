#include <iostream>

using namespace std;

int S[100], t[100], c[10][10], TATA[100], i, l, n, y, x;

void PRIM() {
    S[1] = 1;
    int cost = 0;
    int minim;

    for (i = 2; i <= n; i++) {
        S[i] = 0;
        t[i] = c[i][1];
        TATA[i] = 1;
    }

    for (l = 1; l <= n - 1; l++) {
        minim = 9999;

        for (i = 2; i <= n; i++) {
            if (S[i] == 0 && t[i] < minim) {
                minim = t[i];
                y = i;
            }
        }

        S[y] = 1;
        x = TATA[y];
        cost = cost + c[x][y];

        for (i = 2; i <= n; i++) {
            if (S[i] == 0 && t[i] > c[i][y]) {
                t[i] = c[i][y];
                TATA[i] = y;
            }
        }
    }

    cout << "Costul minim al arborelui de acoperire: " << cost << endl;
}

int main() {
    int m;
    cout << "Introduceti numarul de noduri: ";
    cin >> n;
    cout << "Introduceti numarul de muchii: ";
    cin >> m;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = 9999;
        }
    }

    cout << "Introduceti muchiile si costul acestora: " << endl;
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        c[u][v] = c[v][u] = cost;
    }

    PRIM();

    return 0;
}
