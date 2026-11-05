#include <iostream>
#include <iomanip>
using namespace std;

inline double square(double x)
{
    return x * x;
}

double power(double base, int exponent = 2)
{
    double res = 1.0;
    for (int i = 0; i < exponent; ++i)
    {
        res *= base;
    }
    return res;
}

double calc(double a, double b, char op)
{
    double ans;
    switch(op)
    {
        case '+': ans = a + b; break;
        case '-': ans = a - b; break;
        case '*': ans = a * b; break;
        case '/':
            if (b == 0)
            {
                cout << "Error: divide by zero" << endl;
                return 0;
            }
            ans = a / b;
            break;
        default: ans = 0;
    }
    return ans;
}

double calc(int a, int b, char op)
{
    return calc((double)a, (double)b, op);
}

int main()
{
    int a, b;
    char op;
    cin >> a >> b >> op;

    cout << fixed << setprecision(2);
    cout << "square(" << a << ") = " << square(a) << endl;
    cout << "power(" << a << ",3) = " << power(a,3) << endl;

    if (op == '/' && b == 0)
    {
        cout << "Error: divide by zero" << endl;
    }
    else
    {
        double ret = calc(a,b,op);
        cout << a << " " << op << " " << b << " = " << ret << endl;
    }
    return 0;
}