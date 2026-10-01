#include <iostream>


using namespace std;

int f[10][10], c[10][10], r[10][10], TATA[100], SEL[100], rmin, vmax, n, i, j, m[10][10];


void CALCUL_REZIDUURI()
{
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (f[i][j] < c[i][j])
                r[i][j] = c[i][j] - f[i][j];
            else
            {
                if (f[j][i] > 0)
                    r[i][j] = f[j][i];
                else
                    r[i][j] = 0;
            }
        }
    }
}


void DF(int i)
{
    for (j = 1; j <= n; j++)
    {
        if (r[i][j] > 0 && SEL[j] == 0)
        {
            TATA[j] = i;
            SEL[j] = 1;
            DF(j);
        }
    }
}


void DET_LANT_CR()
{
    j = n;
    rmin = 9999;
    while (j != 1)
    {
        i = TATA[j];
        if (rmin > r[i][j])
            rmin = r[i][j];
        j = i;
    }
}


void MARIRE_FLUX()
{
    j = n;
    while (j != 1)
    {
        i = TATA[j];
        if (c[i][j] > f[i][j])
            f[i][j] = f[i][j] + rmin;
        else
            f[j][i] = f[j][i] - rmin;
        j = i;
    }
}


void CITIRE_RETEA()
{
    cout << "Introdu numarul de noduri: ";
    cin >> n;
    cout << "Introdu matricea capacitatilor \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> m[i][j];
            c[i][j] = m[i][j];
        }
    }
}


void AFISARE_REZULTATE()
{
    cout << "Fluxul maxim: " << vmax << endl;


    cout << "Noduri in setul S (SEL[i] = 1): ";
    for (int i = 1; i <= n; i++)
    {
        if (SEL[i] == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "Noduri in setul T (SEL[i] = 0): ";
    for (int i = 1; i <= n; i++)
    {
        if (SEL[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "Capacitatile utilizate \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (f[i][j] > 0)
            {
                cout << "Flux in (de la " << i << " la " << j << "): " << f[i][j] << endl;
            }
        }
    }
}


void FORD_FULKERSON()
{
    CITIRE_RETEA();


    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            f[i][j] = 0;
        }
    }

    vmax = 0;


    do
    {
        CALCUL_REZIDUURI();
        SEL[1] = 1;
        for (i = 2; i <= n; i++)
            SEL[i] = 0;
        TATA[1] = 0;

        DF(1);

        if (SEL[n] == 1)
        {
            rmin = 9999;
            DET_LANT_CR();
            MARIRE_FLUX();
            vmax =vmax+rmin;
        }
    } while (SEL[n] == 1);



    AFISARE_REZULTATE();
}


int main()
{
    FORD_FULKERSON();
    return 0;
}
