#include "ft_printf.h"

static void ft_print_dDi(t_plist *rules, char *s)
{
    ft_putstr_count(s);
}

void    ft_use_rules_dDi(t_plist *rules, char c, va_list ap)
{
//	if (rules->length &= 32)
//		ft_print_dDi(rules, ft_itoa_base_us(va_arg(ap, size_t), 10));
//	else
	ft_print_dDi(rules, ft_itoa_base_s(va_arg(ap, int), 10));

}
