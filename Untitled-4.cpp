#include <iostream>
using namespace std;

void swap(int& x, int& y)
{
    int t = x;
    x = y;
    y = t;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << "Before swap: x=" << x << ", y=" << y << endl;
    swap(x, y);
    cout << "After  swap: x=" << x << ", y=" << y << endl;
    return 0;
}