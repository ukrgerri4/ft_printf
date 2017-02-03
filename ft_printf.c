#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
	va_list ap;
	static t_plist *rules;
	int     i;
 
	i = 0;
	g_count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			if (!ft_checkparam(rules, format, ap, &i))
				return (g_count);
		if (format[i] && format[i] != '%')
			ft_putchar_count(format[i++]);
	}
	va_end(ap);
	ft_create_plist(&rules);
	return (g_count);
}