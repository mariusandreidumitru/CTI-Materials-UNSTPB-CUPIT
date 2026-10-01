#include <iostream>

using namespace std;

int VOTMAJ3(int V[],int n,int cand)
{
    int i,j,nv,nr=0;

    nv=0;

    for(i=1;i<=n;i++)
    {
        if(nv==0)
        {
            nv=1;
            cand=V[i];
        }
        else
        {
            if(V[i]==cand)
               nv=nv+1;

            else
                nv=nv-1;

        }
    }
    if(nv==0) return 0;

    else
    {
        nv=0;
        for(i=1;i<=n;i++)
        {
            if(V[i]==cand)
            {
                nr=nr+1;

                if(nr>n/2) return cand;
            }
        }
        return 0;
    }
}
int main()
{
    int i,V[100],n,cand;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>V[i];

    cout<<VOTMAJ3(V,n,cand);

    return 0;

}
