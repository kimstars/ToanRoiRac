#include <iostream>

using namespace std;

//in ra tam giac pascal

int main(){

    int n;
    int a[100][100];
    cout << "nhap n : ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[0][i];
    }
    cout << endl;
    int cot = n - 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < cot; j++){
            a[i][j] = a[i-1][j] + a[i-1][j+1];
        }
        cot--;
    }
    cot = n-1;
    for(int i = 0; i < n; i++){
        cout << "[";
        for(int j = 0; j < cot; j++){
            cout << a[i][j] << " ";
        }
        cout << a[i][cot] << "]" << endl;
        cot--;
    }




}