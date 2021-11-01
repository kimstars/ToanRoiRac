// 1. In ra thứ tự các đỉnh được duyệt theo dfs
#include <iostream>
#include <bits/stdc++.h>
#define max 100



using namespace std;
int chuaXet[max];
int a[100][100], n;

void Doc_File(int a[max][max], int &n)
{
    FILE *f = fopen("input.txt", "r");
    fscanf(f, "%d", &n);
    cout << "\n So dinh: " << n << "\nMa tran ke: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d", &a[i][j]);
            if(a[i][j] != 0){
                a[i][j] = 1;
            }
            // cout << a[i][j] << " ";
        }
        // cout << endl;
    }
    fclose(f);
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

void PrintArray(int a[][100],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}




int main(){
    // memset(a,0,sizeof(int));
    memset(chuaXet,1,sizeof(int));
    Doc_File(a,n);
    PrintArray(a,n);

    cout << "\n Duyet do thi DFS: ";

        DFS(0);
        /* code */
    // }
    
}