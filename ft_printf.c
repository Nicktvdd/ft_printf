/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:34:30 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/28 13:34:36 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// take the argument from '%'
int	params(char *str, va_list ap) 
{
	if (ap == 'c')
		ft_putchar(str);//Prints a single character.
	if (ap == 's')
		ft_putstr(str);// Prints a string (as defined by the common C convention).
	if (ap == 'p')
		ft_void(str);// The void * pointer argument has to be printed in hexadecimal format.
	if (ap == 'd')
		ft_putnbr(str);// Prints a decimal (base 10) number.
	if (ap == 'i')
		ft_putnbr(str);// Prints an integer in base 10.
	if (ap == 'u')
		ft_putnbr(str);// Prints an unsigned decimal (base 10) number.
	if (ap == 'x')
		ft_lowhex(str);// Prints a number in hexadecimal (base 16) lowercase format.
	if (ap == 'X')
		ft_uphex(str);// Prints a number in hexadecimal (base 16) uppercase format.
	if (ap == '%')
		write(1, '%', 1);// Prints a percent sign.
	return (0);
}

// loop through the string until '%'
int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, str);

	while (str[i - 1] != '%' && str[i])
		ft_putchar(i++)

	va_end(ap);


}