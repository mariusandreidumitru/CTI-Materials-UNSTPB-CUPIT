#include <iostream>

using namespace std;

int F[101],i,m;
void SORTNUMFRECV(int A[],int n,int B[])
{
    for(int k=1;k<=n;k++)
        F[k]=0;

    for(int i=1;i<=n;i++)
        F[A[i]]=F[A[i]]+1;


    for(int k=1;k<=m;k++)
    {
        for(int j=1;j<=F[k];j++)
        {
            i=i+1;
            B[i]=k;
        }
    }
}
int main()
{
    int A[101],B[101],n;
    cin>>n;

    m = 0;

    for(int i=1;i<=n;i++)
        cin>>A[i];

    SORTNUMFRECV(A,n,B);

    for(int i=1;i<=n;i++)
        cout<<B[i]<<" ";
    return 0;
}
