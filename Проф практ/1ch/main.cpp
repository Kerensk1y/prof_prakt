#include <iostream>
#include <locale.h>
#include "plant.h"
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

void vvod (size_t &k, size_t M[20], size_t &L1, size_t &N, double &A, double &B)
{
    cout << "Enter k\n";
    cin >> k;
    cout << "Enter M\n";
    for (size_t i=1;i<=k; i++)
    {
        cin >> M[i];
    }
    cout << "Enter L1\n";
    cin >> L1;
    cout << "Enter N\n";
    cin >> N;
    cout << "Enter A\n";
    cin >> A;
    cout << "Enter B\n";
    cin >> B;
}


void raschet (size_t &k, size_t M[20], size_t &L1, size_t &N, double &A, double &B)
{
    Plant plant;
    plant_init(plant);
    double X[50][50], Z[50][50], Xmin[50], Xmax[50], Y[50];


    for (size_t i=1; i<=k; i++)
    {
        if (i==1)
        {
            cout << " N";
        }
        if (i==3)
        {
            cout << '\t';
        }
        cout << "\tX" << i;
    }
    cout << "\tY\n";


    for (size_t r=1; r<=N; r++)
    {
        if (r < 10)
        {
            cout << ' ';
        }
        cout << r << '|';

        for (size_t i=1; i<=k; i++)
        {
            X[r][i] = plant_measure(M[i], plant);
            cout << X[r][i] << '\t';
            if (i==2)
            {
                cout << '\t';
            }
        }
        Y[r] = plant_measure(L1, plant);
        cout << Y[r] << '\n';
    }
    cout << '\n';


    //4punct
    for (size_t i=1; i<=k; i++)
    {
        Xmin[i] = X[1][i];
        Xmax[i] = X[1][i];
    }


    for (size_t j=1; j<=k; j++)
    {
        for (size_t i=1; i<=N; i++)
        {
            if (Xmin[j] > X[i][j])
            {
                Xmin[j] = X[i][j];
            }

            if (Xmax[j] < X[i][j])
            {
                Xmax[j] = X[i][j];
            }
        }
    }


    //5punct
    for (size_t i=1; i<=k; i++)
    {
        for (size_t j=1; j<=N; j++)
        {
            Z[j][i] = A + B*(X[j][i]-Xmin[i])/(Xmax[i]-Xmin[i]);
        }
    }


    //7punct
    for (size_t i=1; i<=k; i++)
    {
        if (i==1)
        {
            cout << "   ";
        }
        if (i==3)
        {
            cout << '\t';
        }
        cout << "Xmin" << i << '\t';
    }
    cout << '\n';


    for (size_t i=1; i<=k; i++)
    {
        if (i==1)
        {
            cout << "   ";
        }
        if (i==3)
        {
            cout << '\t';
        }
        cout << Xmin[i] << '\t';
    }
    cout << '\n';



    for (size_t i=1; i<=k; i++)
    {
        if (i==1)
        {
            cout << "   ";
        }
        if (i==3)
        {
            cout << '\t';
        }
        cout << "Xmax" << i << '\t';
    }
    cout << '\n';



    for (size_t i=1; i<=k; i++)
    {
        if (i==1)
        {
            cout << "   ";
        }
        if (i==3)
        {
            cout << '\t';
        }
        cout << Xmax[i] << '\t';
    }
    cout << "\n\n";


    for (size_t i=1; i<=k; i++)
    {
        if (i==1)
        {
            cout << " N";
        }
        if (i==3)
        {
            cout << '\t';
        }
        cout << "\tZ" << i;
    }
    cout << '\n';

    for (size_t i=1; i<=N; i++)
    {
        if (i < 10)
        {
            cout << ' ';
        }
        cout << i << '|';
        for (size_t j=1; j<=k; j++)
        {
            cout << fixed << Z[i][j] << '\t';
        }
        cout << '\n';
    }
}


int main ()
{
    size_t k, M[20], L1, N;
    double A, B;
    vvod (k, M, L1, N, A, B);
    raschet(k, M, L1, N, A, B);
}
