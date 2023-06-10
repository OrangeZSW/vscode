#include <stdio.h>
#define N 100
int position(int a[], int lower, int high);
void quk_sort(int a[], int lower, int high)
{

    if (lower < high)
    {
        int p = position(a, lower, high);
        quk_sort(a, lower, p - 1);
        quk_sort(a, p + 1, high);
    }
}

int position(int a[], int lower, int high)
{
    int temp = a[lower];
    while (high > lower)
    {
        while (a[high] > temp && high > lower)
            high--;
        a[lower] = a[high];
        while (a[lower] < temp && high > lower)
            lower++;
        a[high] = a[lower];
    }
    a[lower] = temp;
    return lower;
}

int main()
{
    int a[N];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d ", &a[i]);

    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    quk_sort(a, 0, n - 1);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
