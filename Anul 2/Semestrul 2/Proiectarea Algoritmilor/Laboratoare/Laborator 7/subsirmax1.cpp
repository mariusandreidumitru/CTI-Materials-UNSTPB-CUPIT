#include <iostream>

using namespace std;

int L[101],P[101],i,j,k,t[101],A[101],t1;
void SUBSIRMAX1(int A[],int n)
{
    L[n]=1;

    for(i=n-1;i>=1;i--)
    {
        L[i]=1;
        P[i]=-1;

        for(j=i+1;j<=n;j++)
        {
            if((A[j]>A[i]) && (1+L[j]>L[i]))
            {
                L[i]=1+L[j];
                P[i]=j;
            }
        }
    }
    k=L[1];
    t[1]=1;

    for(i=2;i<=n;i++)
    {
        if(L[i]>k)
        {
            k=L[i];
            t[1]=i;
        }
    }
    for(j=2;j<=k;j++)
    {
        t[j]=P[t[j-1]];
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

    SUBSIRMAX1(A,n);
    return 0;
}
