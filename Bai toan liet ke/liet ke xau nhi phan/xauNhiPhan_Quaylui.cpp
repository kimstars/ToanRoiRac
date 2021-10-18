#include <iostream>
#include <math.h>

using namespace std;

int n;

int b[20];

void Result(){
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " " ;
    }
    cout << endl;
     
}

void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
            b[i] = j;
        if (i == n-1)
            Result();
        else
            Try(i + 1);
    }
}



int main(){
    cin >> n;
    Try(0);
   

}