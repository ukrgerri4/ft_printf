#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS format[*i] == '+' \
|| format[*i] == '-'\
|| format[*i] == ' '\
|| format[*i] == '0'\
|| format[*i] == '#'

# define LENGTH format[*i] == 'h'\
|| format[*i] == 'l'\
|| format[*i] == 'j'\
|| format[*i] == 'z'\
|| format[*i] == 't'

# define UNSIGNED_SPE c == 'o'\
|| c == 'O'\
|| c == 'u'\
|| c == 'U'\
|| c == 'x'\
|| c == 'X'

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include <stddef.h>
# include <inttypes.h>

int     g_count;

typedef struct	s_plist
{
	int     flags;
	int     width;
	int     precision;
    int     length;
}				t_plist;

int     ft_printf(const char *format, ...);
int     ft_checkparam(const char *format, va_list ap, int *i);

/*
 * use saved parameters and write specifier
 */

void    ft_use_rules(t_plist *rules, char c, va_list ap);
void    ft_use_rules_cCsS(t_plist *rules, char c, va_list ap);
void	ft_use_rules_dDioOuUxX(t_plist *rules, char c, va_list ap);

/*
 * write function
 */

void    ft_putchar_count(char c);
void    ft_putstr_count(char *s);
char    *ft_itoa_base_s(ssize_t value, int base);
char	*ft_itoa_base_us(size_t value, int base);

#endif
