/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:31 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/22 17:42:23 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	main(void)
{
//	printf("pf %010d\n", 123);
//	ft_printf("ft %010d\n", 123);

//	ft_putstr(itoa_base(9223372036854775807, 16));
//	ft_putchar('\n');
//
//	printf("%x\n", 233);
//	printf("%lx\n", 2147483647);
	int i = printf("ls %%\nldfl%% %% %% ");
	int j = ft_printf("ls %%\nldfl%% %% %% ");

	return(0);
}