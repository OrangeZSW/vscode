#include <iostream>
// q:下面这句话是什么意思？
// a:using namespace std; 代表使用标准命名空间
using namespace std;

namespace mySpace
{
    int a;
}
namespace myspace2 = mySpace;
int main()
{
    mySpace ::a = 100;
    cout << "helo word" << endl;
    cout << mySpace::a << endl;
    cout << myspace2::a << endl;
    return 0;
}