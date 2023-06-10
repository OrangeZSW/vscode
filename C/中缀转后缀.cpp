#include <stdio.h>

// ��׺���ʽת��׺���ʽ
// 1.������������ֱ�����
// 2.���������ţ���ջ
void mid2post(char *mid, char *post)
{
    int i = 0, j = 0;
    char stack[100];
    int top = -1;
    while (mid[i] != '\0')
    {
        if (mid[i] >= '0' && mid[i] <= '9')
        {
            post[j++] = mid[i];
        }
        else if (mid[i] == '(')
        {
            stack[++top] = mid[i];
        }
        else if (mid[i] == ')')
        {
            while (stack[top] != '(')
            {
                post[j++] = stack[top--];
            }
            top--;
        }
        else
        {
            while (top != -1 && stack[top] != '(')
            {
                post[j++] = stack[top--];
            }
            stack[++top] = mid[i];
        }
        i++;
    }
    while (top != -1)
    {
        post[j++] = stack[top--];
    }
    post[j] = '\0';
}

int main()
{
    char mid[100], post[100];
    scanf("%s", mid);
    mid2post(mid, post);
    printf("%s", post);
    return 0;
}