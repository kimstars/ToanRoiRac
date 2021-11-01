#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void matranke_dske(string namein,string nameout)
{
    ifstream f;
    f.open(namein, ios::in);
    fflush(stdin);
    int n = 0;
    vector<int> ke[100];
    f >> n;
    string s;
    for (int i = 0; i <= n; i++)
    {
        fflush(stdin);
        getline(f, s);
        if (s.length() > 2)
        {
            // cout << s << " => ";
            for (int j = 0; j < n; j++)
            {
                if (s[2 * j] == '1')
                {
                    // cout <<j<<" ";
                    ke[i].push_back(j + 1);
                }
            }
            // cout <<endl;
        }
    }

    ofstream out;
    out.open(nameout, ios::out);
    out << n << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < ke[i].size(); j++)
        {
            out << ke[i][j] << " ";
            cout << ke[i][j] << " ";
        }
        out << endl;
        cout << endl;
    }
}



int main()
{
    matranke_dske("G.txt","dscanh.txt");
    
}