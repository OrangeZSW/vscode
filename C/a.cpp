#include <stdio.h>
int maxProfit(int *prices, int pricesSize)
{
    int porfit = 0;
    int p, q;
    p = 0, q = pricesSize - 1;
    while (q > p)
    {
        bool max = true;
        bool min = true;
        for (int j = p; j < q; j++)
        {
            if (prices[p] > prices[j])
            {
                p++;
                max = false;
                break;
            }
            if (prices[q] < prices[j])
            {
                q--;
                min = false;
                break;
            }
        }
        if (max && min)
            break;
    }
    if (q > p)
        return prices[q] - prices[p];
    else
        return 0;
}
int main()
{
    int a[6] = {7, 1, 5, 3, 6, 4};
    int b = maxProfit(a, 6);
    printf("%d", b);
}