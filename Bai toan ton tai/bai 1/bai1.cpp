//C++11
#include <iostream>
#include <set>
#include <vector>
#include <random>
#include <ctime>

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

int main(){
    mt19937 generator(time(0));
    set<int> result;
    int n;
    cout << "Nhap n : ";
    cin >> n;
    uniform_int_distribution<int> dist{0, 2*n};
    cout << "Sinh n + 1 so nguyen duong ";
    while(result.size() != n + 1){
        result.insert(dist(generator));
    }
    for (set<int>::iterator i = result.begin(); i != result.end(); i++){
        cout <<*i<< " ";
    }
    vector<int> vec(result.begin(), result.end());
    
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }



}