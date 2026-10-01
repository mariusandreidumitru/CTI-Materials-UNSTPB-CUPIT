#include <iostream>

using namespace std;

int x,p,u,m;

void SORTINSBIN(int A[],int n)
{
    for(int i=2;i<=n;i++)
    {
        x=A[i];
        p=1;
        u=i-1;

        while(p<=u)
        {
            m=(p+u)/2;

            if(x<A[m]) u=m-1;

            else p=m+1;
        }

        for(int j=i-1;j>=p;j--)
        {
            A[j+1]=A[j];
        }
        A[p]=x;
    }
}
int main()
{
    int A[101],n;

    cin>>n;

    for(int i=1;i<=n;i++)
            cin>>A[i];

    SORTINSBIN(A,n);

    for(int i=1;i<=n;i++)
            cout<<A[i]<<" ";

    return 0;
}
