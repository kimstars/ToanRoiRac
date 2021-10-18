#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void readdskevohuong(string namein,string nameout)
{
    ifstream f;
    f.open(namein, ios::in);
    int n = 0 ;
    f >> n;
    string s = "";
    int ke[100][100];
    
    memset(ke,0,sizeof(ke));

    for (int i = 0; i <= n; i++)
    {
        fflush(stdin);
        getline(f, s);
        // cout << s <<"----->";
        int j = 0, so = 0;
        while (j <= s.length())
        {
            // cout << so <<endl;
            if (s[j] >= '0' && s[j] <= '9')
            {
                so = 10 * so + (int)(s[j] - '0');
            }
            else if (so > 0)
            {
                ke[i][so] = 1;
                ke[so][i] = 1;
                so = 0;
            }
            j++;
        }
    }
    
    for (int i = 0; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    ofstream out;
    out.open(nameout,ios::out);
    out << n <<endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
        for (int j = 1; j <= n; j++)
        {
            cout << ke[i][j] << " ";
            out << ke[i][j] << " ";
        }
        out << endl;
        cout << endl;
    }
    out.close();
    f.close();
}

void readdskecohuong(string namein,string nameout)
{
    ifstream f;
    f.open(namein, ios::in);
    int n;
    f >> n;
    string s;
    int ke[100][100];
    
    memset(ke,0,sizeof(ke));
    for (int i = 0; i <= n; i++)
    {
        fflush(stdin);
        getline(f, s);
        int j = 0, so = 0;
        while (j <= s.length())
        {
            if (s[j] >= '0' && s[j] <= '9')
            {
                so = 10 * so + (int)(s[j] - '0');
            }
            else if (so > 0)
            {
                ke[i][so] = 1;
                so = 0;
            }
            j++;
        }
    }
    
    for (int i = 0; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    ofstream out;
    out.open(nameout,ios::out);
    out << n << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
        for (int j = 1; j <= n; j++)
        {
            cout << ke[i][j] << " ";
            out << ke[i][j] << " ";
        }
        out << endl;
        cout << endl;
    }
    out.close();
    f.close();
}

int main()
{
    readdskevohuong("dske1.txt","input1.txt");
    cout << endl;
    readdskecohuong("dske2.txt","input2.txt");
    cout << endl;
    
}