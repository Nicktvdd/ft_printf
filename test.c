/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:35:59 by nvan-den          #+#    #+#             */
/*   Updated: 2022/12/21 13:30:19 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limist.h>

int	main(void)
{
	int value;

	value = 0;

	value = ft_printf("c is :%c:\n", '0');
	printf("value is %i\n", value);
	value = printf("c is :%c:\n", '0');
	printf("value is %i\n\n", value);

	value = ft_printf("i is :%i:\n", 1);
	printf("value is %i\n", value);
	value = printf("i is :%i:\n", 1);
	printf("value is %i\n\n", value);
	
	value = ft_printf("d is :%i:\n", 1);
	printf("value is %i\n", value);
	value = printf("d is :%i:\n", 1);
	printf("value is %i\n\n", value);

	value = ft_printf("%% is :%%:\n");
	printf("value is %i\n", value);
	value = printf("%% is :%%:\n");
	printf("value is %i\n\n", value);
	
	value = ft_printf("u is :%u:\n", -1);
	printf("value is %i\n", value);
	value = printf("u is :%u:\n", -1);
	printf("value is %i\n\n", value);

	value = ft_printf("str is :%s:\n", "stringboi");
	printf("value is %i\n", value);
	value = printf("str is :%s:\n", "stringboi");
	printf("value is %i\n\n", value);

	value = ft_printf("x is :%x:\n", 10);
	printf("value is %i\n", value);
	value = printf("x is :%x:\n", 10);
	printf("value is %i\n\n", value);

	value = ft_printf("X is :%X:\n", 10);
	printf("value is %i\n", value);
	value = printf("X is :%X:\n", 10);
	printf("value is %i\n\n", value);

	value = ft_printf("p is :%p:\n", __LONG_MAX__);
	printf("value is %i\n", value);
	value = printf("p is :%p:\n", __LONG_MAX__);
	printf("value is %i\n\n", value);
	//ft_printf("string :%c: :%s: :%p: :%d: :%i: mid-string :%u: :%x: :%x: :%X: :%%: end-string\n");
	//printf("string :%c: :%s: :%p: :%d: :%i: mid-string :%u: :%x: :%x: :%X: :%%: end-string\n");

	return (0);
}