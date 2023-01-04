/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:34:30 by nvan-den          #+#    #+#             */
/*   Updated: 2023/01/04 09:54:44 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sort(const char *str, va_list ap)
{
	char	*s;
	int		count;

	count = 0;
	if (*str == 's')
	{
		s = va_arg(ap, char *);
		if (s == NULL)
			count = write(1, "(null)", 6);
		else
			ft_putstr_fd(s, 1);
		count += ft_strlen(s);
	}
	else if (*str == 'd' || *str == 'i' || *str == 'u')
	{
		if (*str == 'u')
			s = ft_itoa((unsigned int)va_arg(ap, unsigned int));
		else
			s = ft_itoa(va_arg(ap, int));
		ft_putstr_fd(s, 1);
		count = ft_strlen(s);
		free(s);
	}
	return (count);
}

int	ft_strrev(char *src)
{
	int		i;
	int		len;
	char	str[17];

	i = 0;
	len = strlen(src);
	while (len > 0)
	{
		str[--len] = src[i];
		i++;
	}
	str[i] = '\0';
	ft_putstr_fd(str, 1);
	return (i);
}

int	ft_hex(unsigned long long deci, char flag)
{
	char			hexa[17];
	int				i;
	int				len;
	unsigned int	digit;

	i = 0;
	if (flag == 'p')
		ft_putstr_fd("0x", 1);
	while (deci > 0)
	{
		digit = deci % 16;
		if (digit < 10)
			hexa[i++] = '0' + digit;
		else if (flag == 'X')
			hexa[i++] = 'A' + (digit - 10);
		else
			hexa[i++] = 'a' + (digit - 10);
		deci /= 16;
	}
	if (i == 0)
		hexa[i++] = '0';
	hexa[i] = '\0';
	len = ft_strrev(hexa);
	if (flag == 'p')
		len += 2;
	return (len);
}

// take the argument from '%'
int	params(const char *str, va_list ap)
{
	int	count;

	count = 0;
	if (*str == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	if (*str == 'c')
		count = 1;
	if (*str == 's')
		count = sort(str, ap);
	if (*str == 'd' || *str == 'i' || *str == 'u')
		count = sort(str, ap);
	if (*str == 'x' || *str == 'X')
		count = ft_hex(va_arg(ap, unsigned int), *str);
	if (*str == 'p')
		count = ft_hex(va_arg(ap, unsigned long long), *str);
	if (*str == '%')
		count = write(1, "%", 1);
	return (count);
}

// loop through the string until '%'
int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		ap;
	static int	value;

	i = 0;
	value = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
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
	return (value);
}
