/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:34:30 by nvan-den          #+#    #+#             */
/*   Updated: 2022/12/12 11:17:43 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		if (n <= -2147483648)
		{
			ft_putchar('2');
			n = n % -1000000000;
		}
			n = n * -1;
	}
	if (n / 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
	return (0);
}

// take the argument from '%'
int	params(char *str, va_list ap) 
{
	if (str == 'c')
		ft_putchar(str);//Prints a single character.
/* 	if (ap == 's')
		ft_putstr(str);// Prints a string (as defined by the common C convention).
	if (ap == 'p')
		ft_void(str);// The void * pointer argument has to be printed in hexadecimal format. */
	if (str == 'd' || ap == 'i')
		ft_putnbr(str);// Prints a decimal (base 10) number.
	if (str == 'u')
		ft_putnbr(str);// Prints an unsigned decimal (base 10) number.
/* 	if (ap == 'x')
		ft_lowhex(str);// Prints a number in hexadecimal (base 16) lowercase format.
	if (ap == 'X')
		ft_uphex(str);// Prints a number in hexadecimal (base 16) uppercase format. */
	if (str == '%')
		write(1, '%', 1);// Prints a percent sign.
	return (0);
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
		ft_putchar(str[i]);
		value++;
	}

	va_end(ap);

	return(value);
}