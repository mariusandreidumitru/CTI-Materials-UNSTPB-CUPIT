#include <iostream>

using namespace std;

int A[101][101];
int S[101][101];
int P[101][101];
int t[101];
int m, n;
int M, t1;
int i, j;
void DRUMMIN1(int A[101][101],int m,int n)
{
    for (int j = 1; j <= n; j++) {
        S[m][j] = A[m][j];
    }


    for (int i = m - 1; i >= 1; i--) {
        P[i][1] = 0;
        if (S[i + 1][2] < S[i + 1][1])
            P[i][1] = 1;
        S[i][1] = A[i][1] + S[i + 1][1+P[i][1]];


        for (int j = 2; j <= n - 1; j++) {
            P[i][j] = -1;
            if (S[i + 1][j] < S[i + 1][j - 1])
                P[i][j] = 0;
            if (S[i + 1][j + 1] < S[i + 1][j + P[i][j]])
                P[i][j] = 1;
            S[i][j] = A[i][j] + S[i + 1][j + P[i][j]];
        }


        P[i][n] = -1;
        if (S[i + 1][n] < S[i + 1][n - 1])
            P[i][n] = 0;
        S[i][n] = A[i][n] + S[i + 1][n + P[i][n]];
    }


    int M = S[1][1];
    int t1 = 1;
    for (int j = 2; j <= n; j++) {
        if (S[1][j] < M) {
            M = S[1][j];
            t1 = j;
        }
    }



    for (int i = 2; i <= m; i++) {
        t[i] = t[i - 1] + P[i - 1][t[i - 1]];
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

    DRUMMIN1(A,m,n);
    return 0;
}
