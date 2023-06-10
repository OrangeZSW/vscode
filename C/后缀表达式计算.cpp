#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
// 栈
typedef struct
{
    int data[MAXSIZE];
    int top;
} Stack;

// 初始化栈
void Initstack(Stack *st)
{
    st->top = -1;
}
// 顶部插入数据
bool Push(Stack *st, int data)
{
    if (st->top == MAXSIZE - 1)
        return false;
    st->data[++st->top] = data;
    return true;
}
// 删除数据
bool Pop(Stack *st, int *data)
{
    if (st->top == -1)
        return false;
    *data = st->data[st->top];
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
void hzjs(char ch[], int length)
{
    Stack st;
    Initstack(&st);
    for (int i = 0; i < length; i++)
    {
        if (ch[i] >= '0' && ch[i] <= '9')
        {
            Push(&st, ch[i] - '0');
        }
        else
        {
            int a, b;
            Pop(&st, &b);
            Pop(&st, &a);
            switch (ch[i])
            {
            case '+':
                Push(&st, a + b);
                break;
            case '-':
                Push(&st, a - b);
                break;
            case '*':
                Push(&st, a * b);
                break;
            case '/':
                Push(&st, a / b);
                break;
            }
        }
    }
    int result;
    Pop(&st, &result);
    printf("%d\n", result);
}
int main()
{
    while (1)
    {
        char ch[MAXSIZE];
        int length = 0;
        printf("请输入后缀表达式：");
        scanf("%s", ch);
        while (ch[length] != '\0')
        {
            length++;
        }
        hzjs(ch, length);
    }
    return 0;
}