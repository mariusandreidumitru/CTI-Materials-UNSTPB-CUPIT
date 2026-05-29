#include <iostream>
using namespace std;

int G[100][100]; // matricea de adiacența
int x[100];      // culorile nodurilor
int n, m;        // n = numar noduri, m = numar culori

bool valid(int k) {
    for (int i = 1; i <= n; i++) {
        if (G[k][i] && x[k] == x[i]) // noduri adiacente colorate la fel
            return false;
    }
    return true;
}

void afisare() {
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void colorare_graf(int k) {
    for (int i = 1; i <= m; i++) {
        x[k] = i;
        if (valid(k)) {
            if (k == n)
                afisare();
            else
                colorare_graf(k + 1);
        }
    }
}

int main() {
    int a, b, e;
    cout << "Numar noduri si culori: ";
    cin >> n >> m;

    cout << "Numar muchii: ";
    cin >> e;

    for (int i = 1; i <= e; i++) {
        cin >> a >> b;
        G[a][b] = G[b][a] = 1; // graf neorientat
    }

    colorare_graf(1);

    return 0;
}
