/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_str_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:18:20 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/05 20:31:55 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		new_num_str(t_pf *pf)
{
	char c;
	char *tmp = NULL; ////отредачить str_join
	int i;
	int k;

	k = 0;
	i = 0;
	c = 't';
	if (!(pf->str = ft_memalloc(pf->str_len + 1)))
		return (0);
	if (pf->symbol == 1)
		c = '0';
	if (pf->symbol == 2 || pf->symbol == 3)
		c = ' ';
	if (pf->symbol == 2)
	{
		while (i < pf->symb_width)
		{
			pf->str[i] = c;
			i++;
		}
	}
	if (pf->plus && ft_strchr("dif", pf->type) && !pf->minus)
	{
		pf->str[i] = '+';
		i++;
	}
	if (pf->minus)
	{
		pf->str[i] = '-';
		i++;
	}
	if (pf->space && !pf->minus && !pf->plus)
	{
		pf->str[i] = ' ';
		i++;
	}
	if (ft_strchr("oxX", pf->type) && pf->sharp)
	{
		while (*pf->sharp)
		{
			pf->str[i] = *pf->sharp;
			pf->sharp += 1;
			i++;
		}
	}
	if (pf->symbol == 1)
	{
		pf->symb_width += i;
		while (i < pf->symb_width)
		{
			pf->str[i] = c;
			i++;
		}
	}
	if (ft_strchr("oxX", pf->type)) //////   ютоа_бэйс
		tmp = ft_strdup(pf->tmp_ox);
//	if (pf->type == 'o' && ((pf->precision <= 0 && pf->dot) || pf->sharp) && !ft_strcmp(pf->tmp_ox, "0"))
//	{
//		tmp = NULL;
//	}
//	if (ft_strchr("xX", pf->type) && ((pf->precision <= 0 && pf->dot)) && !ft_strcmp(pf->tmp_ox, "0"))
//	{
//		tmp = NULL;
//	}
	if (ft_strchr("di", pf->type))
		if (!(tmp = ft_lltoa(pf->num.lli)))
			return (-1);
	if ((pf->precision <= 0 && pf->dot) && pf->num.lli == 0)
		tmp = NULL;
	if (pf->type == 'u')
	{
		if (pf->num.ulli == 0 && (pf->precision <= 0 && pf->dot))
			tmp = NULL;
		else
			tmp = ft_ulltoa(pf->num.ulli);
	}
	if (pf->prec_width > 0)
	{
		pf->prec_width += i;
		while (i < pf->prec_width)
		{
			pf->str[i] = '0';
			i++;
		}
	}
	if (tmp)
	{
		while (tmp[k] != '\0')
		{
			pf->str[i] = tmp[k];
			k++;
			i++;
		}
		//free(tmp);
	}

	if (pf->symbol == 3)
	{
		while (i < pf->str_len)
		{
			pf->str[i] = c;
			i++;
		}
	}
	return (pf->str_len);
}

int		str_size(t_pf *pf)
{
	int	sharp_len = 0;
	if (ft_strchr("oxX", pf->type))
	{
		pf->type == 'o' ? (pf->tmp_ox = ulltoa_base(pf->num.ulli, 8)) :
							(pf->tmp_ox = ulltoa_base(pf->num.ulli, 16));
		if (pf->type == 'X')
			pf->tmp_ox = to_uppercase(pf->tmp_ox);
		if (pf->tmp_ox == NULL)
			return (-1);
		if (pf->type == 'o' && ((pf->precision <= 0 && pf->dot) || pf->sharp) && !ft_strcmp(pf->tmp_ox, "0"))
			pf->num_len = 0;
		else if ((pf->type == 'x' || pf->type == 'X') && pf->precision <= 0 && pf->dot)
			pf->num_len = 0;
		else
			{
			pf->num_len = ft_strlen(pf->tmp_ox);
			pf->str_len += pf->num_len;
			}
		if (pf->sharp )
		{
			(pf->type == 'o') ? (pf->str_len += 1) : (pf->str_len += 2);

		}
	}
	if (ft_strchr("di", pf->type))
	{
		if (pf->num.lli == 0 && pf->precision <= 0 && pf->dot)
			pf->num_len = 0;
		else
			pf->num_len = number_len_ll(pf->num.lli);
		pf->str_len += pf->num_len + pf->plus + pf->minus;
		if (!pf->plus && !pf->minus)
			pf->str_len += pf->space;
	}
	if (pf->type == 'u')
	{
		if ( pf->num.ulli == 0 && pf->precision <= 0 && pf->dot)
			pf->num_len = 0;
		else
		{
			pf->num_len = number_len_ull(pf->num.ulli);
			pf->str_len += pf->num_len + pf->minus + pf->plus;
		}
	}
//	if (pf->symbol == 2 && pf->width == 0)
//	{
//		pf->width = pf->str_len + 1;
//
//	}
	if (pf->symbol > 0 || pf->precision > 0)
	{
		if (pf->type == 'o' && pf->sharp)
			sharp_len = 1;
		if ((pf->prec_width = pf->precision - pf->num_len - sharp_len) > 0 &&
								(pf->symb_width = pf->width - pf->str_len - pf->prec_width) > 0)
			pf->str_len += pf->symb_width + pf->prec_width;
		else if ((pf->symb_width = pf->width - pf->str_len) > 0)
			pf->str_len += pf->symb_width;
		else if (pf->prec_width > 0)
			pf->str_len += pf->prec_width;
	}
	return (1);
}

int		save_format(t_pf *pf)
{
	int i = 0;
	if (ft_strchr(pf->flags, '+') && ft_strchr("dif", pf->type) && pf->num.lli >= 0)
		pf->plus = 1;
	if (ft_strchr("dif", pf->type) && pf->num.lli < 0)
	{
		pf->num.lli *= -1;
		pf->minus = 1;
	}
	while (pf->flags[i] != '\0')
	{
		if (((pf->flags[i] == '0' || pf->flags[i] == ' ') &&
					(pf->width > 0 && !(ft_strchr(pf->flags, '-'))))
			|| (pf->width > 0 && !(ft_strchr(pf->flags, '-'))))
		{
			if (pf->flags[i] == '0')
				pf->symbol = 1;
			else
				pf->symbol = 2;
		}
		if (pf->flags[i] == '-' && pf->width > 0)
			pf->symbol = 3;
//		if (pf->flags[i] == ' ' && pf->width == 0 && pf->minus == 0 && pf->plus == 0)
//			pf->symbol = 2;
		if (pf->flags[i] == ' ')
			pf->space = 1;
		if (pf->flags[i] == '#' && ft_strchr("oxX", pf->type))
		{
			if (pf->type == 'o' )//&& pf->num.ulli != 0)
				pf->sharp = ft_strdup("0");
			else if (pf->type == 'x' && pf->num.i != 0)
				pf->sharp = ft_strdup("0x");
			else if (pf->type == 'X' && pf->num.i != 0)
				pf->sharp = ft_strdup("0X");
		}
		i++;
	}
	if (pf->precision > 0 && pf->width > 0)
	{
		if (ft_strchr(pf->flags, '-'))
			pf->symbol = 3;
		else
			pf->symbol = 2;
	}
	if (pf->symbol == -1  && pf->width > 0)
		pf->symbol = 2;
	return (1);
}