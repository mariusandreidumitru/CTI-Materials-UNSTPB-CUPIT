#include <iostream>

using namespace std;

int L[101],P[101],i,j,k,t[101],A[101],m;
void SUBSIRMAX2(int A[],int n)
{
    L[1]=1;

    for(i=2;i<=n;i++)
    {
        L[i]=1;
        P[i]=-1;

        for(j=1;j<=i-1;j++)
        {
            if((A[j]<=A[i]) && (1+L[j]>L[i]))
            {
                L[i]=1+L[j];
                P[i]=j;
            }
        }
    }
    k=L[1];
    m=1;

    for(i=2;i<=n;i++)
    {
        if(L[i]>k)
        {
            k=L[i];
            m=i;
        }
    }
    t[k]=m;
    for(j=k-1;j>=1;j--)
    {
        t[j]=P[t[j+1]];
    }
    for(j=1;j<=k;j++)
        cout<<A[t[j]]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>A[i];

    SUBSIRMAX2(A,n);
    return 0;
}
