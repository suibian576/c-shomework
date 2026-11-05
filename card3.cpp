#include "card_operations.h"
#include <stdexcept>
#include <iostream>

using namespace std;

int main()
{
    try
    {
        card::title("校园一卡通消费管理系统");

        int stuNum;
        cout << "请输入学生账户数量：";
        cin >> stuNum;

        Card* cardArr = createCards(stuNum);

        inputCards(cardArr, stuNum);

        cout << "\n===== 对第一个账户充值100元 =====" << endl;
        deposit(cardArr[0], 100.0);

        cout << "\n===== 消费：食堂午餐 8.5元 =====" << endl;
        spend(cardArr[0], 8.5, "食堂午餐");

        cout << "\n===== 查询第一个账户信息 =====" << endl;
        showBalance(cardArr[0]);
        viewStudentID(&cardArr[0]);

        int cent = toCent(cardArr[0].balance);
        cout << "当前余额换算成分：" << cent << " 分" << endl;

        cout << "\n===== 全部账户报表 =====" << endl;
        printReport(cardArr, stuNum);

        destroyCards(cardArr);
        cout << "\n内存释放完成，系统退出。" << endl;
    }
    catch (const bad_alloc &e)
    {
        cerr << "异常：内存分配失败！" << e.what() << endl;
    }
    catch (const runtime_error &e)
    {
        cerr << "运行异常：" << e.what() << endl;
    }
    catch (...)
    {
        cerr << "未知异常！" << endl;
    }

    system("pause");
    return 0;
}
