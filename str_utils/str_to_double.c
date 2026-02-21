/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:00:10 by yuak              #+#    #+#             */
/*   Updated: 2025/12/11 20:00:14 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static double	get_frac_part(char *s);
static int		get_sign(char **s);
static double	get_overflow_value(int sign);

double	str_to_double(char *s)
{
	double	integer_part;
	int		sign;

	integer_part = 0.0;
	while (*s == ' ' || *s == '\t')
		s++;
	sign = get_sign(&s);
	while (*s != '.' && *s != '\0')
	{
		if (integer_part > DBL_MAX / 10)
			return (get_overflow_value(sign));
		integer_part = integer_part * 10;
		if (integer_part > DBL_MAX - (*s - '0'))
			return (get_overflow_value(sign));
		integer_part += *s - '0';
		s++;
	}
	if ('.' == *s)
		s++;
	return ((integer_part + get_frac_part(s)) * sign);
}

static double	get_frac_part(char *s)
{
	double	fractional_part;
	double	pow;

	fractional_part = 0;
	pow = 1;
	while (*s)
	{
		pow /= 10;
		if (pow == 0.0)
			break ;
		fractional_part = fractional_part + (*s++ - '0') * pow;
	}
	return (fractional_part);
}

static int	get_sign(char **s)
{
	int	sign;

	sign = 1;
	if (**s == '+' || **s == '-')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	return (sign);
}

static double	get_overflow_value(int sign)
{
	if (sign == 1)
		return (HUGE_VAL);
	else
		return (-HUGE_VAL);
}
