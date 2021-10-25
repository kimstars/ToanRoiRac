// Viết c/trình C đọc dữ liệu từ file input1_1.txt(ds kề) sau đó đưa ra: Ma trận kề biểu diễn đồ thị; D/s cạnh  của đồ thị; Bậc của từng đỉnh.(KQ lưu trong file output1_1.txt): 

#include <bits/stdc++.h>
using namespace std;

void dsKe_matranKeVohuong(string namein, string nameout)
{
    ifstream f;
    f.open(namein, ios::in);
    int n = 0;
    f >> n;
    string s = "";
    int ke[100][100];

    memset(ke, 0, sizeof(ke));

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
    out.open(nameout, ios::out);
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

void mtKe_DScanh(string namein, string nameout)
{
    ifstream f;
    f.open(namein, ios::in);
    fflush(stdin);
    int n = 0;
    int ke[100][100];
    memset(ke, 0, sizeof(ke));
    f >> n;
    string s;
    ofstream out;
    out.open(nameout, ios::app);
    out <<endl;

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
                    ke[i][j] = 1;
                    // out << i<< " " << j << endl;
                    cout << "(" << i << "," << j << ")" << endl;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ke[i][j] = 1)
            {
                out << i << " " << j << endl;
            }
        }
    }
    out.close();
    f.close();
}

void demBac(string namein, string nameout)
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
            for (int j = 0; j < n; j++)
            {
                if (s[2 * j] == '1')
                {
                    ke[i].push_back(j + 1);
                }
            }
        }
    }

    ofstream out;
    out.open(nameout, ios::app);
    out <<endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        cout << ke[i].size();
        cout << endl;

        out << i << ": ";
        out << ke[i].size();
        out << endl;
    }
}

int main()
{
    dsKe_matranKeVohuong("../bai2/input1_1.txt", "output1_1.txt");
    mtKe_DScanh("output1_1.txt", "output1_1.txt");
    demBac("output1_1.txt", "output1_1.txt");

}