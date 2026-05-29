#include <iostream>

using namespace std;

int S[10][10],i,j,n,ip,jp,ip1,ip2,ip3,ip4,jp1,jp2,jp3,jp4,p,m,i1,i2,i3,i4,j1,j2,j3,j4;
void ACOPERIRE(int S[10][10],int i,int j,int n,int ip,int jp)
{
    if(n>1)
    {
        p=p+1;
        m=n/2;

        i1=i;j1=j;
        i2=i;j2=j+m;
        i3=i+m;j3=j;
        i4=i+m;j4=j+m;

        ip1=ip;jp1=jp;
        ip2=ip;jp2=jp;
        ip3=ip;jp3=jp;
        ip4=ip;jp4=jp;

        if(i3<=ip)
        {
            ip1=i1+m-1; jp1=j1+m-1;
            ip2=i2+m-1; jp2=j2;
            S[ip1][ip2]=p; S[ip2][jp2]=p;
        }
        else
        {
            ip3=i3;jp3=j3+m-1;
            ip4=i4;jp4=j4;
            S[ip3][jp3]=p; S[ip3][jp4]=p;
        }
        if(j2<=jp)
        {
            ip1=i1+m-1;jp1=j1+m-1;
            ip3=i3;jp3=j3+m-1;
            S[ip1][jp1]=p;S[ip3][jp3]=p;
        }
        else
        {
            ip2=i2+m-1;jp2=j2;
            ip4=i3;jp3=j3+m-1;
            S[ip2][jp2]=p;S[ip4][jp4]=p;
        }
        ACOPERIRE(S,i1,j1,m,ip1,jp1);
        ACOPERIRE(S,i2,j2,m,ip2,jp2);
        ACOPERIRE(S,i3,j3,m,ip3,jp3);
        ACOPERIRE(S,i4,j4,m,ip4,jp4);
    }
}
int main()
{
    cin>>n;
    cin>>ip>>jp;
    ACOPERIRE(S,1,1,n,ip,jp);
    for(i=1;i<=n;i++)
    {
          for(j=1;j<=n;j++)
          {
               cout<<S[i][j]<<" ";
          }
           cout<<endl;
    }

    return 0;
}
