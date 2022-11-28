/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:35:59 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/28 13:39:12 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"
#include <stdio.h>

int	main(void)
{
	int value;

	value = 0;

	ft_printf("string :%c: :%s: :%p: :%d: :%i: mid-string :%u: :%x: :%x: :%X: :%%: end-string\n");
	printf("string :%c: :%s: :%p: :%d: :%i: mid-string :%u: :%x: :%x: :%X: :%%: end-string\n");

	return (0);
}