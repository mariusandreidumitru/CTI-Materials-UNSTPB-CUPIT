#include <iostream>

using namespace std;

int A[101][101];
int S[101][101];
int P[101][101];
int t[101];
int m, n;
int M, t1;
int i, j;
void DRUMMIN2(int A[101][101],int m,int n)
{
    for (int j = 1; j <= n; j++) {
        S[1][j] = A[1][j];
    }


    for (int i = 1; i <= m - 1; i++) {
        P[i][1] = 0;
        if (S[i][2] < S[i][1])
            P[i][1] = 1;
        S[i + 1][1] = A[i + 1][1] + S[i][1 + P[i][1]];

        for (int j = 2; j <= n - 1; j++) {
            P[i][j] = 0;
            if (S[i][j] < S[i][j - 1])
                P[i][j] = -1;
            if (S[i][j + 1] < S[i][j + P[i][j]])
                P[i][j] = 1;
            S[i + 1][j] = A[i + 1][j] + S[i][j + P[i][j]];
        }

        P[i][n] = 0;
        if (S[i][n] < S[i][n - 1])
            P[i][n] = -1;
        S[i + 1][n] = A[i + 1][n] + S[i][n + P[i][n]];
    }

    M = S[m][1];
    t[m] = 1;
    for (int j = 2; j <= n; j++) {
        if (S[m][j] < M) {
            M = S[m][j];
            t[m] = j;
        }
    }

    for (int i = m - 1; i >= 1; i--) {
        t[i] = t[i + 1] + P[i][t[i + 1]];
    }

    cout << M << endl;
    for (int i = 1; i <= m; i++) {
        cout << A[i][t[i]] << " ";
    }
    cout << endl;
}
int main()
{

    cin>>m>>n;

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            cin>>A[i][j];

    DRUMMIN2(A,m,n);
    return 0;
}
