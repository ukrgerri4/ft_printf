/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libfun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:35:38 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/02/04 19:35:56 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int	nb;
	int	sign;

	sign = 1;
	nb = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\v' ||
				*str == '\f' || *str == '\r' || *str == '\n'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
		nb = nb * 10 + (*(str++) - '0');
	return (nb * sign);
}

void	ft_bzero(void *str, size_t n)
{
	int				i;
	unsigned char	*tmp;

	tmp = str;
	i = 0;
	while (n-- > 0)
		tmp[i++] = 0;
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strdel(char **as)
{
	if (!as)
		return ;
	free((char*)*as);
	*as = NULL;
}
