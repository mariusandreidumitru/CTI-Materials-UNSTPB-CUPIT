#include <iostream>

using namespace std;

int p;


int CAUTBIN_REC(int A[], int p, int u, int x) {
    if (p > u)
        return -1;

    int m = (p + u) / 2;

    if (A[m] == x)
        return m;
    else if (x < A[m])
        return CAUTBIN_REC(A, p, m - 1, x);
    else
        return CAUTBIN_REC(A, m + 1, u, x);
}
int main()
{
    int A[100],i,poz,n,m,x;

    cin>>n;

    for(i=1;i<=n;i++)
        cin>>A[i];

    cin>>x;

    poz = CAUTBIN_REC(A, n, 1,n, x);

    if (poz == -1)
        cout << "Elementul nu a fost gasit.\n";
    else
        cout << "Elementul se afla pe pozitia " << poz << ".\n";
    return 0;
}
