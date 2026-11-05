# c-shomework

C++ 入门练习合集（4 个独立小程序），覆盖**结构体、C 风格字符串与指针、内联函数 / 默认参数 / 函数重载、引用传参**。

## 文件一览

| 文件 | 主题 | 说明 |
| --- | --- | --- |
| `Untitled-1.cpp` | 结构体 + 格式化输出 | 读入 n 个学生的姓名、语文、数学、英语成绩，对齐输出三科成绩与平均分；平均分 ≥ 90 的行末追加 `Excellent` |
| `Untitled-2.cpp` | 字符指针遍历 | `countVowels(const char*)` 用指针逐字符扫描，统计元音字母（a e i o u，大小写都算）个数 |
| `Untitled-3.cpp` | 内联函数 / 默认参数 / 重载 | `square()` 求平方；`power()` 幂运算（指数默认 3）；`calc()` 四则运算（含除零保护）；`calc()` 同时有 `double` 与 `int` 两个重载版本 |
| `Untitled-4.cpp` | 引用传参 | `swap(int&, int&)` 交换两个整数，打印交换前后结果 |

## 编译与运行

```bash
g++ -std=c++11 -O2 Untitled-1.cpp -o u1 && ./u1
```

> ⚠️ **注意：源文件的缩进是 U+00A0（不间断空格）**
> 在 VSCode 里看起来和普通空格一样，但 `g++` 会报 `error: stray '\302' in program`。
> 编译前先把它转成普通空格（不改变代码语义）：
>
> ```bash
> sed -i 's/\xc2\xa0/ /g' Untitled-*.cpp
> ```

## 运行示例

### Untitled-1.cpp —— 学生成绩表

输入：

```text
3
Zhang 90 80 70
Li 95 96 97
Wang 60 70 80
```

输出（姓名后补齐到 8 列，成绩保留两位小数）：

```text
Zhang   90.00   80.00   70.00   80.00
Li      95.00   96.00   97.00   96.00    Excellent
Wang    60.00   70.00   80.00   70.00
```

### Untitled-2.cpp —— 统计元音

输入 `Hello World` → 输出 `Number of vowels: 3`

### Untitled-3.cpp —— 函数练习

输入 `5 3 +`：

```text
square(5) = 25.00
power(5,3) = 125.00
5 + 3 = 8.00
```

除零输入 `5 0 /` 时，第三行改为 `Error: divide by zero`。

### Untitled-4.cpp —— 引用交换

输入 `10 20`：

```text
Before swap: x=10, y=20
After  swap: x=20, y=10
```