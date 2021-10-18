#include <iostream>
#include <math.h>

using namespace std;

int n;
int b[100];

int Next_Bit_String()
{
    int i = n - 1;
    while (b[i] == 1 && i >= 0)
    {
        b[i] = 0;
        i = i - 1;
    }
    if (i < 0)
        return 1;
    else
        b[i] = 1;
    return 0;
}

int main()
{
    cin >> n;
    for(int i = 0 ;i < n; i++){
        cout << Next_Bit_String();
    }
}