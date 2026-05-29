#include <iostream>

using namespace std;

int x[100],m,n,k;
int VALID(int x[],int k)
{
    for(int i=1;i<=k-1;i++)
        if(x[k]==x[i])
            return 0;
    return 1;
}
void AFISARE(int x[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}
void ARANJAMENTE1(int m,int n)
{
    k=1;
    x[1]=0;

    while(k>0)
    {
        if(x[k]<m)
        {
            x[k]=x[k]+1;
            if(VALID(x,k))
            {
                if(k==n)
                {
                    AFISARE(x,n);
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
    cin>>m>>n;

    ARANJAMENTE1(m,n);

    return 0;
}
