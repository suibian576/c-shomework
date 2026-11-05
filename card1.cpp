#ifndef CARD_OPERATIONS_H
#define CARD_OPERATIONS_H

#include <iostream>
#include <string>
#include <iomanip>

// 系统常量
const double FEE_RATE = 0.02;
const double WARNING_BALANCE = 10.0;

// 一卡通结构体
struct Card
{
    int id;
    std::string name;
    double balance;
    int transactions;
};

namespace card
{
    void printLine(char c = '-', int len = 60);
    void title(const std::string &s);
}

// 账户动态内存
Card* createCards(int n);
void destroyCards(Card *p);
void inputCards(Card *arr, int n);

// 充值、消费（函数重载）
void deposit(Card &c, double amount, double fee = FEE_RATE);
bool spend(Card &c, double cost);
bool spend(Card &c, double cost, const std::string &item);

// 常引用 / const指针 查询
void showBalance(const Card &c);
void viewStudentID(const Card *p);

// 元转分 static_cast
int toCent(double amount);

// 报表打印
void printReport(const Card *arr, int n);

#endif