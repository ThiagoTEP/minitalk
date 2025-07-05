#include "minitalk.h"

void ft_putstr(char *str)
{
    if (!str)
        return;
    while (*str)
        write(1, str++, 1);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int n)
{
    if (n == -2147483648)
    {
        ft_putstr("-2147483648");
        return;
    }
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    ft_putchar((n % 10) + '0');
}
