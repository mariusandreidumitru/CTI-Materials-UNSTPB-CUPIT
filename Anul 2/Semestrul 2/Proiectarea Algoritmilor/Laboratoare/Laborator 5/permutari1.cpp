#include <iostream>

using namespace std;

int x[100],n,k;

void AFISARE(int x[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}

int VALID(int x[],int k)
{
    for(int i=1;i<=k-1;i++)
        if(x[k]==x[i]) return 0;

    return 1;
}

void PERMUTARI1(int n)
{
    k=1;
    x[1]=0;

    while(k>0)
    {
        if(x[k]<n)
        {
            x[k]=x[k]+1;
            if(VALID(x,k))
            {
                if(k==n)
                {
                    AFISARE(x,n);
                    k=k-1;
                }
                else
                {
                    k=k+1;
                    x[k]=0;
                }
            }
        }
        else
        {
            k=k-1;
        }
    }
}
int main()
{
    cin>>n;
    PERMUTARI1(n);
    return 0;
}
