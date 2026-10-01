#include <iostream>

using namespace std;
int n;
int c_steluta[10][10],c[10][10];
void roy_floyd()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            c_steluta[i][j]=c[i][j];

        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(c_steluta[i][k]+c_steluta[k][j]<c_steluta[i][j])
                {
                    c_steluta[i][j]=c_steluta[i][k]+c_steluta[k][j];
                }
            }
        }
    }
}
int main() {

    cout << "n = ";
    cin >> n;


    const int INF = 1000000000;
    cout << "Matricea de costuri :\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (i == j && x == 0)
                c[i][j] = 0;
            else if (x == 0)
                c[i][j] = INF;
            else
                c[i][j] = x;
        }
    }


    roy_floyd();


    cout << "Distantele minime intre oricare doua noduri:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (c_steluta[i][j] == INF)
                cout << "INF ";
            else
                cout << c_steluta[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
