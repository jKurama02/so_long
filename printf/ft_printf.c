/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:19:43 by anmedyns          #+#    #+#             */
/*   Updated: 2024/02/06 16:19:43 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	what_print(const char str, va_list args, int i)
{
	if (str == 'd' || str == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (str == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (str == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (str == 'x' || str == 'X')
		i += ft_puthex(va_arg(args, unsigned int), str);
	else if (str == 'p')
		i += ft_putptr (va_arg(args, void *));
	else if (str == 'u')
		i += ft_putnum_un(va_arg(args, unsigned int));
	else if (str == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		a;
	va_list	args;

	i = 0;
	a = 0;
	va_start(args, str);
	while (str[a])
	{
		if (str [a] == '%')
		{
			a++;
			i = what_print(str[a], args, i);
		}
		else
			i += ft_putchar(str[a]);
		a++;
	}
	va_end(args);
	return (i);
}
