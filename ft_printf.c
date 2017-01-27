#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    va_list ap;
    int     i;
 
    i = 0;
	g_count = 0;
    va_start(ap, format);
    while (format[i])
    {
		if (format[i] == '%')
			if (!ft_checkparam(format, ap, &i))
				return (0);
		if (format[i])
			ft_putchar_count(format[i++]); // возможно нада сначала писать в строку!
	}
	va_end(ap);
    return (g_count);
}
