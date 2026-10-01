#include <iostream>

using namespace std;

int q,p,k,n,m,x[100],t[100],y[100];
void AFISARE(int x[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}
int VALID(int p,int x[],int k)
{
    q=0;

    if(p==0) return 0;

    for(int i=1;i<=k-1;i++)
    {
        if(x[i]==x[k])
        {
            q=q+1;
            if(q>=p) return 0;
        }
    }
    return 1;
}
void PERMUTARI_CU_REPETITIE2(int n,int t[],int m)
{
    n=0;

    for(int i=1;i<=m;i++)
        n=n+t[i];

    for(int i=1;i<=m;i++)
        y[i]=0;
    k=1;
    x[1]=0;

    while(k>0)
    {
        if(x[k]<m)
        {
            x[k]=x[k]+1;

            if(y[x[k]]<t[x[k]])
            {
                if(k==n)
                {
                    AFISARE(x,n);
                    k=k-1;
                    y[x[k]]=y[x[k]]-1;
                }
                else
                {
                    y[x[k]]=y[x[k]]+1;
                    k=k+1;
                    x[k]=0;
                }
            }
        }
        else
        {
            k=k-1;
            y[x[k]]=y[x[k]]-1;
        }
    }
}
int main()
{
    cin>>m;

    for(int i=1;i<=m;i++)
        cin>>t[i];

    PERMUTARI_CU_REPETITIE2(n,t,m);
    return 0;
}
