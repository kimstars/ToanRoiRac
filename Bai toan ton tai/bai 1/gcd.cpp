#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(a == 0 || b == 0) return a + b;

    while(a*b != 0){
       if(a > b){
           a %= b;
       }else{
           b %= a;
       }
    }
    return a + b;
}
int gcd1(int a, int b){
    if(a == 0 || b == 0) return a +b;
    while(a != b){
        if(a > b){
            a -= b;
        }else{
            b -= a;
        }
    }
    return a;
}


int gcd2(int a, int b){
    int temp;
    while(b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}


int gcd3(int a, int b){
    if(b == 0) return a;
    return gcd3(b,a % b);
}


int main(){
    int a,b;
    cout << "Nhap a, b : " ;
    cin >> a >> b;
    cout << gcd(a,b) << endl;
    cout << gcd1(a,b)<< endl;
    cout << gcd2(a,b)<< endl;
    cout << gcd3(a,b)<< endl;


}