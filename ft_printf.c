/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:34:30 by nvan-den          #+#    #+#             */
/*   Updated: 2022/12/19 16:03:14 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_counter(long n)
{
	int	len;

	len = 0;
	while (n / 10)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

int	ft_hex(int deci, char flag)
{
	int remainder;
	int i;
	int len;
	char *hexa;

	i = 0;
	len = ft_counter(deci);
	if (flag == 'p')
		ft_putstr_fd("0x", 1);
	(hexa = malloc(sizeof(char) * (len + 1)));
	if (!hexa)
		return (0);
	while (deci != 0)
	{
		remainder = deci % 16;
		if (remainder < 10)
			hexa[i++] = 48 + remainder;
		else if (flag == 'X')
			hexa[i++] = 55 + remainder;
		else
			hexa[i++] = 87 + remainder;
		deci = deci / 16;
	}
	ft_putstr_fd(hexa, 1);
	if (flag == 'p')
		len += 2;
return (len);
}

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
		ft_putstr_fd(va_arg(ap, char*), 1);// Prints a string (as defined by the common C convention).
		count = ft_strlen(str);
	}
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
	if (*str == 'x' || *str == 'X' || *str == 'p')
		count = ft_hex(va_arg(ap, int), *str);// Prints a number in hexadecimal (base 16) format.
	if (*str == '%')
		count = write(1, "%", 1);// Prints a percent sign.
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
			value = value + params(&str[i], ap);
			i++;
		}
		ft_putchar_fd(str[i], 1);
		value++;
	}

	va_end(ap);

	return(value);
}