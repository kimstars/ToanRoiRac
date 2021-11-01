#include <iostream>

using namespace std;
#define max 100
int chuaXet[max];
int a[max][max], n;


void Doc_File(int a[max][max], int &n)
{
    FILE *f = fopen("input.txt", "rb");
    
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



int KT_ChuaXet()
{
    for (int i = 0; i < n; i++)
        if (chuaXet[i] == 1)
            return i;
    return -1;
}

void KhoiTao_ChuaXet()
{
    for (int i = 0; i < max; i++)
        chuaXet[i] = 1;
}

void DFS(int u)
{
    // xet dinh u
    chuaXet[u] = 0;
    // cout << u << "->";
    for (int v = 0; v < n; v++)
        if (chuaXet[v] == 1 && a[u][v] == 1)
        {
            DFS(v);
        }
}
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

int Deg(int i)
{
    int deg = 0;
    for (int j = 0; j < n; j++)
    {
        deg += a[i][j];
    }
    return deg;
}

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

int main(){
    Doc_File(a,n);
    KhoiTao_ChuaXet();
    Test_Euler();
}