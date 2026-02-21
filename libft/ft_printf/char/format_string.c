/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:58:08 by yuak              #+#    #+#             */
/*   Updated: 2025/08/12 13:19:18 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	format_string(char *str)
{
	int	n;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	n = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		n++;
	}
	return (n);
}
