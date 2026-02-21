/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:00:19 by yuak              #+#    #+#             */
/*   Updated: 2025/12/11 20:00:24 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	does_exceed_boundary(char *s);
static int	is_there_digit(char *s);
static int	is_there_invalid_char(char *s);

int	is_double(char *s)
{
	char	*formatted;

	formatted = remove_space(s);
	if (formatted == NULL || formatted[0] == '\0')
		return (free(formatted), 0);
	if (!is_there_digit(formatted))
		return (free(formatted), 0);
	if (is_there_invalid_char(formatted))
		return (free(formatted), 0);
	if (does_exceed_boundary(formatted))
		return (free(formatted), 0);
	free(formatted);
	return (1);
}

static int	is_there_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	is_there_invalid_char(char *s)
{
	int	i;
	int	has_dot;

	i = 0;
	has_dot = 0;
	while (s[i])
	{	
		if (s[i] != '+' && s[i] != '-' && !ft_isdigit(s[i]) && s[i] != '.')
			return (1);
		if ((s[i] == '-' || s[i] == '+') && i != 0)
			return (1);
		if (s[i] == '.')
		{
			if (has_dot)
				return (1);
			has_dot = 1;
		}
		i++;
	}
	return (0);
}

static int	does_exceed_boundary(char *s)
{
	double	value;

	value = str_to_double(s);
	if (value == HUGE_VAL || value == -HUGE_VAL)
	{
		ft_putstr_fd("Overflow Error!\n", 2);
		return (1);
	}
	if (value == 0.0 && !is_exactly_zero(s))
	{
		ft_putstr_fd("Underflow Error!\n", 2);
		return (1);
	}
	return (0);
}
