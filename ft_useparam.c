#include "ft_printf.h"
/*
void    ft_use_rules_dDi(t_plist *rules, char c, va_list ap)

void    ft_use_rules_oOuUxX(t_plist *rules, char c, va_list ap)

void    ft_use_rules_p(t_plist *rules, char c, va_list ap)
*/





void    ft_use_rules(t_plist *rules, char c, va_list ap)
{
    if (c == 'c' || c == 'C' || c == 's' || c == 'S')
        ft_use_rules_cCsS(rules, c, ap);
    else if (c == 'd' || c == 'D' || c == 'i' || c == 'o'
        || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
        ft_use_rules_dDioOuUxX(rules, c, ap);
/*    else if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
        ft_use_rules_oOuUxX();
    else if (c == 'p')
        ft_use_rules_p();*/
}
