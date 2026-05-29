#include <iostream>
using namespace std;

int A[101], B[101], P1[101][101], P2[101][101], L[101][101], s[101], t[101];
int i, j, k, m, n;

void SUBSIRCOMUNMAX2(int A[], int m, int B[], int n)
{

    for (j = 0; j <= n; j++) {
        L[0][j] = 0;
        P1[0][j] = -1;
        P2[0][j] = -1;
    }
    for (i = 0; i <= m; i++) {
        L[i][0] = 0;
        P1[i][0] = -1;
        P2[i][0] = -1;
    }


    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (A[i] == B[j]) {
                L[i][j] = 1 + L[i - 1][j - 1];
                P1[i][j] = i;
                P2[i][j] = j;
            }
            else if (L[i][j - 1] >= L[i - 1][j]) {
                L[i][j] = L[i][j - 1];
                P1[i][j] = P1[i][j - 1];
                P2[i][j] = P2[i][j - 1];
            }
            else {
                L[i][j] = L[i - 1][j];
                P1[i][j] = P1[i - 1][j];
                P2[i][j] = P2[i - 1][j];
            }
        }
    }

    k = L[m][n];
    if (k == 0) {
        cout << "nu exista subsir comun";
    }
    else {
        s[k] = P1[m][n];
        t[k] = P2[m][n];

        for (j = k - 1; j >= 1; j--) {
            s[j] = P1[s[j + 1] - 1][t[j + 1] - 1];
            t[j] = P2[s[j + 1] - 1][t[j + 1] - 1];
        }

        for (j = 1; j <= k; j++)
            cout << "(" << A[s[j]] << ", " << B[t[j]] << ")" << endl;
    }
}

int main()
{
    cin >> n;
    m = n;
    for (i = 1; i <= m; i++)
        cin >> A[i];
    for (j = 1; j <= n; j++)
        cin >> B[j];

    SUBSIRCOMUNMAX2(A, m, B, n);
    return 0;
}
