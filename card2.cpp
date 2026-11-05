#include "card_operations.h"
#include <stdexcept>

using namespace std;

namespace card
{
    void printLine(char c, int len)
    {
        for (int i = 0; i < len; i++)
        {
            cout << c;
        }
        cout << endl;
    }

    void title(const string &s)
    {
        printLine('=');
        cout << "          " << s << endl;
        printLine('=');
    }
}

Card* createCards(int n)
{
    if (n <= 0)
    {
        throw runtime_error("学生数量不能小于等于0！");
    }
    Card* p = new(nothrow) Card[n];
    if (p == nullptr)
    {
        throw bad_alloc();
    }
    return p;
}

void destroyCards(Card *p)
{
    delete[] p;
}

void inputCards(Card *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "请输入第" << i+1 << "个学生【学号 姓名 初始余额】：";
        cin >> arr[i].id >> arr[i].name >> arr[i].balance;

        if (!cin)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            throw runtime_error("输入数据非法！");
        }
        if (arr[i].balance < 0)
        {
            throw runtime_error("初始余额不能为负数！");
        }
        arr[i].transactions = 0;
    }
}

void deposit(Card &c, double amount, double fee)
{
    if (amount <= 0)
    {
        throw runtime_error("充值金额必须大于0！");
    }
    double realAdd = amount * (1 - fee);
    c.balance += realAdd;
    c.transactions++;
}

bool spend(Card &c, double cost)
{
    if (cost < 0)
    {
        throw runtime_error("消费金额不能为负数！");
    }
    if (c.balance < cost)
    {
        throw runtime_error("余额不足，消费失败！");
    }
    c.balance -= cost;
    c.transactions++;
    return true;
}

bool spend(Card &c, double cost, const string &item)
{
    cout << "消费项目：" << item << endl;
    return spend(c, cost);
}

void showBalance(const Card &c)
{
    cout << "账户余额：" << fixed << setprecision(2) << c.balance << " 元" << endl;
}

void viewStudentID(const Card *p)
{
    cout << "学生学号：" << p->id << endl;
}

int toCent(double amount)
{
    // 元转分，static_cast强制转换
    int cent = static_cast<int>(amount * 100);
    return cent;
}

void printReport(const Card *arr, int n)
{
    card::printLine();
    cout << left
         << setw(10) << "ID"
         << setw(15) << "Name"
         << setw(12) << "Balance(元)"
         << setw(12) << "Transactions"
         << endl;
    card::printLine();

    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++)
    {
        cout << left
             << setw(10) << arr[i].id
             << setw(15) << arr[i].name
             << setw(12) << arr[i].balance
             << setw(12) << arr[i].transactions
             << endl;
    }
    card::printLine();
}
