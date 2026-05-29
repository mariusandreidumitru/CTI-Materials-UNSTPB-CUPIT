#include <iostream>

using namespace std;
int i, j, c, m, n, l, P[101][101], s[101], CC[101], k, x, y, aux;

void SORTARE(int P[][101])
{
    for (int i = 1; i <= m-1; i++)
        for (int j = i + 1; j <= m; j++)
            if (P[i][3] > P[j][3])
                for(int l=i;l<=m-1;l++)
                    for (int c = 1; c <= 3; c++)
                        swap(P[l][c], P[l+1][c]);
}

double KRUSKAL()
{
    SORTARE(P);

    for (i = 1; i <m; i++)
        s[i] = 0;

    for (i = 1; i < n; i++)
        CC[i] = i;

    int cost = 0;
    int poz = 0;

    for (int l = 1; l < n - 1; l++)
    {
        k = poz;
        do
        {
            k = k + 1;
            x = P[1][k];
            y = P[2][k];
            c = P[3][k];
        } while (CC[x] == CC[y]);

        s[k] = 1;
        cost = cost + c;
        poz = k;
        aux = CC[y];

        for (i = 1; i < n; i++)
        {
            if (CC[i] == aux)
                    CC[i] = CC[x];
        }
    }

}

int main()
{
    cin >> n;
    cin >> m;
    for (i = 1; i <= 3; i++)
        for (j = 1; j <= m; j++)
            cin >> P[i][j];

    double cost = KRUSKAL();
    cout << "Costul arborelui minim de acoperire: " << cost << "\n";

    return 0;
}
