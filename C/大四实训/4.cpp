#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    // 异或法
    a ^= b;
    b ^= a;
    a ^= b;
    // 加减法
    // a = a + b;
    // b = a - b;
    // a = a - b;
}
int &retfunc(int a)
{
    // 静态变量
    static int b = a + 2;
    return b;
}
int main()
{
    int a = 100;
    int b = 80;
    swap(a, b);
    cout << a << " " << b << endl;
    int &ret_b = retfunc(30);
    retfunc(30) = 88;
    cout << ret_b << endl;

    return 0;
}