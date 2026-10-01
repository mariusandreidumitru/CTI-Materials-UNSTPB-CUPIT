#include <iostream>

using namespace std;

int x[100],y[100],a[100],m,n,k;

void AFISARE(int x[],int a[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<a[x[i]]<<" ";
    cout<<endl;
}
void ARANJAMENTE2(int m,int n)
{
    k=1;
    x[1]=0;

    while(k>0)
    {
        if(x[k]<m)
        {
            x[k]=x[k]+1;
            if(y[x[k]]==0)
            {
                if(k==n)
                {
                    AFISARE(x,a,n);
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
    cin>>m>>n;

     for (int i = 1; i <= m; i++)
        cin >> a[i];

    ARANJAMENTE2(m,n);

    return 0;
}
