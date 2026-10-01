#include <iostream>

using namespace std;

void SORTARE(float g[],float c[],int n)
{
    float aux_g,aux_c;

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {

            if((c[i]/g[i])<(c[j]/g[j]))
            {
                aux_g=g[i];
                g[i]=g[j];
                g[j]=aux_g;

                aux_c=c[i];
                c[i]=c[j];
                c[j]=aux_c;

            }
        }
    }
}
void AFISARE(float C,float x[],int n)
{
    cout<<C<<endl;

    for(int i=1;i<=n;i++)
        cout<<x[i]<<" ";

    cout<<endl;
}
void RUCSAC(float G,int n,float g[],float c[],float x[],float C)
{
    SORTARE(g,c,n);

    C=0;

    int i;
    float R;

    for(i=1;i<=n;i++)
        x[i]=0;

    R=G;
    i=1;

    while(R>0)
    {
        if(g[i]<=R)
        {
            x[i]=1;
            C=C+c[i];
            R=R-g[i];
            i=i+1;
        }
        else
        {
            x[i]=R/g[i];
            C=C+x[i]*c[i];
            R=0;
        }
    }
    AFISARE(C,x,n);
}

int main()
{
    int n;
    float G;

    cout<<"n = ";
    cin>>n;

    cout<<"G = ";
    cin>>G;

    float g[100],c[100],x[100],C;

    for(int i=1;i<=n;i++)
    {
        cin>>g[i]>>c[i];
    }
    RUCSAC(G,n,g,c,x,C);
    return 0;
}
