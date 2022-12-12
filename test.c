/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:35:59 by nvan-den          #+#    #+#             */
/*   Updated: 2022/12/12 13:54:33 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int value;

	value = 0;

	ft_printf("c is :%c:\n", 42);
	printf("c is :%c:\n", 42);

	ft_printf("i is :%i:\n", 1);
	printf("i is :%i:\n", 1);
	
	ft_printf("d is :%i:\n", 1);
	printf("d is :%i:\n", 1);

	ft_printf("%% is :%%:\n");
	printf("%% is :%%:\n");
	
	int i = -1;
	while (i != -11)
	{
		printf("u is %u\n", i);
		i--;
	}
	unsigned int my = (4294967296 - 1);
	printf("my is :%u:\n", my);
	//ft_printf("string :%c: :%s: :%p: :%d: :%i: mid-string :%u: :%x: :%x: :%X: :%%: end-string\n");
	//printf("string :%c: :%s: :%p: :%d: :%i: mid-string :%u: :%x: :%x: :%X: :%%: end-string\n");

	return (0);
}