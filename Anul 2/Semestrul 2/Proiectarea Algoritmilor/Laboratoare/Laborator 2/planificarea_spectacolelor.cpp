#include <iostream>

using namespace std;

void SORTARE(double a[],double b[],int n)
{
    float aux_a,aux_b;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]>a[j] && b[i]>b[j])
            {
                swap(a[i],a[j]);
                swap(b[i],b[j]);

            }
        }
    }

}
void AFISARE(int m,double c[],int n,double a[],double b[])
{

    cout<<m<<endl;

    for(int i=1;i<=n;i++)
        if(c[i]==1)
        {
            cout<<a[i]<<" "<<b[i]<<" ";
        }
}
void SPECTACOLE2(double a[],double b[],int n,double c[],int &m)
{
    SORTARE(a,b,n);

    m=0;

    for(int i=1;i<=n;i++)
    {
        c[i]=0;
    }


    double t;

    t=b[n]+1;

    for(int i=n;i>=1;i--)
    {
        if(b[i]<t)
        {
            c[i]=1;
            m=m+1;
            t=a[i];
        }
    }
    AFISARE(m,c,n,a,b);
}
int main()
{
    double a[100],b[100],c[100];

    int n,m;

    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
        cin>>b[i];

    SPECTACOLE2(a,b,n,c,m);
    return 0;
}
