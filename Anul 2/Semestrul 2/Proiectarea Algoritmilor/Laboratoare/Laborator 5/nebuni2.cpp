#include <iostream>

#include <cmath>

using namespace std;

int k,y[100],ult,n;

int VALID2(int y[],int k)
{
    if(y[k]==k) return 0;

    for(int i=2;i<=k-1;i++)
            if((abs(y[k]-y[i]))==(abs(k-i)))
                return 0;
    return 1;
}
void AFISARE(int y[])
{
    for(int i=1;i<=n;i++)
        cout<<y[i]<<" ";
    cout<<endl;
}
void NEBUNI2(int n)
{
        k=2;
        y[2]=0;
        ult=3;

        while(k>1)
        {
            if(y[k]<ult)
            {
                y[k]=y[k]+1;
                if(VALID2(y,k))
                {
                    if(k==n-1)
                    {
                        y[1]=1;
                        AFISARE(y);
                        y[1]=n;
                        AFISARE(y);
                    }
                    else
                    {
                        k=k+1;
                        if(k<=((n+1)/2))
                        {
                            y[k]=0;
                            ult=2*k-1;
                        }
                        else
                        {
                            y[k]=2*k-n-1;
                            ult=n;
                        }
                    }
                }
            }
            else
            {
                k=k-1;

                if(k<=((n+1)/2))
                {
                    ult=2*k-1;
                }
                else
                {
                    ult=n;
                }
            }
        }
}
int main()
{

    cin>>n;
    NEBUNI2(n);
    return 0;
}
