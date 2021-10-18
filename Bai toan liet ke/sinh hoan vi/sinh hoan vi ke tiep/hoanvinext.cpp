#include <iostream>

 
using namespace std;
void init(int a[] , int &n){
    cout << "Nhap n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    
}

int sinh(int a[], int n, int &ok){
    int i = n -1 ;
    while(i > 0 && a[i] > a[i+1]) i--;
    if(i > 0){
        int k = n;
        while(a[i] > a[k]) k--;
        swap(a[i],a[k]);
        int r = i +1;
        int s = n;
        while(r <= s){
            swap(a[r],a[s]);
            r++;
            s--;
        }
    }else{
        ok = 0;
    }
}
void xuat(int a[], int n){
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
        /* code */
    }
    cout << endl;
    
}


void next(int a[],int n, int ok){
    while(ok){
        xuat(a,n);
        sinh(a,n,ok);
    }
}


int main(){
    
    int a[100],n,ok =1;

    init(a,n);
    next(a,n, ok);
}