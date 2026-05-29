#include <iostream>

using namespace std;

int CAUTBIN(int A[],int n,int x)
{
    int p=1,u=n,m;

    while(p<=u)
    {
        m=(p+u)/2;

        if(x==A[m]) return m;

        else
        {
            if(x<A[m]) u=m-1;
            else p=m+1;
        }
    }
    return -1;
}
int main()
{
     int A[100],i,poz,n,m,x;

    cin>>n;

    for(i=1;i<=n;i++)
        cin>>A[i];

    cin>>x;

    poz = CAUTBIN(A, n, x);

    if (poz == -1)
        cout << "Elementul nu a fost gasit.\n";
    else
        cout << "Elementul se afla pe pozitia " << poz << ".\n";
    return 0;
}
