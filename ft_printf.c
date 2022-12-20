/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:34:30 by nvan-den          #+#    #+#             */
/*   Updated: 2022/12/20 14:29:13 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/* static int	ft_counter(long n)
{
	int	len;

	len = 0;
	while (n / 10)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len - 2);
} */

/* int	ft_hex(unsigned int deci, char flag)
{
	int remainder;
	int i;
	int len;
	char *hexa;

	i = 0;
	len = ft_counter(deci);
	if (flag == 'p')
		ft_putstr_fd("0x", 1);
	hexa = malloc(sizeof(char) * (len + 1));
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
	free(hexa);
return (len + 1);
} */

int ft_hex(unsigned int x, char flag) {
  char buffer[17];
  int i = 0;
  if (flag)
	flag = flag + 0;
  while (x > 0) {
    unsigned int digit = x % 16;
    if (digit < 10) {
      buffer[i] = '0' + digit;
    } else {
      buffer[i] = 'a' + (digit - 10);
    }
    x /= 16;
    i++;
  }
  if (i == 0) {
    buffer[i++] = '0';
  }
  buffer[i] = '\0';
  ft_putstr_fd(buffer, 1);
  return (ft_strlen(buffer));
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
		char *s = va_arg(ap, char*);
		if (s == NULL)
		{
			ft_putstr_fd("(null)", 1);
			count = 6;
		}
		else
			ft_putstr_fd(s, 1);// Prints a string (as defined by the common C convention).
		count += ft_strlen(s);
	}
	if (*str == 'd' || *str == 'i')
	{
		char *n = ft_itoa(va_arg(ap, int));// Prints a decimal (base 10) number.
		ft_putstr_fd(n, 1);
		count = ft_strlen(n);
		free(n);
	}
	if (*str == 'u')
	{
		long n = (unsigned int)va_arg(ap, unsigned int);
		char *d = ft_itoa(n);// Prints an unsigned decimal (base 10) number.
		ft_putstr_fd(d, 1);
		count = ft_strlen(d);
		free(d);
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

	i = 0;
	value = 0; // should become same return value as printf
	va_start(ap, str);

	while (str[i] != '\0') // until the string ends
	{
		if (str[i] == '%') // if % is found, check which parameter
		{
			i++;
			value = value + params(&str[i], ap);
			i++;
		}
		else
		{
			value++;
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}

	va_end(ap);

	return(value);
}