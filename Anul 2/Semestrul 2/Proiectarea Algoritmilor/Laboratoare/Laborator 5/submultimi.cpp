#include <iostream>

using namespace std;

void AFISARE(int x[],int a[],int n)
{
    for(int i=1;i<=n;i++)
        if(x[i]==1) cout<<a[i]<<" ";
        cout<<endl;
}
void SUBMULTIMI(int a[],int n)
{
    int k,x[100];

    k=1;
    x[1]=0;

    while(k>0)
    {
        if(x[k]<2)
        {
            x[k]=x[k]+1;
            if(k==n)
                AFISARE(x,a,n);
            else
            {
                k=k+1;
                x[k]=0;
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
    int a[100],n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    SUBMULTIMI(a,n);
    return 0;
}
