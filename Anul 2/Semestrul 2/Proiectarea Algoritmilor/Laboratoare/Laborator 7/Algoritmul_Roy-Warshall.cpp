#include <iostream>
using namespace std;

int a[101][101];
int d[101][101];
int CC[101];
int nrc = 0;
int n;
int i, j, k;

void roy_warshall() {

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] > 0)
                d[i][j] = 1;
            else
                d[i][j] = 0;


    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
}

void componente_tare_conexe() {
    nrc = 0;
    for (i = 1; i <= n; i++)
        CC[i] = 0;

    roy_warshall();

    for (i = 1; i <= n; i++) {
        if (CC[i] == 0) {
            nrc++;
            CC[i] = nrc;
            for (j = i + 1; j <= n; j++) {
                if (CC[j] == 0 && d[i][j] == 1 && d[j][i] == 1)
                    CC[j] = nrc;
            }
        }
    }
}

int main() {
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];

    componente_tare_conexe();

    cout << "Numarul de componente tare conexe: " << nrc << endl;
    for (i = 1; i <= n; i++)
        cout << "Nodul " << i << " apartine componentei " << CC[i] << endl;

    return 0;
}
