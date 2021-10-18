#include <iostream>

using namespace std;

int n;
int a[200], t[200];
void init()
{
    cout << "Nhap n : ";
    cin >> n;
    a[0] = 1;
    t[0] = 0;
}
void Print(int k)
{
    cout << n << " = ";
    for (int i = 1; i < k; i++)
    {
        cout << a[i] << " + ";
    }
    cout << a[k] << endl;
}

void Try(int i)
{
    for (int j = a[i - 1]; j <= ((n - t[i - 1]) / 2); j++)
    {
        a[i] = j;
        t[i] = t[i - 1] + j;
        Try(i + 1);
    }

    a[i] = n - t[i - 1];
    if(a[2] % 3 == 0 && i > 1){
        Print(i);
    }
}

int main()
{
    init();
    Try(1);
}