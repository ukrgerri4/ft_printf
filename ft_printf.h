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
|| format[*i] == 'z'

# define UNSIGNED_SPE c == 'o'\
|| c == 'O'\
|| c == 'u'\
|| c == 'U'\
|| c == 'x'\
|| c == 'X'

# include <stdio.h> // delete
# include <stdarg.h>
# include <string.h>  //?
# include <stdlib.h>
# include <unistd.h>
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
	char    prefix[3];
	char    prep;
	int     len;

}				t_plist;

int     ft_printf(const char *format, ...);
/*
 * check all parameters 
 */
int 	ft_checkparam(t_plist *rules, const char *format, va_list ap, int *i);
int      ft_end_char(char c);
void     ft_write_pad(t_plist *rules, const char *c, int *i);
void     ft_write_flags(t_plist *rules, char c);
void     ft_create_plist(t_plist **rules);
void     ft_write_length(t_plist *rules, const char *c, int *i);
/*
 * use saved parameters and write specifier
 */
void    ft_use_rules_cCsS(t_plist *rules, char c, va_list ap);

ssize_t	ft_signT(t_plist *rules, va_list ap);
size_t 	ft_unsignT(t_plist *rules, va_list ap);
void	ft_use_rules_dDioOuUxX(t_plist *rules, char c, va_list ap);
/*
 * write function
 */
void    ft_putchar_count(char c);
void    ft_putstr_count(char *s);
char    *ft_itoa_base_s(ssize_t value, int base);
char	*ft_itoa_base_us(size_t value, int base);
char    *ft_tolower_str(char *s);
/*
 * libft function
 */
int     ft_atoi(const char *str);
void    ft_bzero(void *str, size_t n);
size_t	ft_strlen(const char *str);
void    ft_strdel(char **as);
#endif