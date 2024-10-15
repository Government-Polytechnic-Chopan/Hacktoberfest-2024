#include <stdio.h>
int fib(int n);
int main()

{
    printf("im fibo'' ,can tell you nth term of fibonacci sequences ,\n try it by entering any term:\n ");
    int n;

    scanf("%d", &n);
    printf("%d", fib(n));
    return 0;
}
int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int fnm1 = fib(n - 1);
    int fnm2 = fib(n - 2);
    int fibn = fnm1 + fnm2;
    return fibn;
}
