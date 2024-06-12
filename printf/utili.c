/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utili.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:48:48 by anmedyns          #+#    #+#             */
/*   Updated: 2024/02/09 14:48:48 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnum_un(unsigned int n)
{
	int	c;

	c = 0;
	if (n < 10)
		c += ft_putchar(n + 48);
	else
	{
		c += ft_putnum_un(n / 10);
		c += ft_putnum_un(n % 10);
	}
	return (c);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
		count = 2;
	}
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		count += ft_putnum_un(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		count += ft_putchar(nb + 48);
	return (count);
}

int	ft_puthex(unsigned int n, const char format)
{
	char	*base;
	int		contatore;

	contatore = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		contatore += ft_puthex(n / 16, format);
	contatore += ft_putchar(base[(n % 16)]);
	return (contatore);
}

int	putt(unsigned long n, const char format)
{
	char	*base;
	int		contatore;

	contatore = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		contatore += putt(n / 16, format);
	contatore += ft_putchar(base[(n % 16)]);
	return (contatore);
}
