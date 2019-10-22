/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:53:59 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/22 19:34:34 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_format(t_pf *pf, char *p)
{
	if (is_flags(p))
		find_flags(pf, &p);
	if (is_width(p))
		find_width(pf, &p);
	if (is_precision(p))
		find_precision(pf, &p);
	if (is_size(p))
		find_size(pf, &p);
	///теперь нужно определить тип переменной из union
}