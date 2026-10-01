#include <iostream>
using namespace std;

void AFISARE(int x[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void PRODUS_CARTEZIAN(int n, int m[])
{
    int k = 1, x[100];
    x[1]=0;


    while (k > 0)
    {
        if (x[k] < m[k])
        {
            x[k] = x[k] + 1;
            if (k == n)
                AFISARE(x, n);
            else
            {
                k = k + 1;
                x[k] = 0;
            }
        }
        else
        {
            k = k - 1;
        }
    }
}

int main()
{
    int n, m[100];
    cin >> n ;

    for(int i=1;i<=n;i++)
        cin>>m[i];
    PRODUS_CARTEZIAN(n, m);
    return 0;
}
