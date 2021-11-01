#include <iostream>
#include <bits/stdc++.h>
#define max 100

#define FileIn "input1.txt"

using namespace std;
int chuaXet[max];

// A: ma tran ke cua G, n: so dinh
int A[max][max], n;

// doc file chua do thi G luu vao ma tran A

void Doc_File(int A[max][max], int &n)
{
    FILE *f = fopen(FileIn, "rb");
    fscanf(f, "%d", &n);
    cout << "\n So dinh: " << n << "\n Ma tran ke: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d", &A[i][j]);
            cout << A[i][j] << " ";
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
            if (chuaXet[v] == 1 && A[p][v] == 1)
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

int main(){
    Doc_File(A, n);
    // Duyet do thi DFS
    KhoiTao_ChuaXet();
    // Duyet do thi BFS
    cout << "\n Duyet do thi BFS: ";
    BFS(0);
}