#include <iostream>
#include <bits/stdc++.h>
#define max 100

#define FileIn "input1.txt"

using namespace std;
int chuaXet[max];

// a: ma tran ke cua G, n: so dinh
int a[max][max], n;

// doc file chua do thi G luu vao ma tran a

void Doc_File(int a[max][max], int &n)
{
    FILE *f = fopen(FileIn, "rb");
    
    fscanf(f, "%d", &n);
    cout << "\n So dinh: " << n << "\n Ma tran ke: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d", &a[i][j]);
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    fclose(f);
}

// Khoi tao chua xet
void KhoiTao_ChuaXet()
{
    for (int i = 0; i < max; i++)
        chuaXet[i] = 1;
}

// thuat toan DFS
void DFS(int u)
{
    // xet dinh u
    chuaXet[u] = 0;
    cout << u << "->";
    for (int v = 0; v < n; v++)
        if (chuaXet[v] == 1 && a[u][v] == 1)
        {
            DFS(v);
        }
}

// thuat toan BFS

void BFS(int u)
{
    int queue[max], dau = 0, cuoi = 0;
    for (int i = 0; i < max; i++)
        queue[i] = 0;
    queue[cuoi] = u;
    chuaXet[u] = 0;
    cout << u << "->";

    while (dau >= cuoi)
    {
        int p = queue[cuoi];
        cuoi++;
        for (int v = 0; v < n; v++)
            if (chuaXet[v] == 1 && a[p][v] == 1)
            {
                dau++;
                queue[dau] = v;
                chuaXet[v] = 0;
                cout << v << "->";
            }
        // cout << "("<<dau <<", "<< cuoi <<")\n";
    }
}

// Kiem tra chuaXet
int KT_ChuaXet()
{
    for (int i = 0; i < n; i++)
        if (chuaXet[i] == 1)
            return i;
    return -1;
}

// Dem so thanh phan lien thong

int DemSLT()
{
    int slt = 0;
    KhoiTao_ChuaXet();
    while (KT_ChuaXet() != -1)
    {
        int i = KT_ChuaXet();
        DFS(i);
        cout << "\ni="<<i<<endl;
        slt++;
    }
    cout << "\nSo lien thong: " << slt;
    return slt;
}

// tim bac cac dinh
int Deg(int i)
{
    int deg = 0;
    for (int j = 0; j < n; j++)
    {
        deg += a[i][j];
    }
    return deg;
}


// Kiem tra do thi Euler

void Test_Euler()
{
    if (DemSLT() == 1)
    {
        // tim bac cua do thi
        int soDinhLe = 0;
        for (int i = 0; i < n; i++)
            if (Deg(i) % 2 != 0)
                soDinhLe++;
        if (soDinhLe == 0)
            cout << "\n Do thi la Euler";
        else if (soDinhLe == 2)
            cout << "\n Do thi la nua Euler";
        else
            cout << "\n Do thi khong phai Euler";
    }
    else
        cout << "\n Do thi khong la Euler";
}

int demcanh(string namein=FileIn){
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

int cnt = 0;
void Try(int u)
{
	chuaXet[u] = 1;
	cnt++;
	for (int i = 1; i <= a[u][0]; i++)
	{
		int v = a[u][i];
		if(!chuaXet[v]) Try(v);
	}
}


bool checkTree(int a[][100],int n){
    int canh = demcanh();
    if(canh == 0) return 0;
    else{
        KhoiTao_ChuaXet();
        if(canh == n-1){
            Try(1);
            if(cnt == n) return 1;
            else return 0;
        }else return 0;
    }
}

// ham chinh

int main()
{
    // doc ma tran
    Doc_File(a, n);
    // Duyet do thi DFS
    KhoiTao_ChuaXet();
    cout << "\n Duyet do thi DFS: ";
    DFS(0);
    // Duyet do thi BFS
    KhoiTao_ChuaXet();
    cout << "\n Duyet do thi BFS: ";
    BFS(0);


    //Kiem tra cay
    bool check = checkTree(a,n);
    if(check) cout << "\nDo thi la cay!!\n";
    else cout << "\nDo thi khong la cay\n";

    // Dem so lien thong
    cout << "\nDem so lien thong \n";
    DemSLT();

    // // Kiem tra Euler
    // Test_Euler();
    return 0;
}