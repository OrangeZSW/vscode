#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
// ջ
typedef struct
{
    int data[MAXSIZE];
    int top;
} Stack;

// ��ʼ��ջ
void Initstack(Stack *st)
{
    st->top = -1;
}
// ������������
bool Push(Stack *st, int data)
{
    if (st->top == MAXSIZE - 1)
        return false;
    st->data[++st->top] = data;
    return true;
}
// ɾ������
bool Pop(Stack *st, int *data)
{
    if (st->top == -1)
        return false;
    *data = st->data[st->top];
    st->top--;
    return true;
}
// �����������
void OutPut(Stack st)
{
    for (int i = 0; i <= st.top; i++)
    {
        printf("%c ", st.data[i]);
    }
    printf("\n");
}
// �ж�ջ�Ƿ�Ϊ��
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
        printf("�������׺���ʽ��");
        scanf("%s", ch);
        while (ch[length] != '\0')
        {
            length++;
        }
        hzjs(ch, length);
    }
    return 0;
}