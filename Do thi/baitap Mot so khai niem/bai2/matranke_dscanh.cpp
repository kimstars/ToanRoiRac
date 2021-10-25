#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream f;
    f.open("../bai1/input1.txt", ios::in);
    fflush(stdin);
    int n = 0;
    vector<int> ke[100];
    f >> n;
    string s;
    ofstream out;
    out.open("input1_2.txt",ios::out);

    for (int i = 0; i <= n; i++)
    {
        fflush(stdin);
        getline(f, s);
        if (s.length() > 2)
        {
            for (int j = 0; j < n; j++)
            {
                if (s[2 * j] == '1')
                {
                    out << i<< " " << j+1 << endl;
                    cout << "("<<i<<","<<j+1<<")"<<endl;
                }
            }
        }
    }
}