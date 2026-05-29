#include <iostream>

using namespace std;

void SORTARE(int a[],int b[],int n)
{
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
void AFISARE(int s,int a[],int b[],int n)
{
    cout<<"Suma= "<<s<<endl;

    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" "<<endl;
        cout<<b[i]<<" "<<endl;
    }

}
void MAXIM2(int a[],int b[],int n,int s)
{
    SORTARE(a,b,n);

    s=0;

    for(int i=1;i<=n;i++)
    {
        s=s+a[i]*b[i];
    }
    AFISARE(s,a,b,n);
}
int main()
{
    int a[100],b[100],n,s;

    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
        cin>>b[i];

    MAXIM2(a,b,n,s);

    return 0;
}
