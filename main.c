/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:31 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/17 17:26:44 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	main(void)
{
//	printf("pf %010d\n", 123);
//	ft_printf("ft %010d\n", 123);

	ft_putstr(itoa_base(9223372036854775807, 16));
	ft_putchar('\n');

	printf("%x\n", 233);
	printf("%lx\n", 2147483647);

	printf("%llo", 18446744073709551615);
	ft_printf("%llo", 18446744073709551615);

	return(0);
}