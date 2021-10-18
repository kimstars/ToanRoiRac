#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int v, e, a ,b;//v đỉnh, e cạnh
    //DS cạnh : Một cạnh được biểu diễn bằng hai đỉnh
    //DS kề: Một đỉnh kề với n đỉnh qua n cạnh :3
    cin >> v >> e;
    
    vector<int> ke[v+5];
    for(int i = 0; i < e; i++){
        cin >> a >> b;
        ke[a].push_back(b);
        ke[b].push_back(a);
    }
    for(int i = 0; i < v; i++){
        sort(ke[i].begin(),ke[i].end());
    }
    cout << "----------------------\n";
    for(int i = 1; i <= v ;i++){
        cout << i << " : ";
        for(int j = 0; j < ke[i].size(); j++){
            cout << " " << ke[i][j];
        }
        cout << endl;
    }
    cout << "----------------------\n";


   


}

// Test
// 6 7
// 1 2
// 1 3
// 2 4
// 2 5
// 3 5
// 3 6
// 4 6


// output
// ----------------------
// 1 :  2 3
// 2 :  1 4 5
// 3 :  1 5 6
// 4 :  2 6
// 5 :  2 3
// 6 :  3 4
// ----------------------

