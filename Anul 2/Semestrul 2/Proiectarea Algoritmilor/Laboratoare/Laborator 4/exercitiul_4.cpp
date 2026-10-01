#include <iostream>

#include <cmath>

using namespace std;

int tito(int n)
{
    if(n==1) return 3;
    else return tito(n-1)+3*n-2;
}
int f(int n)
{
    return (3*n*n-n+4)/2;
}


int main()
{
    int n;
    cin>>n;
    if(n<=0) cout<<"n trebuie sa fie pozitiv";
    else cout<<tito(n)<<endl<<f(n);

    return 0;
}
