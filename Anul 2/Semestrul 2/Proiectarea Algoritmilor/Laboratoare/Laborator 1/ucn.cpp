#include <iostream>

using namespace std;

int UCNF2(int n)
{
    int p,a,b,c,i;
    a=0;b=0;c=1;

    for(int k=1;k<=n;k++)
    {
        p=k;
        while(p%2==0)
        {
            a=a+1;
            p=p/2;
        }
        while(p%5==0)
        {
            b=b+1;
            p=p/5;
        }
        c=(c*p)%10;
    }

    if(a==b)
        return c;
    else
    {
        if(a<b) return 5;
        else
        {

            for(i=1;i<=(a-b)%4;i++)
                c=2*c;
            return (6*c)%10;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<UCNF2(n);
    return 0;
}
