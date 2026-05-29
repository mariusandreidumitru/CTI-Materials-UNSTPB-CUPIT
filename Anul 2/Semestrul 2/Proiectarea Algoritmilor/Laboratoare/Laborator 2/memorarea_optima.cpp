#include <iostream>

using namespace std;

void sortare(int v[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(v[i]>v[j])
            {
                int aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}
int suma_pana_la_k(int v[],int k)
{
    int s=0;
    for(int i=0;i<k;i++)
        s=s+v[i];

    return s;
}
int main()
{
    int n,k;

    cout<<"n= ";
    cin>>n;

    int v[100];

    cout<<"Introduceti lungimile textelor ";

    for(int i=0;i<n;i++)
            cin>>v[i];

    cout<<"k= ";
    cin>>k;

    sortare(v,n);

    cout<<"Lungimea totala parcursa la textul "<<k<<" este: "<<suma_pana_la_k(v,k);

    return 0;
}
