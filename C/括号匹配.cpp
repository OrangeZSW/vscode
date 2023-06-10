#include <stdio.h>
#define MAXSIZE 10
// 栈
typedef struct
{
    char data[MAXSIZE];
    int top;
} Stack;

// 初始化栈
void Initstack(Stack *st)
{
    st->top = -1;
}
// 顶部插入数据
bool Push(Stack *st, char data)
{
    if (st->top == MAXSIZE - 1)
        return false;
    st->data[++st->top] = data;
    return true;
}
// 删除数据
bool Pop(Stack *st, char *ch)
{
    if (st->top == -1)
        return false;
    *ch = st->data[st->top];
    st->top--;
    return true;
}
// 输出所有数据
void OutPut(Stack st)
{
    for (int i = 0; i <= st.top; i++)
    {
        printf("%c ", st.data[i]);
    }
    printf("\n");
}
// 判断栈是否为空
bool IsEmpy(Stack st)
{
    if (st.top == -1)
        return true;
    return false;
}
bool khpp(char ch[], int length)
{
    Stack st;
    Initstack(&st);
    for (int i = 0; i < length; i++)
    {
        if (ch[i] == '(' || ch[i] == '{' || ch[i] == '[')
        {
            Push(&st, ch[i]);
        }
        else
        {
            if (IsEmpy(st))
                return false;
            char topElem = ')';
            Pop(&st, &topElem);
            if (ch[i] == ')' && topElem != '(')
                return false;
            if (ch[i] == ']' && topElem != '[')
                return false;
            if (ch[i] == '}' && topElem != '{')
                return false;
        }
    }
    if (!IsEmpy(st))
        return false;
    return true;
}
int main()
{
    char ch;
    char str[MAXSIZE];
    int i = 0;
    Stack st;
    Initstack(&st);
    printf("请输入需要匹配的括号(#结束)：");
    while ((ch = getchar()) != '#')
    {
        str[i++] = ch;
    }
    if (khpp(str, i))
        printf("匹配成功");
    else
        printf("匹配失败");

    return 0;
}