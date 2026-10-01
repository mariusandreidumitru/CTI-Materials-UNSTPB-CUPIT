#include <iostream>

using namespace std;



int n, capacitate[10][10], flux[10][10];
int tata[100], vizitat[100];

int BFS(int sursa, int destinatie) {
    for (int i = 0; i < n; i++) {
        vizitat[i] = 0;
        tata[i] = -1;
    }

    int coada[100], inceput = 0, sfarsit = 0;
    coada[sfarsit++] = sursa;
    vizitat[sursa] = 1;

    while (inceput < sfarsit) {
        int nod = coada[inceput++];

        for (int i = 0; i < n; i++) {
            if (!vizitat[i] && capacitate[nod][i] - flux[nod][i] > 0) {
                coada[sfarsit++] = i;
                tata[i] = nod;
                vizitat[i] = 1;
                if (i == destinatie) return 1;
            }
        }
    }
    return 0;
}

int EdmondsKarp(int sursa, int destinatie) {
    int fluxMaxim = 0;

    while (BFS(sursa, destinatie)) {
        int fluxMinim = 9999;

        int v = destinatie;
        while (v != sursa) {
            int u = tata[v];
            fluxMinim = min(fluxMinim, capacitate[u][v] - flux[u][v]);
            v = tata[v];
        }

            v = destinatie;
        while (v != sursa) {
            int u = tata[v];
            flux[u][v] += fluxMinim;
            flux[v][u] -= fluxMinim;
            v = tata[v];
            }


        fluxMaxim += fluxMinim;
    }
    return fluxMaxim;
}

int main() {
    cout << "Numar de noduri: ";
    cin >> n;

    cout << "Introdu matricea capacitatilor: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> capacitate[i][j];
            flux[i][j] = 0;
        }
    }

    int sursa = 0, destinatie = n - 1;
    int fluxMaxim = EdmondsKarp(sursa, destinatie);
    cout << "Fluxul maxim: " << fluxMaxim << endl;

    return 0;
}
