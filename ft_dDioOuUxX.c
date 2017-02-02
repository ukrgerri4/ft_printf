#include "ft_printf.h"

static void ft_check_prefix(t_plist *rules, char **s, char c, int *i)
{
    if (*s[0] == '-')
    {
        rules->prefix[0] = '-';
        *i = 1;
        *s++;
    }
    else if ((c == 'o' || c == 'O') && (rules->flags & 8))
    {
        rules->prefix[0] = '0';
        *i = 1;
    }
    else if ((c == 'x' || c == 'X') && (rules->flags & 8))
    {
        rules->prefix[0] = '0';
        rules->prefix[1] = (c == 'x') ? 'x' : 'X';
        *i = 2;
    }
    else if ((rules->flags & 4) && !(UNSIGNED_SPE))
    {
        rules->prefix[0] = ' ';
        *i = 1;
    }
    else
        rules->prefix[0] = '+';
}

static void ft_prefix_on(t_plist *rules, char *s, char c, int i)
{
    int j;

    if (i)
        ft_putstr_count(rules->prefix);
    if ((j = rules->precision - rules->len) > 0)
        while (j--)
            ft_putchar_count('0');
    (c == 'x') ? ft_putstr_count(ft_tolower_str(s)) : ft_putstr_count(s);
    rules->len = (rules->precision >= ft_strlen(s)) ? rules->precision : rules->len;
    if ((j = rules->width - (i + rules->len)) > 0)
        while (j--)
            ft_putchar_count(' ');
}

static void ft_prefix_off(t_plist *rules, char *s, char c, int i)
{
    int j;

    if (rules->precision)
    {
        rules->precision = (rules->precision >= rules->len) ? rules->precision : rules->len;
        if ((j = rules->width - (i + rules->precision)) > 0)
            while (j--)
                ft_putchar_count(' ');
        if (i)
            ft_putstr_count(rules->prefix);
        while ((rules->len)++ != rules->precision)
            ft_putchar_count('0');
    }
    else
    {
        if (i && rules->prep == '0')
            ft_putstr_count(rules->prefix);
        if ((j = rules->width - (i + rules->len)) > 0)
            while (j--)
                ft_putchar_count(rules->prep);
        if (i && rules->prep == ' ')
            ft_putstr_count(rules->prefix);
    }
    (c == 'x') ? ft_putstr_count(ft_tolower_str(s)) : ft_putstr_count(s);
}

static void ft_print_dDioOuUxX(t_plist *rules, char *s, char c)
{
    int     i;
    int     j;

    rules->prep = (rules->flags & 16) ? '0' : ' ';
    i = 0;
    ft_check_prefix(rules, &s, c, &i);
    i = ((rules->flags & 1) && !(UNSIGNED_SPE)) ? 1 : i;
    rules->len = ft_strlen(s);
    if (rules->flags & 2)
        ft_prefix_on(rules, s, c, i);
    else
        ft_prefix_off(rules, s, c, i);
}

void    ft_use_rules_dDioOuUxX(t_plist *rules, char c, va_list ap)
{
	if (c == 'd' || c == 'i' || c == 'D') // ask about 'D'
        ft_print_dDioOuUxX(rules, ft_itoa_base_s(ft_signT(rules, ap), 10), c);
    else if (c == 'o' || c == 'O')
        ft_print_dDioOuUxX(rules, ft_itoa_base_us(ft_unsignT(rules, ap), 8), c);
    else if (c == 'u' || c == 'U')
        ft_print_dDioOuUxX(rules, ft_itoa_base_us(ft_unsignT(rules, ap), 10), c);
    else if (c == 'x' || c == 'X' || c == 'p')
    {
        if (c == 'p')
        {
            c = 'x';
            rules->length = 0;
            rules->length |= 32;
            rules->flags |= 8;
        }
        ft_print_dDioOuUxX(rules, ft_itoa_base_us(ft_unsignT(rules, ap), 16), c);
    }
}
