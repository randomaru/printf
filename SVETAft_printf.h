/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:54 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/06 17:59:06 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>

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

	char 					*tmp_ox;
	int						num_len;
	union number			num;
}							t_pf;

/// svetik
typedef struct  s_float
{
    unsigned long long      first;
    unsigned long long      second;
    char                    *scnd;
    char                    *frst;
    int                     znak;
}               t_float;

/*typedef struct  s_float
{
    int                     point;
    char                    *res;
    int                     znak;
    unsigned long int       len;
}               t_float;*/


int					ft_printf(char *format, ...);
int 				new_str(t_pf *pf, char **p);
int					pf_format(t_pf *pf, char **p, va_list ap);

int 				is_flags(char *p);
void				find_flags(t_pf *pf, char **p);
int 				is_width(char *p);
void				find_width(t_pf *pf, char **p);
int					is_precision(char *p);
void				find_precision(t_pf *pf, char **p);
int 				is_size(char *p);
void				find_size(t_pf *pf, char **p);


int					save_format(t_pf *pf);
int					str_size(t_pf *pf);
int					new_num_str(t_pf *pf);


///SVETA

int    				display_f(t_pf *pf);
char				*pf_itoa(unsigned long long n);
unsigned long long	ft_len_of_number(unsigned long long n);
t_float	*new_t_float(void);
char     *okrugl(long double num, unsigned long long i, t_float *floatty, int prec);
char	*pf_strcpy(char *dst, const char *src, int j);

#endif