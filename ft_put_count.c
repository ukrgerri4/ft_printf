#include "ft_printf.h"

void    ft_putchar_count(char c)
{
    write(1, &c, 1);
    g_count++;
}

void    ft_putstr_count(char *s)                                                                               
{
    if (s)
    {
        while (*s)
            ft_putchar_count((char)*(s++));
    }
}
