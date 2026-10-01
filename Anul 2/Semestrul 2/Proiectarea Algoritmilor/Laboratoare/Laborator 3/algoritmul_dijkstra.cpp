#include <iostream>

using namespace std;

int S[100],t[100],TATA[100],c[100][100],minim,x,n,m;
void DIJKSTRA(int s)
{
    for(int i=1;i<=n;i++)
    {
        S[i]=0;
        t[i]=9999;
        TATA[i]=9999;
    }
    t[s]=0;
    TATA[s]=0;

    do
    {
        minim=9999;
        for(int i=1;i<=n;i++)
        {
            if(S[i]==0 && t[i]<minim)
            {
                minim=t[i];
                x=i;
            }
        }
        if(minim<9999)
        {
            S[x]=1;

            for(int i=1;i<=n;i++)
            {
                if(S[i]==0 && c[x][i]<9999)
                {
                    if(t[i]>t[x]+c[x][i])
                    {
                        t[i]=t[x]+c[x][i];
                        TATA[i]=x;
                    }
                }
            }
        }
    }while(minim<9999);

    for(int i=1;i<=n;i++)
         if (t[i] == 9999)
            cout << "Distanta de la " << s << " la " << i << " este infinita.\n";
        else
            cout << "Distanta de la " << s << " la " << i << " este " << t[i] << ".\n";
}
int main()
{
    cin>>n>>m;

     for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = 9999;
        }
    }
    for(int i=0;i<m;i++)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        c[u][v]=c[v][u]=cost;
    }
    int nSursa;
    cin>>nSursa;

    DIJKSTRA(nSursa);

    return 0;
}
