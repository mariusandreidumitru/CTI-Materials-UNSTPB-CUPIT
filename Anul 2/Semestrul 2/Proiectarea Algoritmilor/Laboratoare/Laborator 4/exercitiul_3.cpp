#include <iostream>

#include <cmath>

using namespace std;

int tito(int n)
{
    if(n==1) return 1;
    else return 3*tito(n-1)+2*n-1;
}
int f(int n)
{
    return pow(3,n)-n-1;
}


int main()
{
    int n;
    cin>>n;
    if(n<=0) cout<<"n trebuie sa fie pozitiv";
    else cout<<tito(n)<<endl<<f(n);

    return 0;
}
