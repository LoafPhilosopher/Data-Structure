#include <iostream>
using namespace std;
int main()
{
    int xuan;
    int tian;
    int da;
    while (true)
    {
        cin >> xuan >> tian;
        cout << 100 - xuan * 5 - tian * 5 << endl;
    }
}