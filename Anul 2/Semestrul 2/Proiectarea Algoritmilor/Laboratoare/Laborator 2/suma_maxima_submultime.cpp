#include <iostream>

using namespace std;

int suma_maxima_submultime(int v[],int n)
{
    int smax=0;
    int maxim=v[0];

    for(int i=0;i<n;i++)
    {
        if(v[i]>0)
            smax=smax+v[i];

        if(v[i]>maxim)
            maxim=v[i];
    }
    if(smax==0)
        return maxim;

    return smax;
}
int main()
{
    int v[100],n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<suma_maxima_submultime(v,n);

    return 0;
}
