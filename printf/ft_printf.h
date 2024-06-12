/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:48:48 by anmedyns          #+#    #+#             */
/*   Updated: 2024/02/09 19:48:48 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_check(const char str, va_list args, int i);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnum_un(unsigned int n);
int	ft_putnbr(int n);
int	ft_puthex(unsigned int n, const char format);
int	ft_putptr(void *p);
int	ft_count_num(int n);
int	ft_count_len_pnt(unsigned long int n);
int	putt(unsigned long n, const char format);

#endif
