#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int demcanh(string namein){
    ifstream f;
    f.open(namein, ios::in);
    int n = 0;
    f >> n;
    string s;
    int count = 0;
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
                    count++;
                    // out << i<< " " << j+1 << endl; // vì chỉ số trong string s bắt đầu từ 0
                    // cout << "("<<i<<","<<j+1<<")"<<endl;
                }
            }
        }
    }
    cout << count/2;
    return count/2;
}




int main()
{
    int n = demcanh("input.txt");
}

