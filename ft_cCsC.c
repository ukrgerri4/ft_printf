#include "ft_printf.h"

static void ft_print_s(t_plist *rules, char *s)
{
    int len;

    len = ft_strlen(s);
    if (rules->precision && rules->precision < len)
        if (rules->width > rules->precision)
        {
            len = rules->width - rules->precision;
            while (len--)
                ft_putchar_count(' ');
            while (rules->precision--)
                ft_putchar_count(*(s++));
        }
        else
            while (rules->precision--)
                ft_putchar_count(*(s++));
    else
    {
        if (rules->width && rules->width > len)
        {
            len = rules->width - len;
            while (len--)
                ft_putchar_count(' ');
        }
        ft_putstr_count(s);
    }
}

void        ft_use_rules_cCsS(t_plist *rules, char c, va_list ap)
{
    if ((c == 'c' && (rules->length &= 4)) || c == 'C')
        ft_putchar_count(va_arg(ap, wint_t));
    if ((c == 's' && (rules->length &= 4)) || c == 'S')
        ft_putstr_count(va_arg(ap, wchar_t*));
    if (c == 'c')
        ft_putchar_count(va_arg(ap, int));
    if (c == 's')
        ft_print_s(rules, va_arg(ap, char*));
}
