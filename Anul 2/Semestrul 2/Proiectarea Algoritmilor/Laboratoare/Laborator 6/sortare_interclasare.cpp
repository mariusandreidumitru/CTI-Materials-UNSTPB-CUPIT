#include <iostream>

using namespace std;

int A[100], B[100], i, j, k, p, q, u, m, n;

void INTERCLAS(int A[], int p, int u, int m)
{
    i = p;
    j = m + 1;
    k = 0;

    while (i <= m && j <= u)
    {
        if (A[i] <= A[j])
        {
            k++;
            B[k] = A[i];
            i++;
        }
        else
        {
            k++;
            B[k] = A[j];
            j++;
        }
    }
    for (int q = i; q <= m; q++)
    {
        k++;
        B[k] = A[q];
    }
    for (int q = j; q <= u; q++)
    {
        k++;
        B[k] = A[q];
    }

    for (i = 1; i <= k; i++)
        A[p + i - 1] = B[i];
}

void SORTINT(int A[], int p, int u)
{
    if (p < u)
    {
        m = (p + u) / 2;

        SORTINT(A, p, m);
        SORTINT(A, m + 1, u);

        INTERCLAS(A, p, u, m);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    SORTINT(A, 1, n);

    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    return 0;
}
