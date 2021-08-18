#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100][100];
vector<string> res;
bool check = false;


// 5
// 1 0 0 0 0 
// 1 1 1 1 1
// 1 0 1 0 1 
// 1 1 1 0 1
// 0 0 1 1 1

// res:
// DDDRRDRR
// DRRDDDRR
// DRRRRDDD


void init(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for (int j = 0 ; j < n; j++){
            cin >> a[i][j];
        }
    }
    res.clear();
    check = false;
}

void Try(int i, int j, string s){
    if(i == 0 && j == 0 && a[i][j] == 0){
        check = false;
        return;
    }

    if(i == n-1 && j == n-1 && a[n-1][n-1]){
        res.push_back(s);
        check = true;
        return;
    }

    if(i < n - 1 && a[i+1][j]){
        Try(i+1,j, s + "D");
    }
    if(j < n - 1 && a[i][j+1]){
        Try(i,j + 1, s + "R");
    }

    if((i < n - 1 && j < n - 1 && !(a[i+1][j] && a[i][j + 1]))  || (i > n - 1 || j > n - 1)){
        return;
    }
}


int main(){
    
    init();

    Try(0,0,"");


    if(!check){
        cout << "-1";
    }else{
        sort(res.begin(), res.end());
        for(int i = 0 ; i < res.size(); i++){
            cout << res[i] << endl;
        }
    }

}