#include <iostream>

using namespace std;

int x[100],n,m,k;
void AFISARE(int x[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}
void COMBINARI(int m,int n)
{
    k=1;
    x[1]=0;

    while(k>0)
    {
        if(x[k]<(m-n+k))
        {
            x[k]=x[k]+1;

            if(k==n)
            {
                AFISARE(x,n);
            }
            else
            {
                k=k+1;
                x[k]=x[k-1]-1;
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

    COMBINARI(m,n);

    return 0;
}
