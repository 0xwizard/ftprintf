
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int calc(char c, int n, ...)
{
    int res; 
    va_list ap; 
    va_start(ap, n); 

    res = 0;
    if (c == '-')
    {
        res = va_arg(ap, int);
        while (n)
        {
            res -= va_arg(ap, int);
            n--;
        }
    }
    else if (c == '+')
    {
        while (n)
        {
            res += va_arg(ap, int);
            n--;
        }

    }
    else if (c == '*')
    {
        res = va_arg(ap, int);
        n -= 1;
        while (n)
            res *= va_arg(ap, int);
            n--;

    }
    else if (c == '/')
    {
        res = va_arg(ap, int);
        n -= 1;
        while (n)
            res /= va_arg(ap, int);
            n--;

    }
    else
        return (0);
 va_end(ap);
 return (res);
}

int main(void)
{
    printf("Sum >> %d\n", calc('+', 2, 2, 2));
    printf("Minus >> %d", calc('-', 2, 4, 2));
    printf("Multiplication >> %d", calc('*', 2, 6, 6));
    printf("Division >> %d", calc('/', 2, 8, 2));
}