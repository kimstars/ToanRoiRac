#include <iostream>
#include <math.h>

using namespace std;

int n;

int b[20];
int count = 0;

void Result(){
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " " ;
    }
        ++count;
    cout << endl;
     
}

void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        if(b[i-1]){
            b[i] = j;
        }else{
            b[i] = 1;
        }
        if (i == n)
            Result();
        else
            Try(i + 1);
    }
}



int main(){
    cin >> n;
    b[1] = 1;
    Try(1);
    Try(0);
    cout << "So hoan vi :"  << count ;

}