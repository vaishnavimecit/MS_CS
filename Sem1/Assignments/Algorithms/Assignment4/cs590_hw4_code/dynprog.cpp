#include <cstring>
#include <iostream>
#include <limits.h>

#include "dynprog.h"

using namespace std;

int** bottomupSW(char* X, char* Y, int n, int m, int** H, int** P)
{
    int i, j;
    int p1, p2, p3;

    for(i=0; i<=n; i++)
    {
        H[i][0] = P[i][0] = 0;
    }
    for(j=0; j<=m; j++)
    {
        H[0][j] = P[0][j] = 0;
    }
    
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(X[i-1] == Y[j-1])
                p1 = H[i-1][j-1] + 2;
             else
                 p1 = H[i-1][j-1] -1;
            p2 = H[i][j-1] -1;
            p3 = H[i-1][j] -1;
            
           // H[i+1][j+1] = max(p1,p2,p3);

            if(p1>=p2 && p1>=p3)
				H[i][j]=p1;
			else if(p2>=p1 && p2>=p3)
				H[i][j]=p2;
			else if(p3>=p1 && p3>=p2)
				H[i][j]=p3;
            
            if(H[i][j] == p1)
                P[i][j] = '@';
                else
                {
                    if(H[i][j] == p2)
                        P[i][j] = '|';
                        else
                        {
                            P[i][j] = '#';
                        }  
                }
        }  
                
    }
    return H;
}

void printSeqAlignX(char* X, int** P, int n, int m)
{ 
    if(P[n][m] == '@')
    {
    cout << "1:" << X[n] << endl;
    printSeqAlignX(X,P,n-1,m-1);
    }
        else
        {
            if (P[n][m] == '#')
            {
                cout << "2:-" << endl;
                printSeqAlignX(X,P,n,m-1);
            }
                else
                {
                    cout << "3." << X[n] << endl;
                    //printSeqAlignX(X,P,n-1,m);
                }
        }
}

void printSeqAlignY(char* Y,int** P,int n,int m)
{
    if(P[n][m] == '@')
    {
    cout << "1:" << Y[n] << endl;
    printSeqAlignY(Y,P,n-1,m-1);
    }
        else
        {
            if (P[n][m] == '#')
            {
                cout << "2:-" << endl;
                printSeqAlignY(Y,P,n,m-1);
            }
                else
                {
                    cout << "3." << Y[n] << endl;
                    //printSeqAlignY(Y,P,n-1,m);
                }
        }
}

int topdownSW(char* X, char* Y, int m, int n, int** ops)
{
    cout <<"Hi" << endl;
    if (m == 0 || n == 0)
        return 0;

    if (ops[m][n] != INT_MIN)
        return ops[m][n];

    if (X[m-1] == Y[n-1]) {

        ops[m-1][n-1] = 2 + topdownSW(X, Y, m - 1, n - 1,ops);
        return ops[m-1][n-1];
    }
    else {
       int t = max((topdownSW(X, Y, m, n - 1,ops)-1),
                               (topdownSW(X, Y, m - 1, n,ops)-1));
       ops[m-1][n-1]=max(t,topdownSW(X, Y, m - 1, n - 1,ops)-1);
        return ops[m-1][n-1];
    }
}
void printTopDownX(char* X, char* Y, int** ops, int m, int n)
{
    if(m == 0 || n== 0)
    {
        cout << "hi";
        return;
    }
    if(X[m-1] == Y[n-1])
    {
        printTopDownX(X, Y, ops, m - 1, n - 1);
        cout << X[m-1];
    }
    else
    {
        if(ops[m][n - 1] > ops[m - 1][n])
        {
            printTopDownX(X, Y, ops, m, n - 1);
            cout << "-";
        }
        else
        {
            printTopDownX(X, Y, ops, m - 1, n);
            cout << X[m-1];
        }
    }
}

void printTopDownY(char* X, char* Y, int** ops, int m, int n)
{
    if(m == 0 || n == 0)
    {
        cout << "";
        return;
    }
    if(X[m-1] == Y[n-1])
    {
        printTopDownY(X, Y, ops, m - 1, n - 1);
        cout << Y[n-1];
    }
    else
    {
        if(ops[m][n - 1] > ops[m - 1][n])
        {
            printTopDownY(X, Y, ops, m, n - 1);
            cout << Y[n-1];
        }
        else
        {
            printTopDownY(X, Y, ops, m - 1, n);
            cout << "-";
        }
    }
}