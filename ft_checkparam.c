#include "ft_printf.h"

static void	ft_use_rules(t_plist *rules, char c, va_list ap)
{
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == '%')
		ft_use_rules_cCsS(rules, c, ap);
	else if (c == 'd' || c == 'D' || c == 'i' || c == 'o'
		|| c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'p')
		ft_use_rules_dDioOuUxX(rules, c, ap);
/*    else if (c == 'p')
		ft_use_rules_p(rules, ap);*/
}

int		ft_checkparam(t_plist *rules, const char *format, va_list ap, int *i)
{
	ft_create_plist(&rules);
	(*i)++;
	while (!ft_end_char(format[*i]) && format[*i]) // or change ++(*i) in while
	{
		if ((format[*i] >= '1' && format[*i] <= '9') || format[*i] == '.')
			ft_write_pad(rules, format, i);
		else if (FLAGS)
			ft_write_flags(rules, format[(*i)++]);
		else if (LENGTH)
			ft_write_length(rules, &format[(*i)++], i);
		else
		{
			while ( --rules->width > 0)
				(rules->flags & 16) ? ft_putchar_count('0') : ft_putchar_count(' ');
			return (1);
		}
	}
	if (!format[*i]) // нужно уточнить этот кейс
		return (0);
	ft_use_rules(rules, format[*i], ap);
	(*i)++; // <-- нада куда-то это дело перенести помоднее
	return (1);
}