#include <iostream>

using namespace std;

void init(int a[], int &n, int &k){
    cout <<"Nhap n : ";
    cin >> n;
    cout <<"Nhap k : ";
    cin >> k;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    
}

void sinh(int a[], int n, int k,int &ok){
    int i = k-1;
    while(a[i] == n - k +i && i >= 0) i--;
    if(i > 0){
        a[i]++;
        for (int  j = i+1; j < n; j++)
        {
            a[j] = a[i] + j-i;
        }
    }else{
        ok = 0;
    }

}
void xuat(int a[], int n){
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << endl;
    
}
int next(int a[], int n, int k,int ok){
    while(ok){
        xuat(a,n);
        sinh(a,n,k,ok);
    }
}

int main(){
    int a[100],n,k, ok;
    init(a,n,k);
    next(a,n,k,ok);



}