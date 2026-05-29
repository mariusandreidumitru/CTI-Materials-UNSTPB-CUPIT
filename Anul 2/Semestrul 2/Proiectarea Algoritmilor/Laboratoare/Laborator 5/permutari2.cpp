#include <iostream>

using namespace std;

int x[100],y[100],n,k;

void AFISARE(int x[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}


void PERMUTARI2(int n)
{
    k=1;
    x[1]=0;

    while(k>0)
    {
        if(x[k]<n)
        {
            x[k]=x[k]+1;
            if(y[x[k]]==0)
            {
                if(k==n)
                {
                    AFISARE(x,n);
                    k=k-1;
                    y[x[k]]=0;
                }
                else
                {
                    y[x[k]]=1;
                    k=k+1;
                    x[k]=0;
                }
            }
        }
        else
        {
            k=k-1;
            y[x[k]]=0;
        }
    }
}
int main()
{
    cin>>n;
    PERMUTARI2(n);
    return 0;
}
