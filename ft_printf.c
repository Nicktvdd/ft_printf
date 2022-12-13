/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:34:30 by nvan-den          #+#    #+#             */
/*   Updated: 2022/12/13 10:22:55 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// take the argument from '%'
int	params(const char *str, va_list ap) 
{
	int count;
	count = 0;
	if (*str == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1);//Prints a single character.
		count = 1;
	}	
	if (*str == 's')
	{
		char *str = va_arg(ap, char*);
		ft_putstr_fd(str, 1);// Prints a string (as defined by the common C convention).
		ft_strlen(str);
	}
	/*if (ap == 'p')
		ft_void(str);// The void * pointer argument has to be printed in hexadecimal format. */
	if (*str == 'd' || *str == 'i')
	{
		char *n = ft_itoa(va_arg(ap, int));// Prints a decimal (base 10) number.
		ft_putstr_fd(n, 1);
		count = ft_strlen(n);
	}
	if (*str == 'u')
	{
		long n = (unsigned int)va_arg(ap, unsigned int);
		char *d = ft_itoa(n);// Prints an unsigned decimal (base 10) number.
		ft_putstr_fd(d, 1);
		count = ft_strlen(d);
	}
/* 	if (ap == 'x')
		ft_lowhex(str);// Prints a number in hexadecimal (base 16) lowercase format.
	if (ap == 'X')
		ft_uphex(str);// Prints a number in hexadecimal (base 16) uppercase format. */
	if (*str == '%')
	{
		write(1, "%", 1);// Prints a percent sign.
		count = 1;
	}
	return (count);
}

// loop through the string until '%'
int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		ap;
	static int	value;

	i = -1;
	value = 0; // should become same return value as printf
	va_start(ap, str);

	while (str[++i]) // until the string ends
	{
		if (str[i] == '%') // if % is found, check which parameter
		{
			i++;
			params(&str[i], ap);
			//value = value + params(*ap, int);
			i++;
		}
		ft_putchar_fd(str[i], 1);
		value++;
	}

	va_end(ap);

	return(value);
}