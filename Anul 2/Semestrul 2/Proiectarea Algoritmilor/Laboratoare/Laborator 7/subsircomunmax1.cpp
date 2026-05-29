#include <iostream>

using namespace std;

int A[101],B[101],P1[11][11],P2[11][11],L[11][11],s[101],t[101],i,j,k,m;
void SUBSIRCOMUNMAX1(int A[],int m,int B[],int n)
{
    for(j=1;j<=n+1;j++)
    {
        L[m+1][j]=0;
        P1[m+1][j]=-1;
        P2[m+1][j]=-1;
    }
        for(i=m;i>=1;i--)
        {
            L[i][n+1]=0;
            P1[i][n+1]=-1;
            P2[i][n+1]=-1;

            for(j=n;j>=1;j--)
            {
                if(A[i]==B[j])
                {
                    L[i][j]=1+L[i+1][j+1];
                    P1[i][j]=i;
                    P2[i][j]=j;
                }
                else
                {
                    if(L[i][j+1]>=L[i+1][j])
                    {
                        L[i][j]=L[i][j+1];
                        P1[i][j]=P1[i][j+1];
                        P2[i][j]=P2[i][j+1];
                    }
                    else
                    {
                        L[i][j]=L[i+1][j];
                        P1[i][j]=P1[i+1][j];
                        P2[i][j]=P2[i+1][j];
                    }
                }
            }
        }
        k=L[1][1];
        if(k==0)
        {
            cout<<"nu exista subsir comun";
        }
        else
        {
            s[1]=P1[1][1];
            t[1]=P2[1][1];

            for(j=2;j<=k;j++)
            {
                s[j] = P1[s[j - 1] + 1][t[j - 1] + 1];
                t[j] = P2[s[j - 1] + 1][t[j - 1] + 1];
            }
            for(j=1;j<=k;j++)
                cout << "(" << A[s[j]] << ", " << B[t[j]] << ")" << endl;

            cout<<endl;
        }

}
int main()
{
    int n;
    cin>>n;
    m=n;
    for(i=1;i<=m;i++)
        cin>>A[i];

    for(j=1;j<=n;j++)
        cin>>B[j];

    SUBSIRCOMUNMAX1(A,m,B,n);
    return 0;
}
