#include <stdio.h>
#define MAXSIZE 10
// ջ
typedef struct
{
    char data[MAXSIZE];
    int top;
} Stack;

// ��ʼ��ջ
void Initstack(Stack *st)
{
    st->top = -1;
}
// ������������
bool Push(Stack *st, char data)
{
    if (st->top == MAXSIZE - 1)
        return false;
    st->data[++st->top] = data;
    return true;
}
// ɾ������
bool Pop(Stack *st, char *ch)
{
    if (st->top == -1)
        return false;
    *ch = st->data[st->top];
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
    printf("��������Ҫƥ�������(#����)��");
    while ((ch = getchar()) != '#')
    {
        str[i++] = ch;
    }
    if (khpp(str, i))
        printf("ƥ��ɹ�");
    else
        printf("ƥ��ʧ��");

    return 0;
}