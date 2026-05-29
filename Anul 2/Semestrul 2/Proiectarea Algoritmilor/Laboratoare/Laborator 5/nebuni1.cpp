#include <iostream>
#include <cmath>

using namespace std;

int k, x[100], ult, n;

int VALID1(int x[], int k)
{
    for (int i = 1; i <= k - 1; i++)
    {
        if (abs(x[k] - x[i]) == abs(k - i))
            return 0;
    }
    return 1;
}

void AFISARE(int x[])
{
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void NEBUNI1(int n)
{
    k = 1;
    x[k] = 0;
    ult = 2;

    while (k > 0)
    {
        if (x[k] < ult)
        {
            x[k] = x[k] + 1;

            if (VALID1(x, k))
            {
                if (k == n-1)
                {
                    AFISARE(x);
                }
                else
                {
                    k = k + 1;

                    if (k <= (n / 2))
                    {
                        x[k] = 0;
                        ult = 2 * k;
                    }
                    else
                    {
                        x[k] = 2 * k - n;
                        ult = n;
                    }
                }
            }
        }
        else
        {
            k = k - 1;

            if (k <= (n / 2))
            {
                ult = 2 * k;
            }
            else
            {
                ult = n;
            }
        }
    }
}

int main()
{
    cin >> n;
    NEBUNI1(n);
    return 0;
}
