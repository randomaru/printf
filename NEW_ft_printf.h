/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:54 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/12 17:43:11 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/// Sveta
# define ULL unsigned long long
# define LD long double
# define UI unsigned int

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>
# include <math.h>

typedef struct			s_float
{
	unsigned long long	first;
	unsigned long long	second;
	char				*scnd;
	char				*frst;
	unsigned long long  i;
    unsigned long long  pos;
    char                *tmp;
    char                *res;
    int                 not_f;
}						t_float;

union					number
{
	int					i; ///
	long int			li; ////
	long long int		lli; ///
	unsigned int		ui; ///
	unsigned long int	uli; ///
	unsigned long long	ulli; ///
	short int			hi; ///
	unsigned short int	uhi; ///
	signed char			sc; ///
	unsigned char		uc; ////
	double				d;
	long double			ld;
	char 				c;
	char 				*str;
	void				*p;
};

typedef struct		s_pf
{
	char					*flags;
	int 					width;
	int 					precision;
	int						prec_width;
	char					*size;
	char 					type;
	int 					str_len;
	char 					*str;
	int 					percent;
	int 					counter;

	int						symbol; /// 1='0', 2=' ' totheleft; 3=' ' totheright
	int 					symb_width;
	int 					sign; /// 0='-', 1='+'
	char 					*sharp;

	char 					*tmp_oxfs;
	int						num_len;
	union number			num;

	int 					dot;
	int						plus;
	int 					minus;
	int						space;
	int						float_dot;
}							t_pf;


int					ft_printf(char *format, ...);
int 				new_str(t_pf *pf, char **p);
int					pf_format(t_pf *pf, char **p, va_list ap);

int 				is_flags(char *p);
void				find_flags(t_pf *pf, char **p);
int 				is_width(char *p);
void				find_width(t_pf *pf, char **p);
int					is_precision(char **p, t_pf *pf);
void				find_precision(t_pf *pf, char **p);
int 				is_size(char *p);
void				find_size(t_pf *pf, char **p);


int					parse_format(t_pf *pf);
int					find_str_size(t_pf *pf);
int					fill_final_str(t_pf *pf);


///SVETA

int    				display_f(t_pf *pf);
char				*pf_itoa(unsigned long long n);
unsigned long long	ft_len_of_number(unsigned long long n);
char				*pf_strcpy(char *dst, const char *src, int j);
long double ft_pow_double(long double n, unsigned long long pow);
int   handle_inf_nan(LD num, t_pf *pf, t_float *fl);
void    real_okrugl(t_float *fl, t_pf *pf, LD num);
void	free_t_float(t_float *fl);
int    work_with_parts(t_float *fl, LD num, t_pf *pf);
void    put_if_precision_null(t_float *fl, t_pf *pf, LD num);
void    put_if_precision_not_null(t_float *fl, t_pf *pf, LD num);
char *make_decimal(t_float *fl, t_pf *pf);

#endif