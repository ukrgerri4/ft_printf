#include "ft_printf.h"

static void ft_print_s(t_plist *rules, char *s)
{
    if (!s)
        s = "(null)";
    rules->len = ft_strlen(s);
    if (rules->flags & 2)
    {
        if (rules->precision != -1 && rules->precision < rules->len)
            if (rules->width > rules->precision)
            {
                rules->len = rules->width - rules->precision;
                while (rules->precision-- > 0)
                    ft_putchar_count(*(s++));
                while ((rules->len)--)
                    ((rules->flags & 16) && !(rules->flags & 2)) ? ft_putchar_count('0') : ft_putchar_count(' ');
            }
            else
                while (rules->precision-- > 0)
                    ft_putchar_count(*(s++));
        else
        {
            ft_putstr_count(s);
            if (rules->width && rules->width > rules->len)
            {
                rules->len = rules->width - rules->len;
                while ((rules->len)--)
                    ((rules->flags & 16) && !(rules->flags & 2)) ? ft_putchar_count('0') : ft_putchar_count(' ');
            }
        }
    }
    else
    {
        if (rules->precision != -1 && rules->precision < rules->len)
            if (rules->width > rules->precision)
            {
                rules->len = rules->width - rules->precision;
                while ((rules->len)--)
                    ((rules->flags & 16) && !(rules->flags & 2)) ? ft_putchar_count('0') : ft_putchar_count(' ');
                while (rules->precision-- > 0)
                    ft_putchar_count(*(s++));
            }
            else
                while (rules->precision-- > 0)
                    ft_putchar_count(*(s++));
        else
        {
            if (rules->width && rules->width > rules->len)
            {
                rules->len = rules->width - rules->len;
                while ((rules->len)--)
                    ((rules->flags & 16) && !(rules->flags & 2)) ? ft_putchar_count('0') : ft_putchar_count(' ');
            }
            ft_putstr_count(s);
        }
    }
}

static void ft_print_c(t_plist *rules, char c)
{
    rules->len = 1;
    if (rules->flags & 2)
    {
        ft_putchar_count(c);
        if (rules->width && rules->width > rules->len)
        {
            rules->len = rules->width - rules->len;
            while ((rules->len)--)
                ((rules->flags & 16) && !(rules->flags & 2)) ? ft_putchar_count('0') : ft_putchar_count(' ');
        }
    }
    else
    {
        if (rules->width && rules->width > rules->len)
        {
            rules->len = rules->width - rules->len;
            while ((rules->len)--)
                ((rules->flags & 16) && !(rules->flags & 2)) ? ft_putchar_count('0') : ft_putchar_count(' ');
        }
        ft_putchar_count(c);
    }
}

void        ft_use_rules_cCsS(t_plist *rules, char c, va_list ap)
{
    if (c == '%')
        ft_print_c(rules, '%');
    if ((c == 'c' && (rules->length &= 4)) || c == 'C')
        ft_putchar_count(va_arg(ap, int));
    if ((c == 's' && (rules->length &= 4)) || c == 'S')
        ft_putstr_count(va_arg(ap, char*));
    if (c == 'c')
        ft_print_c(rules, va_arg(ap, int));
    if (c == 's')
        ft_print_s(rules, va_arg(ap, char*));
}