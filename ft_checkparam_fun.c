#include "ft_printf.h"

int      ft_end_char(char c)
{
	static char    mass[16] = "cCsSdDioOuUxXp%";
	int     i;

	i = 0;
	while (c != mass[i] && mass[i])
		i++;
	if (mass[i])
		return (1);
	return (0);
}

void     ft_write_pad(t_plist *rules, const char *format, int *i)
{
	int res;

	if (format[*i] >= '1' && format[*i] <= '9')
	{
		if ((res = ft_atoi(&format[*i])) > rules->width) // mb it's not accord with norm
			rules->width = res;
		while (format[*i] >= '0' && format[*i] <= '9')
			(*i)++;
	}
	else
	{
		(*i)++;
		if (format[*i] >= '1' && format[*i] <= '9')
		{
			if ((res = ft_atoi(&format[*i])) > rules->precision) // mb it's not accord with norm
			{
				rules->precision = res; 
				while (format[*i] >= '0' && format[*i] <= '9')
					(*i)++;
			}
		}
		else
			rules->precision = 0;
	}
}

void     ft_write_flags(t_plist *rules, char c)
{
	if (c == '+')
		rules->flags |= 1;
	else if (c == '-')
		rules->flags |= 2;
	else if (c == ' ')
		rules->flags |= 4;
	else if (c == '#')
		rules->flags |= 8;
	else if (c == '0')
		rules->flags |= 16;
}

void     ft_create_plist(t_plist **rules)
{
	if (!*rules)
		*rules = (t_plist*)malloc(sizeof(t_plist));
	(*rules)->flags = 0;
	(*rules)->width = 0;
	(*rules)->precision = -1;
	(*rules)->length = 0;
	(*rules)->len = 0;
	ft_bzero((*rules)->prefix, 3);
	(*rules)->prep = ' ';
}

void     ft_write_length(t_plist *rules, const char *c, int *i)
{
	if (*c == 'h')
		if (*(c + 1) == 'h')
		{
			rules->length |= 1;
			(*i)++;
		}
		else
			rules->length |= 2;
	else if (*c == 'l')
		if (*(c + 1) == 'l')
		{
			rules->length |= 8;
			(*i)++;
		}
		else
			rules->length |= 4;
	else if (*c == 'j')
		rules->length |= 16;
	else if (*c == 'z')
		rules->length |= 32;
}