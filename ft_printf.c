/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:34:30 by nvan-den          #+#    #+#             */
/*   Updated: 2022/12/12 15:03:47 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/* void	*cast(const char *str, va_list ap)
{
	if (*str == 'c' || *str == 'd' || *str == 'i')
	{
		int c;
		c = va_arg(ap, int);
	}
	if (ap == 's')
		ft_putstr(str);
	if (ap == 'p')
		ft_void(str);
	if (*str == 'u')
	{
		unsigned int c;
		c = va_arg(ap, unsigned int);
	}
	if (ap == 'x')
		ft_lowhex(str);
	if (ap == 'X')
		ft_uphex(str);
} */

// take the argument from '%'
int	params(const char *str, va_list ap) 
{
	int count;
	count = 0;
	char *type;
	//cast(str, ap);
	//c = va_arg(ap, type);
	if (*str == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);//Prints a single character.
/* 	if (ap == 's')
		ft_putstr(str);// Prints a string (as defined by the common C convention).
	if (ap == 'p')
		ft_void(str);// The void * pointer argument has to be printed in hexadecimal format. */
	if (*str == 'd' || *str == 'i')
	{
		char *n = ft_itoa(va_arg(ap, int));// Prints a decimal (base 10) number.
		ft_putstr_fd(n, 1);
	}
	if (*str == 'u')
	{
		long n = (unsigned int)va_arg(ap, unsigned int);
		char *d = ft_itoa(n);// Prints an unsigned decimal (base 10) number.
		ft_putstr_fd(d, 1);
	}
/* 	if (ap == 'x')
		ft_lowhex(str);// Prints a number in hexadecimal (base 16) lowercase format.
	if (ap == 'X')
		ft_uphex(str);// Prints a number in hexadecimal (base 16) uppercase format. */
	if (*str == '%')
		write(1, "%", 1);// Prints a percent sign.
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