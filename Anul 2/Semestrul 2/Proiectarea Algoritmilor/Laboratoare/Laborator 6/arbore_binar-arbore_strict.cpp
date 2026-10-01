#include <iostream>

using namespace std;

void numaraFii(int TATA[], int nrFii[], int n) {
    for (int i = 1; i <= n; ++i)
        if (TATA[i] != 0)
            nrFii[TATA[i]]++;
}

bool esteBinar(int nrFii[], int n) {
    for (int i = 1; i <= n; ++i)
        if (nrFii[i] > 2)
            return false;
    return true;
}

bool esteBinarStrict(int nrFii[], int n) {
    for (int i = 1; i <= n; ++i)
        if (nrFii[i] != 0 && nrFii[i] != 2)
            return false;
    return true;
}

int main()
{
    int n,TATA[100]={0},nrFii[100] = {0};
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> TATA[i];

    numaraFii(TATA, nrFii, n);

    cout << " Arborele " << (esteBinar(nrFii, n) ? "este" : "NU este") << " binar.\n";
    cout << " Arborele " << (esteBinarStrict(nrFii, n) ? "este" : "NU este") << " binar strict.\n";
    return 0;
}
