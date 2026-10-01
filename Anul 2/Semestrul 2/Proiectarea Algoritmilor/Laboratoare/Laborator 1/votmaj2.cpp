#include <iostream>

using namespace std;

void SORTARE(int V[],int n)
{
    int i,j,aux;

    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(V[i]>V[j])
            {
                aux=V[i];
                V[i]=V[j];
                V[j]=aux;
            }
        }
    }
}
int VOTMAJ2(int V[],int n,int cand)
{
    SORTARE(V,n);
    int i,j,maxim;
    i=1;
    maxim=0;
    do
    {
        j=i+1;
        while(j<=n && V[j]==V[i])
        {
            j=j+1;
        }
        if(j-i>maxim)
        {
            maxim=j-i;
            cand=V[i];

            if(maxim>n/2)
                return cand;
        }
        i=j;
    }while(i<=(n+1)/2);
}
int main()
{
    int i,j,V[100],n,cand;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>V[i];

    cout<<VOTMAJ2(V,n,cand);


    return 0;
}
