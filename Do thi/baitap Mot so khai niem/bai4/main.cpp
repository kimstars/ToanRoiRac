// Viết c/trình C đọc dữ liệu từ file input1_2.txt sau đó đưa ra: Ma trận kề biểu diễn đồ thị; D/s kề của đồ thị; Bậc của từng đỉnh. (KQ lưu trong file output1_2.txt)

#include <bits/stdc++.h>
using namespace std;

void dsCanh_mtranKe(string namein, string nameout)
{
    string s;
    int ke[100][100];
    memset(ke, 0, sizeof(ke));
    ifstream f;
    f.open(namein, ios::in);

    while (getline(f, s))
    {
        ke[s[0] - '0'][s[2] - '0'] = 1;
    }
    int n = s[0] - '0';
    cout << n << endl;
    ofstream out;
    out.open(nameout, ios::out);
    out << n << endl;

    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
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
    dsCanh_mtranKe("../bai2/input1_2.txt", "output1_2.txt");
}